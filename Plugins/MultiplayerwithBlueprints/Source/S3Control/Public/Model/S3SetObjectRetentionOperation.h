/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3SetObjectRetentionOperation.h"

#endif

#include "Model/S3Retention.h"

#include "S3SetObjectRetentionOperation.generated.h"

USTRUCT(BlueprintType)
struct FS3SetObjectRetentionOperation {
GENERATED_BODY()

    /**
    *  <p>Indicates if the operation should be applied to objects in the Batch Operations job even if they have Governance-type Object Lock in place.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool bypassGovernanceRetention = false;

    /**
    *  <p>Amazon S3 object lock Retention contains the retention mode to be applied to all objects in the Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3Retention retention;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3SetObjectRetentionOperation toAWS() const {
        Aws::S3Control::Model::S3SetObjectRetentionOperation awsS3SetObjectRetentionOperation;

        if (!(false)) {
            awsS3SetObjectRetentionOperation.SetBypassGovernanceRetention(this->bypassGovernanceRetention);
        }

        if (!(this->retention.IsEmpty())) {
            awsS3SetObjectRetentionOperation.SetRetention(this->retention.toAWS());
        }

        return awsS3SetObjectRetentionOperation;
    }

    bool IsEmpty() const {
        return false && this->retention.IsEmpty();
    }

    FS3SetObjectRetentionOperation &fromAWS(const Aws::S3Control::Model::S3SetObjectRetentionOperation &awsS3SetObjectRetentionOperation) {
        this->bypassGovernanceRetention = awsS3SetObjectRetentionOperation.GetBypassGovernanceRetention();

        this->retention.fromAWS(awsS3SetObjectRetentionOperation.GetRetention());

        return *this;
    }
#endif
};
