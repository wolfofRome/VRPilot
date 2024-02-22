/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteObjectResult.h"

#endif

#include "Model/RequestCharged.h"

#include "DeleteObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteObjectResult {
GENERATED_BODY()

    /**
    *  <p>Specifies whether the versioned object that was permanently deleted was (true) or was not (false) a delete marker.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool deleteMarker = false;

    /**
    *  <p>Returns the version ID of the delete marker created as a result of the DELETE operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString versionId;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FDeleteObjectResult &fromAWS(const Aws::S3::Model::DeleteObjectResult &awsDeleteObjectResult) {
        this->deleteMarker = awsDeleteObjectResult.GetDeleteMarker();

        this->versionId = UTF8_TO_TCHAR(awsDeleteObjectResult.GetVersionId().c_str());

        switch(awsDeleteObjectResult.GetRequestCharged()) {
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
