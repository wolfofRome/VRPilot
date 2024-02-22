/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/IntelligentTieringFilter.h"

#endif

#include "Model/S3Tag.h"
#include "Model/AWSS3IntelligentTieringAndOperator.h"

#include "AWSS3IntelligentTieringFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3IntelligentTieringFilter {
GENERATED_BODY()

    /**
    *  <p>An object key name prefix that identifies the subset of objects to which the rule applies.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Tag tag;

    /**
    *  <p>A conjunction (logical AND) of predicates, which is used in evaluating a metrics filter. The operator must have at least two predicates, and an object must match all of the predicates in order for the filter to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3IntelligentTieringAndOperator andOperator;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::IntelligentTieringFilter toAWS() const {
        Aws::S3::Model::IntelligentTieringFilter awsIntelligentTieringFilter;

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

    FAWSS3IntelligentTieringFilter &fromAWS(const Aws::S3::Model::IntelligentTieringFilter &awsIntelligentTieringFilter) {
        this->prefix = UTF8_TO_TCHAR(awsIntelligentTieringFilter.GetPrefix().c_str());

        this->tag.fromAWS(awsIntelligentTieringFilter.GetTag());

        this->andOperator.fromAWS(awsIntelligentTieringFilter.GetAnd());

        return *this;
    }
#endif
};
