/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/DeleteEndpointRequest.h"

#endif

#include "AWSS3OutpostsDeleteEndpointRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsDeleteEndpointRequest {
GENERATED_BODY()

    /**
    *  <p>The ID of the end point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString endpointId;

    /**
    *  <p>The ID of the AWS Outpost. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString outpostId;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    Aws::S3Outposts::Model::DeleteEndpointRequest toAWS() const {
        Aws::S3Outposts::Model::DeleteEndpointRequest awsDeleteEndpointRequest;

        if (!(this->endpointId.IsEmpty())) {
            awsDeleteEndpointRequest.SetEndpointId(TCHAR_TO_UTF8(*this->endpointId));
        }

        if (!(this->outpostId.IsEmpty())) {
            awsDeleteEndpointRequest.SetOutpostId(TCHAR_TO_UTF8(*this->outpostId));
        }

        return awsDeleteEndpointRequest;
    }

    bool IsEmpty() const {
        return this->endpointId.IsEmpty() && this->outpostId.IsEmpty();
    }
#endif
};
