/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/RestoreObjectResult.h"

#endif

#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTRestoreObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTRestoreObjectResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

    /**
    *  <p>Indicates the path in the provided S3 output location where Select results will be restored to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString restoreOutputPath;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTRestoreObjectResult &fromAWS(const Aws::S3Crt::Model::RestoreObjectResult &awsRestoreObjectResult) {
        switch(awsRestoreObjectResult.GetRequestCharged()) {
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

        this->restoreOutputPath = UTF8_TO_TCHAR(awsRestoreObjectResult.GetRestoreOutputPath().c_str());

        return *this;
    }
#endif
};
