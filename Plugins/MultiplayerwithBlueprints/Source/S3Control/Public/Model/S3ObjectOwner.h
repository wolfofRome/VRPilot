/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3ObjectOwner.h"

#endif

#include "S3ObjectOwner.generated.h"

USTRUCT(BlueprintType)
struct FS3ObjectOwner {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString iD;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString displayName;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3ObjectOwner toAWS() const {
        Aws::S3Control::Model::S3ObjectOwner awsS3ObjectOwner;

		if (!(this->iD.IsEmpty())) {
            awsS3ObjectOwner.SetID(TCHAR_TO_UTF8(*this->iD));
        }

		if (!(this->displayName.IsEmpty())) {
            awsS3ObjectOwner.SetDisplayName(TCHAR_TO_UTF8(*this->displayName));
        }

        return awsS3ObjectOwner;
    }

    bool IsEmpty() const {
        return this->iD.IsEmpty() && this->displayName.IsEmpty();
    }

    FS3ObjectOwner &fromAWS(const Aws::S3Control::Model::S3ObjectOwner &awsS3ObjectOwner) {
        this->iD = UTF8_TO_TCHAR(awsS3ObjectOwner.GetID().c_str());

        this->displayName = UTF8_TO_TCHAR(awsS3ObjectOwner.GetDisplayName().c_str());

        return *this;
    }
#endif
};
