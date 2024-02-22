/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/LifecycleRuleAndOperator.h"

#endif

#include "Model/AWSS3CRTTag.h"

#include "AWSS3CRTLifecycleRuleAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTLifecycleRuleAndOperator {
GENERATED_BODY()

    /**
    *  <p>Prefix identifying one or more objects to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>All of these tags must exist in the object's tag set in order for the rule to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTag> tags;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::LifecycleRuleAndOperator toAWS() const {
        Aws::S3Crt::Model::LifecycleRuleAndOperator awsLifecycleRuleAndOperator;

        if (!(this->prefix.IsEmpty())) {
            awsLifecycleRuleAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FAWSS3CRTTag& elem : this->tags) {
            awsLifecycleRuleAndOperator.AddTags(elem.toAWS());
        }

        return awsLifecycleRuleAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0;
    }

    FAWSS3CRTLifecycleRuleAndOperator &fromAWS(const Aws::S3Crt::Model::LifecycleRuleAndOperator &awsLifecycleRuleAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsLifecycleRuleAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3Crt::Model::Tag& elem : awsLifecycleRuleAndOperator.GetTags()) {
            this->tags.Add(FAWSS3CRTTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
