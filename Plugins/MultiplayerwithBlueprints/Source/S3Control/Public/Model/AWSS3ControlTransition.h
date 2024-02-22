/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/Transition.h"

#endif

#include "Model/AWSS3ControlTransitionStorageClass.h"

#include "AWSS3ControlTransition.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlTransition {
GENERATED_BODY()

    /**
    *  <p>Indicates when objects are transitioned to the specified storage class. The date value must be in ISO 8601 format. The time is always midnight UTC.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime date;

    /**
    *  <p>Indicates the number of days after creation when objects are transitioned to the specified storage class. The value must be a positive integer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int days = 0;

    /**
    *  <p>The storage class to which you want the object to transition.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlTransitionStorageClass storageClass = EAWSS3ControlTransitionStorageClass::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::Transition toAWS() const {
        Aws::S3Control::Model::Transition awsTransition;

        if (!(this->date.ToUnixTimestamp() <= 0)) {
            awsTransition.SetDate(Aws::Utils::DateTime((int64_t)((this->date - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->days == 0)) {
            awsTransition.SetDays(this->days);
        }

        switch(this->storageClass) {
            case EAWSS3ControlTransitionStorageClass::GLACIER:
                awsTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::GLACIER);
                break;
            case EAWSS3ControlTransitionStorageClass::STANDARD_IA:
                awsTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::STANDARD_IA);
                break;
            case EAWSS3ControlTransitionStorageClass::ONEZONE_IA:
                awsTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::ONEZONE_IA);
                break;
            case EAWSS3ControlTransitionStorageClass::INTELLIGENT_TIERING:
                awsTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3ControlTransitionStorageClass::DEEP_ARCHIVE:
                awsTransition.SetStorageClass(Aws::S3Control::Model::TransitionStorageClass::DEEP_ARCHIVE);
                break;
            default:
                break;
        }

        return awsTransition;
    }

    bool IsEmpty() const {
        return this->date.ToUnixTimestamp() <= 0 && this->days == 0 && this->storageClass == EAWSS3ControlTransitionStorageClass::NOT_SET;
    }

    FAWSS3ControlTransition &fromAWS(const Aws::S3Control::Model::Transition &awsTransition) {
        this->date = FDateTime(1970, 1, 1) + FTimespan(awsTransition.GetDate().Millis() * ETimespan::TicksPerMillisecond);

		this->days = awsTransition.GetDays();

        switch(awsTransition.GetStorageClass()) {
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
