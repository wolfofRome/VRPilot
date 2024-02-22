/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/RequestProgress.h"

#endif

#include "AWSS3CRTRequestProgress.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTRequestProgress {
GENERATED_BODY()

    /**
    *  <p>Specifies whether periodic QueryProgress frames should be sent. Valid values: TRUE, FALSE. Default value: FALSE.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool enabled = false;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::RequestProgress toAWS() const {
        Aws::S3Crt::Model::RequestProgress awsRequestProgress;

        if (!(false)) {
            awsRequestProgress.SetEnabled(this->enabled);
        }

        return awsRequestProgress;
    }

    bool IsEmpty() const {
        return false;
    }
#endif
};
