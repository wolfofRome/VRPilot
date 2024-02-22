/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/IntelligentTieringFilter.h"

#endif

#include "Model/AWSS3CRTTag.h"
#include "Model/AWSS3CRTIntelligentTieringAndOperator.h"

#include "AWSS3CRTIntelligentTieringFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTIntelligentTieringFilter {
GENERATED_BODY()

    /**
    *  <p>An object key name prefix that identifies the subset of objects to which the rule applies.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTTag tag;

    /**
    *  <p>A conjunction (logical AND) of predicates, which is used in evaluating a metrics filter. The operator must have at least two predicates, and an object must match all of the predicates in order for the filter to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTIntelligentTieringAndOperator andOperator;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::IntelligentTieringFilter toAWS() const {
        Aws::S3Crt::Model::IntelligentTieringFilter awsIntelligentTieringFilter;

        if (!(this->prefix.IsEmpty())) {
            awsIntelligentTieringFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->tag.IsEmpty())) {
            awsIntelligentTieringFilter.SetTag(this->tag.toAWS());
        }

        if (!(this->andOperator.IsEmpty())) {
            awsIntelligentTieringFilter.SetAnd(this->andOperator.toAWS());
        }

        return awsIntelligentTieringFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tag.IsEmpty() && this->andOperator.IsEmpty();
    }

    FAWSS3CRTIntelligentTieringFilter &fromAWS(const Aws::S3Crt::Model::IntelligentTieringFilter &awsIntelligentTieringFilter) {
        this->prefix = UTF8_TO_TCHAR(awsIntelligentTieringFilter.GetPrefix().c_str());

        this->tag = FAWSS3CRTTag().fromAWS(awsIntelligentTieringFilter.GetTag());

        this->andOperator = FAWSS3CRTIntelligentTieringAndOperator().fromAWS(awsIntelligentTieringFilter.GetAnd());

        return *this;
    }
#endif
};
