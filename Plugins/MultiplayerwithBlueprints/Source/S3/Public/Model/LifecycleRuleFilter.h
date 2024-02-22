/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/LifecycleRuleFilter.h"

#endif

#include "Model/S3Tag.h"
#include "Model/LifecycleRuleAndOperator.h"

#include "LifecycleRuleFilter.generated.h"

USTRUCT(BlueprintType)
struct FLifecycleRuleFilter {
GENERATED_BODY()

    /**
    *  <p>Prefix identifying one or more objects to which the rule applies.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>This tag must exist in the object's tag set in order for the rule to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Tag tag;

    /**
    *  <p>Minimum object size to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 objectSizeGreaterThan = 0;

    /**
    *  <p>Maximum object size to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int64 objectSizeLessThan = 0;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FLifecycleRuleAndOperator andOperator;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::LifecycleRuleFilter toAWS() const {
        Aws::S3::Model::LifecycleRuleFilter awsLifecycleRuleFilter;

		if (!(this->prefix.IsEmpty())) {
            awsLifecycleRuleFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->tag.IsEmpty())) {
            awsLifecycleRuleFilter.SetTag(this->tag.toAWS());
        }

        if (!(this->objectSizeGreaterThan == 0)) {
            awsLifecycleRuleFilter.SetObjectSizeGreaterThan(this->objectSizeGreaterThan);
        }

        if (!(this->objectSizeLessThan == 0)) {
            awsLifecycleRuleFilter.SetObjectSizeLessThan(this->objectSizeLessThan);
        }

        if (!(this->andOperator.IsEmpty())) {
            awsLifecycleRuleFilter.SetAnd(this->andOperator.toAWS());
        }

        return awsLifecycleRuleFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tag.IsEmpty() && this->objectSizeGreaterThan == 0 && this->objectSizeLessThan == 0 && this->andOperator.IsEmpty();
    }

    FLifecycleRuleFilter &fromAWS(const Aws::S3::Model::LifecycleRuleFilter &awsLifecycleRuleFilter) {
        this->prefix = UTF8_TO_TCHAR(awsLifecycleRuleFilter.GetPrefix().c_str());

        this->tag.fromAWS(awsLifecycleRuleFilter.GetTag());

        this->objectSizeGreaterThan = (int64)awsLifecycleRuleFilter.GetObjectSizeGreaterThan();

        this->objectSizeLessThan = (int64)awsLifecycleRuleFilter.GetObjectSizeLessThan();

        this->andOperator.fromAWS(awsLifecycleRuleFilter.GetAnd());

        return *this;
    }
#endif
};
