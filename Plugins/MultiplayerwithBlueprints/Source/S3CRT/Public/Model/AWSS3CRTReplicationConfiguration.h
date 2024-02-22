/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ReplicationConfiguration.h"

#endif

#include "Model/AWSS3CRTReplicationRule.h"

#include "AWSS3CRTReplicationConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTReplicationConfiguration {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the AWS Identity and Access Management (IAM) role that Amazon S3 assumes when replicating objects. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/replication-how-setup.html">How to Set Up Replication</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString role;

    /**
    *  <p>A container for one or more replication rules. A replication configuration must have at least one rule and can contain a maximum of 1,000 rules. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTReplicationRule> rules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ReplicationConfiguration toAWS() const {
        Aws::S3Crt::Model::ReplicationConfiguration awsReplicationConfiguration;

        if (!(this->role.IsEmpty())) {
            awsReplicationConfiguration.SetRole(TCHAR_TO_UTF8(*this->role));
        }

        for (const FAWSS3CRTReplicationRule& elem : this->rules) {
            awsReplicationConfiguration.AddRules(elem.toAWS());
        }

        return awsReplicationConfiguration;
    }

    bool IsEmpty() const {
        return this->role.IsEmpty() && this->rules.Num() == 0;
    }

    FAWSS3CRTReplicationConfiguration &fromAWS(const Aws::S3Crt::Model::ReplicationConfiguration &awsReplicationConfiguration) {
        this->role = UTF8_TO_TCHAR(awsReplicationConfiguration.GetRole().c_str());

        this->rules.Empty();
        for (const Aws::S3Crt::Model::ReplicationRule& elem : awsReplicationConfiguration.GetRules()) {
            this->rules.Add(FAWSS3CRTReplicationRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
