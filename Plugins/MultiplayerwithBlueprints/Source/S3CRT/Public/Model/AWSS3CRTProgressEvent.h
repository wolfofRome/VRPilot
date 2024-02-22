/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ProgressEvent.h"

#endif

#include "Model/AWSS3CRTProgress.h"

#include "AWSS3CRTProgressEvent.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTProgressEvent {
GENERATED_BODY()

    /**
    *  <p>The Progress event details.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTProgress details;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTProgressEvent &fromAWS(const Aws::S3Crt::Model::ProgressEvent &awsProgressEvent) {
        this->details.fromAWS(awsProgressEvent.GetDetails());

        return *this;
    }
#endif
};
