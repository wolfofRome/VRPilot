/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ProgressEvent.h"

#endif

#include "Model/Progress.h"

#include "ProgressEvent.generated.h"

USTRUCT(BlueprintType)
struct FProgressEvent {
GENERATED_BODY()

    /**
    *  <p>The Progress event details.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FProgress details;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FProgressEvent &fromAWS(const Aws::S3::Model::ProgressEvent &awsProgressEvent) {
        this->details.fromAWS(awsProgressEvent.GetDetails());

        return *this;
    }
#endif
};
