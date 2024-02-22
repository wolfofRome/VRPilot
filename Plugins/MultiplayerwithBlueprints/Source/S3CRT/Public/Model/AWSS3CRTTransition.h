/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Transition.h"

#endif

#include "Model/AWSS3CRTTransitionStorageClass.h"

#include "AWSS3CRTTransition.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTTransition {
GENERATED_BODY()

    /**
    *  <p>Indicates when objects are transitioned to the specified storage class. The date value must be in ISO 8601 format. The time is always midnight UTC.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime date;

    /**
    *  <p>Indicates the number of days after creation when objects are transitioned to the specified storage class. The value must be a positive integer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int days = 0;

    /**
    *  <p>The storage class to which you want the object to transition.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTTransitionStorageClass storageClass = EAWSS3CRTTransitionStorageClass::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Transition toAWS() const {
        Aws::S3Crt::Model::Transition awsTransition;

        if (!(this->date.ToUnixTimestamp() <= 0)) {
            awsTransition.SetDate(Aws::Utils::DateTime((int64_t)((this->date - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->days == 0)) {
            awsTransition.SetDays(this->days);
        }

        switch(this->storageClass) {
            case EAWSS3CRTTransitionStorageClass::GLACIER:
                awsTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::GLACIER);
                break;
            case EAWSS3CRTTransitionStorageClass::STANDARD_IA:
                awsTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::STANDARD_IA);
                break;
            case EAWSS3CRTTransitionStorageClass::ONEZONE_IA:
                awsTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::ONEZONE_IA);
                break;
            case EAWSS3CRTTransitionStorageClass::INTELLIGENT_TIERING:
                awsTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::INTELLIGENT_TIERING);
                break;
            case EAWSS3CRTTransitionStorageClass::DEEP_ARCHIVE:
                awsTransition.SetStorageClass(Aws::S3Crt::Model::TransitionStorageClass::DEEP_ARCHIVE);
                break;
            default:
                break;
        }

        return awsTransition;
    }

    bool IsEmpty() const {
        return this->date.ToUnixTimestamp() <= 0 && this->days == 0 && this->storageClass == EAWSS3CRTTransitionStorageClass::NOT_SET;
    }

    FAWSS3CRTTransition &fromAWS(const Aws::S3Crt::Model::Transition &awsTransition) {
        this->date = FDateTime(1970, 1, 1) + FTimespan(awsTransition.GetDate().Millis() * ETimespan::TicksPerMillisecond);

		this->days = awsTransition.GetDays();

        switch(awsTransition.GetStorageClass()) {
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
