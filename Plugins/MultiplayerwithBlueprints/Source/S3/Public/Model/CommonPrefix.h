/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CommonPrefix.h"

#endif

#include "CommonPrefix.generated.h"

USTRUCT(BlueprintType)
struct FCommonPrefix {
GENERATED_BODY()

    /**
    *  <p>Container for the specified common prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FCommonPrefix &fromAWS(const Aws::S3::Model::CommonPrefix &awsCommonPrefix) {
        this->prefix = UTF8_TO_TCHAR(awsCommonPrefix.GetPrefix().c_str());

        return *this;
    }
#endif
};
