/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/StorageLensDataExportEncryption.h"

#endif

#include "Model/AWSS3ControlSSES3.h"
#include "Model/AWSS3ControlSSEKMS.h"

#include "AWSS3ControlStorageLensDataExportEncryption.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlStorageLensDataExportEncryption {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlSSES3 sSES3;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlSSEKMS sSEKMS;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::StorageLensDataExportEncryption toAWS() const {
        Aws::S3Control::Model::StorageLensDataExportEncryption awsStorageLensDataExportEncryption;

        if (!(this->sSES3.IsEmpty())) {
            awsStorageLensDataExportEncryption.SetSSES3(this->sSES3.toAWS());
        }

        if (!(this->sSEKMS.IsEmpty())) {
            awsStorageLensDataExportEncryption.SetSSEKMS(this->sSEKMS.toAWS());
        }

        return awsStorageLensDataExportEncryption;
    }

    bool IsEmpty() const {
        return this->sSES3.IsEmpty() && this->sSEKMS.IsEmpty();
    }

    FAWSS3ControlStorageLensDataExportEncryption &fromAWS(const Aws::S3Control::Model::StorageLensDataExportEncryption &awsStorageLensDataExportEncryption) {
        this->sSES3.fromAWS(awsStorageLensDataExportEncryption.GetSSES3());

        this->sSEKMS.fromAWS(awsStorageLensDataExportEncryption.GetSSEKMS());

        return *this;
    }
#endif
};
