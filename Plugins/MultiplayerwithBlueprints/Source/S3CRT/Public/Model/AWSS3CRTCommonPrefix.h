/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CommonPrefix.h"

#endif

#include "AWSS3CRTCommonPrefix.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCommonPrefix {
GENERATED_BODY()

    /**
    *  <p>Container for the specified common prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTCommonPrefix &fromAWS(const Aws::S3Crt::Model::CommonPrefix &awsCommonPrefix) {
        this->prefix = UTF8_TO_TCHAR(awsCommonPrefix.GetPrefix().c_str());

        return *this;
    }
#endif
};
