/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/DeleteObjectsResult.h"

#endif

#include "Model/AWSS3CRTDeletedObject.h"
#include "Model/AWSS3CRTRequestCharged.h"
#include "Model/AWSS3CRTError.h"

#include "AWSS3CRTDeleteObjectsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDeleteObjectsResult {
GENERATED_BODY()

    /**
    *  <p>Container element for a successful delete. It identifies the object that was successfully deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTDeletedObject> deleted;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

    /**
    *  <p>Container for a failed delete action that describes the object that Amazon S3 attempted to delete and the error it encountered.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTError> errors;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTDeleteObjectsResult &fromAWS(const Aws::S3Crt::Model::DeleteObjectsResult &awsDeleteObjectsResult) {
        this->deleted.Empty();
        for (const Aws::S3Crt::Model::DeletedObject& elem : awsDeleteObjectsResult.GetDeleted()) {
            this->deleted.Add(FAWSS3CRTDeletedObject().fromAWS(elem));
        }

        switch(awsDeleteObjectsResult.GetRequestCharged()) {
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

        this->errors.Empty();
        for (const Aws::S3Crt::Model::Error& elem : awsDeleteObjectsResult.GetErrors()) {
            this->errors.Add(FAWSS3CRTError().fromAWS(elem));
        }

        return *this;
    }
#endif
};
