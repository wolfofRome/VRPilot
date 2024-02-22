/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/OwnershipControls.h"

#endif

#include "Model/AWSS3CRTOwnershipControlsRule.h"

#include "AWSS3CRTOwnershipControls.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTOwnershipControls {
GENERATED_BODY()

    /**
    *  <p>The container element for an ownership control rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTOwnershipControlsRule> rules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::OwnershipControls toAWS() const {
        Aws::S3Crt::Model::OwnershipControls awsOwnershipControls;

        for (const FAWSS3CRTOwnershipControlsRule& elem : this->rules) {
            awsOwnershipControls.AddRules(elem.toAWS());
        }

        return awsOwnershipControls;
    }

    bool IsEmpty() const {
        return this->rules.Num() == 0;
    }

    FAWSS3CRTOwnershipControls &fromAWS(const Aws::S3Crt::Model::OwnershipControls &awsOwnershipControls) {
        this->rules.Empty();
        for (const Aws::S3Crt::Model::OwnershipControlsRule& elem : awsOwnershipControls.GetRules()) {
            this->rules.Add(FAWSS3CRTOwnershipControlsRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
