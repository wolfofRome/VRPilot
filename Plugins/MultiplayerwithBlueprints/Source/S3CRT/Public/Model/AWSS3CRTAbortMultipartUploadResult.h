/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AbortMultipartUploadResult.h"

#endif

#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTAbortMultipartUploadResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAbortMultipartUploadResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTAbortMultipartUploadResult &fromAWS(const Aws::S3Crt::Model::AbortMultipartUploadResult &awsAbortMultipartUploadResult) {
        switch(awsAbortMultipartUploadResult.GetRequestCharged()) {
            case Aws::S3Crt::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
            case Aws::S3Crt::Model::RequestCharged::requester:
                this->requestCharged = EAWSS3CRTRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
