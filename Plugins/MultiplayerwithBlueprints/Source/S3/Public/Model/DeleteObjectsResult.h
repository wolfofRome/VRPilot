/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/DeleteObjectsResult.h"

#endif

#include "Model/DeletedObject.h"
#include "Model/RequestCharged.h"
#include "Model/Error.h"

#include "DeleteObjectsResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteObjectsResult {
GENERATED_BODY()

    /**
    *  <p>Container element for a successful delete. It identifies the object that was successfully deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FDeletedObject> deleted;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

    /**
    *  <p>Container for a failed delete operation that describes the object that Amazon S3 attempted to delete and the error it encountered.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FError> errors;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FDeleteObjectsResult &fromAWS(const Aws::S3::Model::DeleteObjectsResult &awsDeleteObjectsResult) {
        this->deleted.Empty();
        for (const Aws::S3::Model::DeletedObject& elem : awsDeleteObjectsResult.GetDeleted()) {
            this->deleted.Add(FDeletedObject().fromAWS(elem));
        }

        switch(awsDeleteObjectsResult.GetRequestCharged()) {
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

        this->errors.Empty();
        for (const Aws::S3::Model::Error& elem : awsDeleteObjectsResult.GetErrors()) {
            this->errors.Add(FError().fromAWS(elem));
        }

        return *this;
    }
#endif
};
