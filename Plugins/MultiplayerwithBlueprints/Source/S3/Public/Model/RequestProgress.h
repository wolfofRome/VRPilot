/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/RequestProgress.h"

#endif

#include "RequestProgress.generated.h"

USTRUCT(BlueprintType)
struct FRequestProgress {
GENERATED_BODY()

    /**
    *  <p>Specifies whether periodic QueryProgress frames should be sent. Valid values: TRUE, FALSE. Default value: FALSE.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool enabled = false;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::RequestProgress toAWS() const {
        Aws::S3::Model::RequestProgress awsRequestProgress;

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
