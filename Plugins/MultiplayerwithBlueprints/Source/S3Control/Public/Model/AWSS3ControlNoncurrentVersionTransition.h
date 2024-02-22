/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/NoncurrentVersionTransition.h"

#endif

#include "Model/AWSS3ControlTransitionStorageClass.h"

#include "AWSS3ControlNoncurrentVersionTransition.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlNoncurrentVersionTransition {
GENERATED_BODY()

    /**
    *  <p>Specifies the number of days an object is noncurrent before Amazon S3 can perform the associated action. For information about the noncurrent days calculations, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations"> How Amazon S3 Calculates How Long an Object Has Been Noncurrent</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int noncurrentDays = 0;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlTransitionStorageClass storageClass = EAWSS3ControlTransitionStorageClass::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::NoncurrentVersionTransition toAWS() const {
        Aws::S3Control::Model::NoncurrentVersionTransition awsNoncurrentVersionTransition;

        if (!(this->noncurrentDays == 0)) {
            awsNoncurrentVersionTransition.SetNoncurrentDays(this->noncurrentDays);
        }

        switch(this->storageClass) {
            case EAWSS3ControlTransitionStorageClass::GLACIER:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::GLACIER);
                break;
            case EAWSS3ControlTransitionStorageClass::STANDARD_IA:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::STANDARD_IA);
                break;
            case EAWSS3ControlTransitionStorageClass::ONEZONE_IA:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::ONEZONE_IA);
                break;
            case EAWSS3ControlTransitionStorageClass::INTELLIGENT_TIERING:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3ControlTransitionStorageClass::DEEP_ARCHIVE:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::DEEP_ARCHIVE);
                break;
            default:
                break;
        }

        return awsNoncurrentVersionTransition;
    }

    bool IsEmpty() const {
        return this->noncurrentDays == 0 && this->storageClass == EAWSS3ControlTransitionStorageClass::NOT_SET;
    }

    FAWSS3ControlNoncurrentVersionTransition &fromAWS(const Aws::S3Control::Model::NoncurrentVersionTransition &awsNoncurrentVersionTransition) {
		this->noncurrentDays = awsNoncurrentVersionTransition.GetNoncurrentDays();

        switch(awsNoncurrentVersionTransition.GetStorageClass()) {
            case Aws::S3Control::Model::TransitionStorageClass::NOT_SET:
                this->storageClass = EAWSS3ControlTransitionStorageClass::NOT_SET;
                break;
            case Aws::S3Control::Model::TransitionStorageClass::GLACIER:
                this->storageClass = EAWSS3ControlTransitionStorageClass::GLACIER;
                break;
            case Aws::S3Control::Model::TransitionStorageClass::STANDARD_IA:
                this->storageClass = EAWSS3ControlTransitionStorageClass::STANDARD_IA;
                break;
            case Aws::S3Control::Model::TransitionStorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3ControlTransitionStorageClass::ONEZONE_IA;
                break;
            case Aws::S3Control::Model::TransitionStorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3ControlTransitionStorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3Control::Model::TransitionStorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3ControlTransitionStorageClass::DEEP_ARCHIVE;
                break;
            default:
                this->storageClass = EAWSS3ControlTransitionStorageClass::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
