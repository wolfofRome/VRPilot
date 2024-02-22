/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ReplicationRuleFilter.h"

#endif

#include "Model/S3Tag.h"
#include "Model/ReplicationRuleAndOperator.h"

#include "ReplicationRuleFilter.generated.h"

USTRUCT(BlueprintType)
struct FReplicationRuleFilter {
GENERATED_BODY()

    /**
    *  <p>An object key name prefix that identifies the subset of objects to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>A container for specifying a tag key and value. </p> <p>The rule applies only to objects that have the tag in their tag set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Tag tag;

    /**
    *  <p>A container for specifying rule filters. The filters determine the subset of objects to which the rule applies. This element is required only if you specify more than one filter. For example: </p> <ul> <li> <p>If you specify both a <code>Prefix</code> and a <code>Tag</code> filter, wrap these filters in an <code>And</code> tag.</p> </li> <li> <p>If you specify a filter based on multiple tags, wrap the <code>Tag</code> elements in an <code>And</code> tag.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FReplicationRuleAndOperator andOperator;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ReplicationRuleFilter toAWS() const {
        Aws::S3::Model::ReplicationRuleFilter awsReplicationRuleFilter;

		if (!(this->prefix.IsEmpty())) {
            awsReplicationRuleFilter.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        if (!(this->tag.IsEmpty())) {
            awsReplicationRuleFilter.SetTag(this->tag.toAWS());
        }

        if (!(this->andOperator.IsEmpty())) {
            awsReplicationRuleFilter.SetAnd(this->andOperator.toAWS());
        }

        return awsReplicationRuleFilter;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tag.IsEmpty() && this->andOperator.IsEmpty();
    }

    FReplicationRuleFilter &fromAWS(const Aws::S3::Model::ReplicationRuleFilter &awsReplicationRuleFilter) {
        this->prefix = UTF8_TO_TCHAR(awsReplicationRuleFilter.GetPrefix().c_str());

        this->tag.fromAWS(awsReplicationRuleFilter.GetTag());

        this->andOperator.fromAWS(awsReplicationRuleFilter.GetAnd());

        return *this;
    }
#endif
};
