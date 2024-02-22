/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/NoncurrentVersionTransition.h"

#endif

#include "Model/AWSS3CRTTransitionStorageClass.h"

#include "AWSS3CRTNoncurrentVersionTransition.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTNoncurrentVersionTransition {
GENERATED_BODY()

    /**
    *  <p>Specifies the number of days an object is noncurrent before Amazon S3 can perform the associated action. For information about the noncurrent days calculations, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations">How Amazon S3 Calculates How Long an Object Has Been Noncurrent</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int noncurrentDays = 0;

    /**
    *  <p>The class of storage used to store the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTTransitionStorageClass storageClass = EAWSS3CRTTransitionStorageClass::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::NoncurrentVersionTransition toAWS() const {
        Aws::S3Crt::Model::NoncurrentVersionTransition awsNoncurrentVersionTransition;

        if (!(this->noncurrentDays == 0)) {
            awsNoncurrentVersionTransition.SetNoncurrentDays(this->noncurrentDays);
        }

        switch(this->storageClass) {
            case EAWSS3CRTTransitionStorageClass::GLACIER:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::GLACIER);
                break;
            case EAWSS3CRTTransitionStorageClass::STANDARD_IA:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::STANDARD_IA);
                break;
            case EAWSS3CRTTransitionStorageClass::ONEZONE_IA:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::ONEZONE_IA);
                break;
            case EAWSS3CRTTransitionStorageClass::INTELLIGENT_TIERING:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3CRTTransitionStorageClass::DEEP_ARCHIVE:
                awsNoncurrentVersionTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::DEEP_ARCHIVE);
                break;
            default:
                break;
        }

        return awsNoncurrentVersionTransition;
    }

    bool IsEmpty() const {
        return this->noncurrentDays == 0 && this->storageClass == EAWSS3CRTTransitionStorageClass::NOT_SET;
    }

    FAWSS3CRTNoncurrentVersionTransition &fromAWS(const Aws::S3Crt::Model::NoncurrentVersionTransition &awsNoncurrentVersionTransition) {
		this->noncurrentDays = awsNoncurrentVersionTransition.GetNoncurrentDays();

        switch(awsNoncurrentVersionTransition.GetStorageClass()) {
            case Aws::S3Crt::Model::TransitionStorageClass::NOT_SET:
                this->storageClass = EAWSS3CRTTransitionStorageClass::NOT_SET;
                break;
            case Aws::S3Crt::Model::TransitionStorageClass::GLACIER:
                this->storageClass = EAWSS3CRTTransitionStorageClass::GLACIER;
                break;
            case Aws::S3Crt::Model::TransitionStorageClass::STANDARD_IA:
                this->storageClass = EAWSS3CRTTransitionStorageClass::STANDARD_IA;
                break;
            case Aws::S3Crt::Model::TransitionStorageClass::ONEZONE_IA:
                this->storageClass = EAWSS3CRTTransitionStorageClass::ONEZONE_IA;
                break;
            case Aws::S3Crt::Model::TransitionStorageClass::INTELLIGENT_TIERING:
                this->storageClass = EAWSS3CRTTransitionStorageClass::INTELLIGENT_TIERING;
                break;
            case Aws::S3Crt::Model::TransitionStorageClass::DEEP_ARCHIVE:
                this->storageClass = EAWSS3CRTTransitionStorageClass::DEEP_ARCHIVE;
                break;
            default:
                this->storageClass = EAWSS3CRTTransitionStorageClass::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
