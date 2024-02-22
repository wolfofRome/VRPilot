/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3SetObjectAclOperation.h"

#endif

#include "Model/S3AccessControlPolicy.h"

#include "S3SetObjectAclOperation.generated.h"

USTRUCT(BlueprintType)
struct FS3SetObjectAclOperation {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3AccessControlPolicy accessControlPolicy;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3SetObjectAclOperation toAWS() const {
        Aws::S3Control::Model::S3SetObjectAclOperation awsS3SetObjectAclOperation;

        if (!(this->accessControlPolicy.IsEmpty())) {
            awsS3SetObjectAclOperation.SetAccessControlPolicy(this->accessControlPolicy.toAWS());
        }

        return awsS3SetObjectAclOperation;
    }

    bool IsEmpty() const {
        return this->accessControlPolicy.IsEmpty();
    }

    FS3SetObjectAclOperation &fromAWS(const Aws::S3Control::Model::S3SetObjectAclOperation &awsS3SetObjectAclOperation) {
        this->accessControlPolicy.fromAWS(awsS3SetObjectAclOperation.GetAccessControlPolicy());

        return *this;
    }
#endif
};
