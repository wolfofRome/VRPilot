/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/InventorySchedule.h"

#endif

#include "Model/InventoryFrequency.h"

#include "InventorySchedule.generated.h"

USTRUCT(BlueprintType)
struct FInventorySchedule {
GENERATED_BODY()

    /**
    *  <p>Specifies how frequently inventory results are produced.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSInventoryFrequency frequency = EAWSInventoryFrequency::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::InventorySchedule toAWS() const {
        Aws::S3::Model::InventorySchedule awsInventorySchedule;

        switch(this->frequency) {
            case EAWSInventoryFrequency::Daily:
                awsInventorySchedule.SetFrequency(Aws::S3::Model::InventoryFrequency::Daily);
                break;
            case EAWSInventoryFrequency::Weekly:
                awsInventorySchedule.SetFrequency(Aws::S3::Model::InventoryFrequency::Weekly);
                break;
            default:
                break;
        }

        return awsInventorySchedule;
    }

    bool IsEmpty() const {
        return frequency == EAWSInventoryFrequency::NOT_SET;
    }

    FInventorySchedule &fromAWS(const Aws::S3::Model::InventorySchedule &awsInventorySchedule) {
        switch(awsInventorySchedule.GetFrequency()) {
            case Aws::S3::Model::InventoryFrequency::NOT_SET:
                this->frequency = EAWSInventoryFrequency::NOT_SET;
                break;
            case Aws::S3::Model::InventoryFrequency::Daily:
                this->frequency = EAWSInventoryFrequency::Daily;
                break;
            case Aws::S3::Model::InventoryFrequency::Weekly:
                this->frequency = EAWSInventoryFrequency::Weekly;
                break;
            default:
                this->frequency = EAWSInventoryFrequency::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
