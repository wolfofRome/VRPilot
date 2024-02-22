/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/InventorySchedule.h"

#endif

#include "Model/AWSS3CRTInventoryFrequency.h"

#include "AWSS3CRTInventorySchedule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTInventorySchedule {
GENERATED_BODY()

    /**
    *  <p>Specifies how frequently inventory results are produced.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTInventoryFrequency frequency = EAWSS3CRTInventoryFrequency::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::InventorySchedule toAWS() const {
        Aws::S3Crt::Model::InventorySchedule awsInventorySchedule;

        switch(this->frequency) {
            case EAWSS3CRTInventoryFrequency::Daily:
                awsInventorySchedule.SetFrequency(Aws::S3Crt::Model::InventoryFrequency::Daily);
                break;
            case EAWSS3CRTInventoryFrequency::Weekly:
                awsInventorySchedule.SetFrequency(Aws::S3Crt::Model::InventoryFrequency::Weekly);
                break;
            default:
                break;
        }

        return awsInventorySchedule;
    }

    bool IsEmpty() const {
        return this->frequency == EAWSS3CRTInventoryFrequency::NOT_SET;
    }

    FAWSS3CRTInventorySchedule &fromAWS(const Aws::S3Crt::Model::InventorySchedule &awsInventorySchedule) {
        switch(awsInventorySchedule.GetFrequency()) {
            case Aws::S3Crt::Model::InventoryFrequency::NOT_SET:
                this->frequency = EAWSS3CRTInventoryFrequency::NOT_SET;
                break;
            case Aws::S3Crt::Model::InventoryFrequency::Daily:
                this->frequency = EAWSS3CRTInventoryFrequency::Daily;
                break;
            case Aws::S3Crt::Model::InventoryFrequency::Weekly:
                this->frequency = EAWSS3CRTInventoryFrequency::Weekly;
                break;
            default:
                this->frequency = EAWSS3CRTInventoryFrequency::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
