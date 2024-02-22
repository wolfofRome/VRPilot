/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeleteObjectResult.h"

#endif

#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTDeleteObjectResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeleteObjectResult {
GENERATED_BODY()

    /**
    *  <p>Specifies whether the versioned object that was permanently deleted was (true) or was not (false) a delete marker.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool deleteMarker = false;

    /**
    *  <p>Returns the version ID of the delete marker created as a result of the DELETE operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTDeleteObjectResult &fromAWS(const Aws::S3Crt::Model::DeleteObjectResult &awsDeleteObjectResult) {
        this->deleteMarker = awsDeleteObjectResult.GetDeleteMarker();

        this->versionId = UTF8_TO_TCHAR(awsDeleteObjectResult.GetVersionId().c_str());

        switch(awsDeleteObjectResult.GetRequestCharged()) {
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
