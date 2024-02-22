/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/LifecycleRuleFilter.h"

#endif

#include "Model/AWSS3CRTTag.h"
#include "Model/AWSS3CRTLifecycleRuleAndOperator.h"

#include "AWSS3CRTLifecycleRuleFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTLifecycleRuleFilter {
GENERATED_BODY()

    /**
    *  <p>Prefix identifying one or more objects to which the rule applies.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>This tag must exist in the object's tag set in order for the rule to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTTag tag;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTLifecycleRuleAndOperator andOperator;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::LifecycleRuleFilter toAWS() const {
        Aws::S3Crt::Model::LifecycleRuleFilter awsLifecycleRuleFilter;

        if (!(this->prefix.IsEmpty())) {
            awsLifecycleRuleFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->tag.IsEmpty())) {
            awsLifecycleRuleFilter.SetTag(this->tag.toAWS());
        }

        if (!(this->andOperator.IsEmpty())) {
            awsLifecycleRuleFilter.SetAnd(this->andOperator.toAWS());
        }

        return awsLifecycleRuleFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tag.IsEmpty() && this->andOperator.IsEmpty();
    }

    FAWSS3CRTLifecycleRuleFilter &fromAWS(const Aws::S3Crt::Model::LifecycleRuleFilter &awsLifecycleRuleFilter) {
        this->prefix = UTF8_TO_TCHAR(awsLifecycleRuleFilter.GetPrefix().c_str());

        this->tag = FAWSS3CRTTag().fromAWS(awsLifecycleRuleFilter.GetTag());

        this->andOperator = FAWSS3CRTLifecycleRuleAndOperator().fromAWS(awsLifecycleRuleFilter.GetAnd());

        return *this;
    }
#endif
};
