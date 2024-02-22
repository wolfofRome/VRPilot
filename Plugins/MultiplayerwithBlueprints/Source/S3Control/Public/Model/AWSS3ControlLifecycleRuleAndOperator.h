/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/LifecycleRuleAndOperator.h"

#endif

#include "Model/S3ControlS3Tag.h"

#include "AWSS3ControlLifecycleRuleAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlLifecycleRuleAndOperator {
GENERATED_BODY()

    /**
    *  <p>Prefix identifying one or more objects to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString prefix;

    /**
    *  <p>All of these tags must exist in the object's tag set in order for the rule to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3ControlS3Tag> tags;

    /**
    *  <p>Minimum object size to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int64 objectSizeGreaterThan = 0;

    /**
    *  <p>Maximum object size to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int64 objectSizeLessThan = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::LifecycleRuleAndOperator toAWS() const {
        Aws::S3Control::Model::LifecycleRuleAndOperator awsLifecycleRuleAndOperator;

        if (!(this->prefix.IsEmpty())) {
            awsLifecycleRuleAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FS3ControlS3Tag& elem : this->tags) {
            awsLifecycleRuleAndOperator.AddTags(elem.toAWS());
        }

        if (!(this->objectSizeGreaterThan == 0)) {
            awsLifecycleRuleAndOperator.SetObjectSizeGreaterThan(this->objectSizeGreaterThan);
        }

        if (!(this->objectSizeLessThan == 0)) {
            awsLifecycleRuleAndOperator.SetObjectSizeLessThan(this->objectSizeLessThan);
        }

        return awsLifecycleRuleAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0 && this->objectSizeGreaterThan == 0 && this->objectSizeLessThan == 0;
    }

    FAWSS3ControlLifecycleRuleAndOperator &fromAWS(const Aws::S3Control::Model::LifecycleRuleAndOperator &awsLifecycleRuleAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsLifecycleRuleAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3Control::Model::S3Tag& elem : awsLifecycleRuleAndOperator.GetTags()) {
            this->tags.Add(FS3ControlS3Tag().fromAWS(elem));
        }

        this->objectSizeGreaterThan = (int64)awsLifecycleRuleAndOperator.GetObjectSizeGreaterThan();

        this->objectSizeLessThan = (int64)awsLifecycleRuleAndOperator.GetObjectSizeLessThan();

        return *this;
    }
#endif
};
