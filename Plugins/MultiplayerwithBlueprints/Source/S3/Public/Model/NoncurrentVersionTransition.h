/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/NoncurrentVersionTransition.h"

#endif

#include "Model/TransitionStorageClass.h"

#include "NoncurrentVersionTransition.generated.h"

USTRUCT(BlueprintType)
struct FNoncurrentVersionTransition {
GENERATED_BODY()

    /**
    *  <p>Specifies the number of days an object is noncurrent before Amazon S3 can perform the associated action. For information about the noncurrent days calculations, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations">How Amazon S3 Calculates How Long an Object Has Been Noncurrent</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int noncurrentDays = 0;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSTransitionStorageClass storageClass = EAWSTransitionStorageClass::NOT_SET;

    /**
    *  <p>Specifies how many noncurrent versions Amazon S3 will retain. If there are this many more recent noncurrent versions, Amazon S3 will take the associated action. For more information about noncurrent versions, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/intro-lifecycle-rules.html">Lifecycle configuration elements</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int newerNoncurrentVersions = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::NoncurrentVersionTransition toAWS() const {
        Aws::S3::Model::NoncurrentVersionTransition awsNoncurrentVersionTransition;

        if (!(this->noncurrentDays == 0)) {
            awsNoncurrentVersionTransition.SetNoncurrentDays(this->noncurrentDays);
        }

        switch(this->storageClass) {
            case EAWSTransitionStorageClass::GLACIER:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::GLACIER);
                break;
            case EAWSTransitionStorageClass::STANDARD_IA:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::STANDARD_IA);
                break;
            case EAWSTransitionStorageClass::ONEZONE_IA:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::ONEZONE_IA);
                break;
            case EAWSTransitionStorageClass::INTELLIGENT_TIERING:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSTransitionStorageClass::DEEP_ARCHIVE:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::DEEP_ARCHIVE);
                break;
            case EAWSTransitionStorageClass::GLACIER_IR:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::GLACIER_IR);
                break;
            default:
                break;
        }
        
        if (!(this->newerNoncurrentVersions == 0)) {
            awsNoncurrentVersionTransition.SetNewerNoncurrentVersions(this->newerNoncurrentVersions);
        }

        return awsNoncurrentVersionTransition;
    }

    bool IsEmpty() const {
        return this->noncurrentDays == 0 && storageClass == EAWSTransitionStorageClass::NOT_SET && this->newerNoncurrentVersions == 0;
    }

    FNoncurrentVersionTransition &fromAWS(const Aws::S3::Model::NoncurrentVersionTransition &awsNoncurrentVersionTransition) {
		this->noncurrentDays = awsNoncurrentVersionTransition.GetNoncurrentDays();

        switch(awsNoncurrentVersionTransition.GetStorageClass()) {
            case Aws::S3::Model::TransitionStorageClass::NOT_SET:
                this->storageClass = EAWSTransitionStorageClass::NOT_SET;
                break;
            case Aws::S3::Model::TransitionStorageClass::GLACIER:
                this->storageClass = EAWSTransitionStorageClass::GLACIER;
                break;
            case Aws::S3::Model::TransitionStorageClass::STANDARD_IA:
                this->storageClass = EAWSTransitionStorageClass::STANDARD_IA;
                break;
            case Aws::S3::Model::TransitionStorageClass::ONEZONE_IA:
                this->storageClass = EAWSTransitionStorageClass::ONEZONE_IA;
                break;
            case Aws::S3::Model::TransitionStorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSTransitionStorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3::Model::TransitionStorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSTransitionStorageClass::DEEP_ARCHIVE;
                break;
            case Aws::S3::Model::TransitionStorageClass::GLACIER_IR:
                this->storageClass = EAWSTransitionStorageClass::GLACIER_IR;
                break;
            default:
                this->storageClass = EAWSTransitionStorageClass::NOT_SET;
                break;
        }

		this->newerNoncurrentVersions = awsNoncurrentVersionTransition.GetNewerNoncurrentVersions();

        return *this;
    }
#endif
};
