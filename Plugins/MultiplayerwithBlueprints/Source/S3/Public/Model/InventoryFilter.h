/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/InventoryFilter.h"

#endif

#include "InventoryFilter.generated.h"

USTRUCT(BlueprintType)
struct FInventoryFilter {
GENERATED_BODY()

    /**
    *  <p>The prefix that an object must have to be included in the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::InventoryFilter toAWS() const {
        Aws::S3::Model::InventoryFilter awsInventoryFilter;

		if (!(this->prefix.IsEmpty())) {
            awsInventoryFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        return awsInventoryFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty();
    }

    FInventoryFilter &fromAWS(const Aws::S3::Model::InventoryFilter &awsInventoryFilter) {
        this->prefix = UTF8_TO_TCHAR(awsInventoryFilter.GetPrefix().c_str());

        return *this;
    }
#endif
};
