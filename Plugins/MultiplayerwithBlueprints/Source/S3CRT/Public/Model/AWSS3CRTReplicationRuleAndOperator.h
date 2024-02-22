/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ReplicationRuleAndOperator.h"

#endif

#include "Model/AWSS3CRTTag.h"

#include "AWSS3CRTReplicationRuleAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTReplicationRuleAndOperator {
GENERATED_BODY()

    /**
    *  <p>An object key name prefix that identifies the subset of objects to which the rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>An array of tags containing key and value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTag> tags;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ReplicationRuleAndOperator toAWS() const {
        Aws::S3Crt::Model::ReplicationRuleAndOperator awsReplicationRuleAndOperator;

        if (!(this->prefix.IsEmpty())) {
            awsReplicationRuleAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FAWSS3CRTTag& elem : this->tags) {
            awsReplicationRuleAndOperator.AddTags(elem.toAWS());
        }

        return awsReplicationRuleAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0;
    }

    FAWSS3CRTReplicationRuleAndOperator &fromAWS(const Aws::S3Crt::Model::ReplicationRuleAndOperator &awsReplicationRuleAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsReplicationRuleAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3Crt::Model::Tag& elem : awsReplicationRuleAndOperator.GetTags()) {
            this->tags.Add(FAWSS3CRTTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
