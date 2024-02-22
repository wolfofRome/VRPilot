/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ReplicationRuleAndOperator.h"

#endif

#include "Model/S3Tag.h"

#include "ReplicationRuleAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FReplicationRuleAndOperator {
GENERATED_BODY()

    /**
    *  <p>An object key name prefix that identifies the subset of objects to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
    *  <p>An array of tags containing key and value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FS3Tag> tags;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ReplicationRuleAndOperator toAWS() const {
        Aws::S3::Model::ReplicationRuleAndOperator awsReplicationRuleAndOperator;

		if (!(this->prefix.IsEmpty())) {
            awsReplicationRuleAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FS3Tag& elem : this->tags) {
            awsReplicationRuleAndOperator.AddTags(elem.toAWS());
        }

        return awsReplicationRuleAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0;
    }

    FReplicationRuleAndOperator &fromAWS(const Aws::S3::Model::ReplicationRuleAndOperator &awsReplicationRuleAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsReplicationRuleAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3::Model::Tag& elem : awsReplicationRuleAndOperator.GetTags()) {
            this->tags.Add(FS3Tag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
