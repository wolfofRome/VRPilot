/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3AccessControlList.h"

#endif

#include "Model/S3ObjectOwner.h"
#include "Model/S3Grant.h"

#include "S3AccessControlList.generated.h"

USTRUCT(BlueprintType)
struct FS3AccessControlList {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ObjectOwner owner;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3Grant> grants;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3AccessControlList toAWS() const {
        Aws::S3Control::Model::S3AccessControlList awsS3AccessControlList;

        if (!(this->owner.IsEmpty())) {
            awsS3AccessControlList.SetOwner(this->owner.toAWS());
        }

        for (const FS3Grant& elem : this->grants) {
            awsS3AccessControlList.AddGrants(elem.toAWS());
        }

        return awsS3AccessControlList;
    }

    bool IsEmpty() const {
        return this->owner.IsEmpty() && this->grants.Num() == 0;
    }

    FS3AccessControlList &fromAWS(const Aws::S3Control::Model::S3AccessControlList &awsS3AccessControlList) {
        this->owner.fromAWS(awsS3AccessControlList.GetOwner());

        this->grants.Empty();
        for (const Aws::S3Control::Model::S3Grant& elem : awsS3AccessControlList.GetGrants()) {
            this->grants.Add(FS3Grant().fromAWS(elem));
        }

        return *this;
    }
#endif
};
