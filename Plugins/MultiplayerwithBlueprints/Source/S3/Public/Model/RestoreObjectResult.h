/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/RestoreObjectResult.h"

#endif

#include "Model/RequestCharged.h"

#include "RestoreObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FRestoreObjectResult {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>Indicates the path in the provided S3 output location where Select results will be restored to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString restoreOutputPath;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FRestoreObjectResult &fromAWS(const Aws::S3::Model::RestoreObjectResult &awsRestoreObjectResult) {
        switch(awsRestoreObjectResult.GetRequestCharged()) {
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

        this->restoreOutputPath = UTF8_TO_TCHAR(awsRestoreObjectResult.GetRestoreOutputPath().c_str());

        return *this;
    }
#endif
};
