/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Transition.h"

#endif

#include "Model/TransitionStorageClass.h"

#include "Transition.generated.h"

USTRUCT(BlueprintType)
struct FTransition {
GENERATED_BODY()

    /**
    *  <p>Indicates when objects are transitioned to the specified storage class. The date value must be in ISO 8601 format. The time is always midnight UTC.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDateTime date;

    /**
    *  <p>Indicates the number of days after creation when objects are transitioned to the specified storage class. The value must be a positive integer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int days = 0;

    /**
    *  <p>The storage class to which you want the object to transition.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSTransitionStorageClass storageClass = EAWSTransitionStorageClass::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Transition toAWS() const {
        Aws::S3::Model::Transition awsTransition;

        if (!(this->date.ToUnixTimestamp() <= 0)) {
            awsTransition.SetDate(Aws::Utils::DateTime((int64_t)((this->date - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->days == 0)) {
            awsTransition.SetDays(this->days);
        }

        switch(this->storageClass) {
            case EAWSTransitionStorageClass::GLACIER:
                awsTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::GLACIER);
                break;
            case EAWSTransitionStorageClass::STANDARD_IA:
                awsTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::STANDARD_IA);
                break;
            case EAWSTransitionStorageClass::ONEZONE_IA:
                awsTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::ONEZONE_IA);
                break;
            case EAWSTransitionStorageClass::INTELLIGENT_TIERING:
                awsTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSTransitionStorageClass::DEEP_ARCHIVE:
                awsTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::DEEP_ARCHIVE);
                break;
            case EAWSTransitionStorageClass::GLACIER_IR:
                awsTransition.SetStorageClass(Aws::S3::Model::TransitionStorageClass::GLACIER_IR);
                break;
            default:
                break;
            }

        return awsTransition;
    }

    bool IsEmpty() const {
        return date.ToUnixTimestamp() <= 0 && this->days == 0 && storageClass == EAWSTransitionStorageClass::NOT_SET;
    }

    FTransition &fromAWS(const Aws::S3::Model::Transition &awsTransition) {
        this->date = FDateTime(1970, 1, 1) + FTimespan(awsTransition.GetDate().Millis() * ETimespan::TicksPerMillisecond);

		this->days = awsTransition.GetDays();

        switch(awsTransition.GetStorageClass()) {
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

        return *this;
    }
#endif
};
