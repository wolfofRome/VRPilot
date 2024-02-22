/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Owner.h"

#endif

#include "Owner.generated.h"

USTRUCT(BlueprintType)
struct FOwner {
GENERATED_BODY()

    /**
    *  <p>Container for the display name of the owner.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString displayName;

    /**
    *  <p>Container for the ID of the owner.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString iD;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Owner toAWS() const {
        Aws::S3::Model::Owner awsOwner;

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

    FOwner &fromAWS(const Aws::S3::Model::Owner &awsOwner) {
        this->displayName = UTF8_TO_TCHAR(awsOwner.GetDisplayName().c_str());

        this->iD = UTF8_TO_TCHAR(awsOwner.GetID().c_str());

        return *this;
    }
#endif
};
