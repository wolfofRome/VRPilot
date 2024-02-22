/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/LifecycleRuleFilter.h"

#endif

#include "Model/S3ControlS3Tag.h"
#include "Model/AWSS3ControlLifecycleRuleAndOperator.h"

#include "AWSS3ControlLifecycleRuleFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlLifecycleRuleFilter {
GENERATED_BODY()

    /**
    *  <p>Prefix identifying one or more objects to which the rule applies.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString prefix;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlS3Tag tag;

    /**
    *  <p>The container for the <code>AND</code> condition for the lifecycle rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlLifecycleRuleAndOperator andOperator;

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
    Aws::S3Control::Model::LifecycleRuleFilter toAWS() const {
        Aws::S3Control::Model::LifecycleRuleFilter awsLifecycleRuleFilter;

        if (!(this->prefix.IsEmpty())) {
            awsLifecycleRuleFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->tag.IsEmpty())) {
            awsLifecycleRuleFilter.SetTag(this->tag.toAWS());
        }

        if (!(this->andOperator.IsEmpty())) {
            awsLifecycleRuleFilter.SetAnd(this->andOperator.toAWS());
        }

        if (!(this->objectSizeGreaterThan == 0)) {
            awsLifecycleRuleFilter.SetObjectSizeGreaterThan(this->objectSizeGreaterThan);
        }

        if (!(this->objectSizeLessThan == 0)) {
            awsLifecycleRuleFilter.SetObjectSizeLessThan(this->objectSizeLessThan);
        }

        return awsLifecycleRuleFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tag.IsEmpty() && this->andOperator.IsEmpty() && this->objectSizeGreaterThan == 0 && this->objectSizeLessThan == 0;
    }

    FAWSS3ControlLifecycleRuleFilter &fromAWS(const Aws::S3Control::Model::LifecycleRuleFilter &awsLifecycleRuleFilter) {
        this->prefix = UTF8_TO_TCHAR(awsLifecycleRuleFilter.GetPrefix().c_str());

        this->tag.fromAWS(awsLifecycleRuleFilter.GetTag());

        this->andOperator.fromAWS(awsLifecycleRuleFilter.GetAnd());

        this->objectSizeGreaterThan = (int64)awsLifecycleRuleFilter.GetObjectSizeGreaterThan();

        this->objectSizeLessThan = (int64)awsLifecycleRuleFilter.GetObjectSizeLessThan();

        return *this;
    }
#endif
};
