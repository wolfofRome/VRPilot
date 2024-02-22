/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AbortMultipartUploadResult.h"

#endif

#include "Model/RequestCharged.h"

#include "AbortMultipartUploadResult.generated.h"

USTRUCT(BlueprintType)
struct FAbortMultipartUploadResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FAbortMultipartUploadResult &fromAWS(const Aws::S3::Model::AbortMultipartUploadResult &awsAbortMultipartUploadResult) {
        switch(awsAbortMultipartUploadResult.GetRequestCharged()) {
            case Aws::S3::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
            case Aws::S3::Model::RequestCharged::requester:
                this->requestCharged = EAWSRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
