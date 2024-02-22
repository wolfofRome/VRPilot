/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Owner.h"

#endif

#include "AWSS3CRTOwner.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTOwner {
GENERATED_BODY()

    /**
    *  <p>Container for the display name of the owner.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString displayName;

    /**
    *  <p>Container for the ID of the owner.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString iD;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Owner toAWS() const {
        Aws::S3Crt::Model::Owner awsOwner;

        if (!(this->displayName.IsEmpty())) {
            awsOwner.SetDisplayName(TCHAR_TO_UTF8(*this->displayName));
        }

        if (!(this->iD.IsEmpty())) {
            awsOwner.SetID(TCHAR_TO_UTF8(*this->iD));
        }

        return awsOwner;
    }

    bool IsEmpty() const {
        return this->displayName.IsEmpty() && this->iD.IsEmpty();
    }

    FAWSS3CRTOwner &fromAWS(const Aws::S3Crt::Model::Owner &awsOwner) {
        this->displayName = UTF8_TO_TCHAR(awsOwner.GetDisplayName().c_str());

        this->iD = UTF8_TO_TCHAR(awsOwner.GetID().c_str());

        return *this;
    }
#endif
};
