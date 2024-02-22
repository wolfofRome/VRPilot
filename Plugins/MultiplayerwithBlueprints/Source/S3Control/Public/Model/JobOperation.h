/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobOperation.h"

#endif

#include "Model/LambdaInvokeOperation.h"
#include "Model/S3CopyObjectOperation.h"
#include "Model/S3SetObjectAclOperation.h"
#include "Model/S3SetObjectTaggingOperation.h"
#include "Model/AWSS3ControlS3DeleteObjectTaggingOperation.h"
#include "Model/S3InitiateRestoreObjectOperation.h"
#include "Model/S3SetObjectLegalHoldOperation.h"
#include "Model/S3SetObjectRetentionOperation.h"
#include "Model/AWSS3ControlS3ReplicateObjectOperation.h"

#include "JobOperation.generated.h"

USTRUCT(BlueprintType)
struct FJobOperation {
GENERATED_BODY()

    /**
    *  <p>Directs the specified job to invoke an Lambda function on every object in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FLambdaInvokeOperation lambdaInvoke;

    /**
    *  <p>Directs the specified job to run a PUT Copy object call on every object in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3CopyObjectOperation s3PutObjectCopy;

    /**
    *  <p>Directs the specified job to run a <code>PutObjectAcl</code> call on every object in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3SetObjectAclOperation s3PutObjectAcl;

    /**
    *  <p>Directs the specified job to run a PUT Object tagging call on every object in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3SetObjectTaggingOperation s3PutObjectTagging;

    /**
    *  <p>Directs the specified job to execute a DELETE Object tagging call on every object in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlS3DeleteObjectTaggingOperation s3DeleteObjectTagging;

    /**
    *  <p>Directs the specified job to initiate restore requests for every archived object in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3InitiateRestoreObjectOperation s3InitiateRestoreObject;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3SetObjectLegalHoldOperation s3PutObjectLegalHold;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3SetObjectRetentionOperation s3PutObjectRetention;

    /**
    *  <p>Directs the specified job to invoke <code>ReplicateObject</code> on every object in the job's manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlS3ReplicateObjectOperation s3ReplicateObject;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::JobOperation toAWS() const {
        Aws::S3Control::Model::JobOperation awsJobOperation;

        if (!(this->lambdaInvoke.IsEmpty())) {
            awsJobOperation.SetLambdaInvoke(this->lambdaInvoke.toAWS());
        }

        if (!(this->s3PutObjectCopy.IsEmpty())) {
            awsJobOperation.SetS3PutObjectCopy(this->s3PutObjectCopy.toAWS());
        }

        if (!(this->s3PutObjectAcl.IsEmpty())) {
            awsJobOperation.SetS3PutObjectAcl(this->s3PutObjectAcl.toAWS());
        }

        if (!(this->s3PutObjectTagging.IsEmpty())) {
            awsJobOperation.SetS3PutObjectTagging(this->s3PutObjectTagging.toAWS());
        }

        if (!(this->s3DeleteObjectTagging.IsEmpty())) {
            awsJobOperation.SetS3DeleteObjectTagging(this->s3DeleteObjectTagging.toAWS());
        }

        if (!(this->s3InitiateRestoreObject.IsEmpty())) {
            awsJobOperation.SetS3InitiateRestoreObject(this->s3InitiateRestoreObject.toAWS());
        }

        if (!(this->s3PutObjectLegalHold.IsEmpty())) {
            awsJobOperation.SetS3PutObjectLegalHold(this->s3PutObjectLegalHold.toAWS());
        }

        if (!(this->s3PutObjectRetention.IsEmpty())) {
            awsJobOperation.SetS3PutObjectRetention(this->s3PutObjectRetention.toAWS());
        }

        if (!(this->s3ReplicateObject.IsEmpty())) {
            awsJobOperation.SetS3ReplicateObject(this->s3ReplicateObject.toAWS());
        }

        return awsJobOperation;
    }

    bool IsEmpty() const {
        return this->lambdaInvoke.IsEmpty() && this->s3PutObjectCopy.IsEmpty() && this->s3PutObjectAcl.IsEmpty() && this->s3PutObjectTagging.IsEmpty() && this->s3DeleteObjectTagging.IsEmpty() && this->s3InitiateRestoreObject.IsEmpty() && this->s3PutObjectLegalHold.IsEmpty() && this->s3PutObjectRetention.IsEmpty() && this->s3ReplicateObject.IsEmpty();
    }

    FJobOperation &fromAWS(const Aws::S3Control::Model::JobOperation &awsJobOperation) {
        this->lambdaInvoke.fromAWS(awsJobOperation.GetLambdaInvoke());

        this->s3PutObjectCopy.fromAWS(awsJobOperation.GetS3PutObjectCopy());

        this->s3PutObjectAcl.fromAWS(awsJobOperation.GetS3PutObjectAcl());

        this->s3PutObjectTagging.fromAWS(awsJobOperation.GetS3PutObjectTagging());

        this->s3DeleteObjectTagging.fromAWS(awsJobOperation.GetS3DeleteObjectTagging());

        this->s3InitiateRestoreObject.fromAWS(awsJobOperation.GetS3InitiateRestoreObject());

        this->s3PutObjectLegalHold.fromAWS(awsJobOperation.GetS3PutObjectLegalHold());

        this->s3PutObjectRetention.fromAWS(awsJobOperation.GetS3PutObjectRetention());

        this->s3ReplicateObject.fromAWS(awsJobOperation.GetS3ReplicateObject());

        return *this;
    }
#endif
};
