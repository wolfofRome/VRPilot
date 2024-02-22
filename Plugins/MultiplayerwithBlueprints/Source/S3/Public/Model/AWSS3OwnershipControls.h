/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/OwnershipControls.h"

#endif

#include "Model/AWSS3OwnershipControlsRule.h"

#include "AWSS3OwnershipControls.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OwnershipControls {
GENERATED_BODY()

    /**
    *  <p>The container element for an ownership control rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FAWSS3OwnershipControlsRule> rules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::OwnershipControls toAWS() const {
        Aws::S3::Model::OwnershipControls awsOwnershipControls;

        for (const FAWSS3OwnershipControlsRule& elem : this->rules) {
            awsOwnershipControls.AddRules(elem.toAWS());
        }

        return awsOwnershipControls;
    }

    bool IsEmpty() const {
        return this->rules.Num() == 0;
    }

    FAWSS3OwnershipControls &fromAWS(const Aws::S3::Model::OwnershipControls &awsOwnershipControls) {
        this->rules.Empty();
        for (const Aws::S3::Model::OwnershipControlsRule& elem : awsOwnershipControls.GetRules()) {
            this->rules.Add(FAWSS3OwnershipControlsRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
