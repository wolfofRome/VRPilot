/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/S3KeyFilter.h"

#endif

#include "Model/FilterRule.h"

#include "S3KeyFilter.generated.h"

USTRUCT(BlueprintType)
struct FS3KeyFilter {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FFilterRule> filterRules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::S3KeyFilter toAWS() const {
        Aws::S3::Model::S3KeyFilter awsS3KeyFilter;

        for (const FFilterRule& elem : this->filterRules) {
            awsS3KeyFilter.AddFilterRules(elem.toAWS());
        }

        return awsS3KeyFilter;
    }

    bool IsEmpty() const {
        return this->filterRules.Num() == 0;
    }

    FS3KeyFilter &fromAWS(const Aws::S3::Model::S3KeyFilter &awsS3KeyFilter) {
        this->filterRules.Empty();
        for (const Aws::S3::Model::FilterRule& elem : awsS3KeyFilter.GetFilterRules()) {
            this->filterRules.Add(FFilterRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
