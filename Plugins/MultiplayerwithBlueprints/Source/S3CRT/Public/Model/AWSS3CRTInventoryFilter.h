/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/InventoryFilter.h"

#endif

#include "AWSS3CRTInventoryFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTInventoryFilter {
GENERATED_BODY()

    /**
    *  <p>The prefix that an object must have to be included in the inventory results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::InventoryFilter toAWS() const {
        Aws::S3Crt::Model::InventoryFilter awsInventoryFilter;

        if (!(this->prefix.IsEmpty())) {
            awsInventoryFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        return awsInventoryFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty();
    }

    FAWSS3CRTInventoryFilter &fromAWS(const Aws::S3Crt::Model::InventoryFilter &awsInventoryFilter) {
        this->prefix = UTF8_TO_TCHAR(awsInventoryFilter.GetPrefix().c_str());

        return *this;
    }
#endif
};
