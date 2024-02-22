/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/S3KeyFilter.h"

#endif

#include "Model/AWSS3CRTFilterRule.h"

#include "AWSS3CRTS3KeyFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTS3KeyFilter {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTFilterRule> filterRules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::S3KeyFilter toAWS() const {
        Aws::S3Crt::Model::S3KeyFilter awsS3KeyFilter;

        for (const FAWSS3CRTFilterRule& elem : this->filterRules) {
            awsS3KeyFilter.AddFilterRules(elem.toAWS());
        }

        return awsS3KeyFilter;
    }

    bool IsEmpty() const {
        return this->filterRules.Num() == 0;
    }

    FAWSS3CRTS3KeyFilter &fromAWS(const Aws::S3Crt::Model::S3KeyFilter &awsS3KeyFilter) {
        this->filterRules.Empty();
        for (const Aws::S3Crt::Model::FilterRule& elem : awsS3KeyFilter.GetFilterRules()) {
            this->filterRules.Add(FAWSS3CRTFilterRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
