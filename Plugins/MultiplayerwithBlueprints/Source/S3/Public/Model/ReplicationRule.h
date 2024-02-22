/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ReplicationRule.h"

#endif

#include "Model/ReplicationRuleFilter.h"
#include "Model/ReplicationRuleStatus.h"
#include "Model/SourceSelectionCriteria.h"
#include "Model/ExistingObjectReplication.h"
#include "Model/S3Destination.h"
#include "Model/DeleteMarkerReplication.h"

#include "ReplicationRule.generated.h"

USTRUCT(BlueprintType)
struct FReplicationRule {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the rule. The maximum value is 255 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString iD;

    /**
    *  <p>The priority associated with the rule. If you specify multiple rules in a replication configuration, Amazon S3 prioritizes the rules to prevent conflicts when filtering. If two or more rules identify the same object based on a specified filter, the rule with higher priority takes precedence. For example:</p> <ul> <li> <p>Same object quality prefix-based filter criteria if prefixes you specified in multiple rules overlap </p> </li> <li> <p>Same object qualify tag-based filter criteria specified in multiple rules</p> </li> </ul> <p>For more information, see <a href=" https://docs.aws.amazon.com/AmazonS3/latest/dev/replication.html">Replication</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int priority = 0;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FReplicationRuleFilter filter;

    /**
    *  <p>Specifies whether the rule is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSReplicationRuleStatus status = EAWSReplicationRuleStatus::NOT_SET;

    /**
    *  <p>A container that describes additional filters for identifying the source objects that you want to replicate. You can choose to enable or disable the replication of these objects. Currently, Amazon S3 supports only the filter that you can specify for objects created with server-side encryption using a customer master key (CMK) stored in AWS Key Management Service (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FSourceSelectionCriteria sourceSelectionCriteria;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FExistingObjectReplication existingObjectReplication;

    /**
    *  <p>A container for information about the replication destination and its configurations including enabling the S3 Replication Time Control (S3 RTC).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Destination destination;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FDeleteMarkerReplication deleteMarkerReplication;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ReplicationRule toAWS() const {
        Aws::S3::Model::ReplicationRule awsReplicationRule;

		if (!(this->iD.IsEmpty())) {
            awsReplicationRule.SetID(TCHAR_TO_UTF8(*this->iD));
        }

        if (!(this->priority == 0)) {
            awsReplicationRule.SetPriority(this->priority);
        }

        if (!(this->filter.IsEmpty())) {
            awsReplicationRule.SetFilter(this->filter.toAWS());
        }

        switch(this->status) {
            case EAWSReplicationRuleStatus::Enabled:
                awsReplicationRule.SetStatus(Aws::S3::Model::ReplicationRuleStatus::Enabled);
                break;
            case EAWSReplicationRuleStatus::Disabled:
                awsReplicationRule.SetStatus(Aws::S3::Model::ReplicationRuleStatus::Disabled);
                break;
            default:
                break;
        }

        if (!(this->sourceSelectionCriteria.IsEmpty())) {
            awsReplicationRule.SetSourceSelectionCriteria(this->sourceSelectionCriteria.toAWS());
        }

        if (!(this->existingObjectReplication.IsEmpty())) {
            awsReplicationRule.SetExistingObjectReplication(this->existingObjectReplication.toAWS());
        }

        if (!(this->destination.IsEmpty())) {
            awsReplicationRule.SetDestination(this->destination.toAWS());
        }

        if (!(this->deleteMarkerReplication.IsEmpty())) {
            awsReplicationRule.SetDeleteMarkerReplication(this->deleteMarkerReplication.toAWS());
        }

        return awsReplicationRule;
    }

    bool IsEmpty() const {
        return this->iD.IsEmpty() && this->priority == 0 && this->filter.IsEmpty() && status == EAWSReplicationRuleStatus::NOT_SET && this->sourceSelectionCriteria.IsEmpty() && this->existingObjectReplication.IsEmpty() && this->destination.IsEmpty() && this->deleteMarkerReplication.IsEmpty();
    }

    FReplicationRule &fromAWS(const Aws::S3::Model::ReplicationRule &awsReplicationRule) {
        this->iD = UTF8_TO_TCHAR(awsReplicationRule.GetID().c_str());

		this->priority = awsReplicationRule.GetPriority();

		this->filter.fromAWS(awsReplicationRule.GetFilter());

        switch(awsReplicationRule.GetStatus()) {
            case Aws::S3::Model::ReplicationRuleStatus::NOT_SET:
                this->status = EAWSReplicationRuleStatus::NOT_SET;
                break;
            case Aws::S3::Model::ReplicationRuleStatus::Enabled:
                this->status = EAWSReplicationRuleStatus::Enabled;
                break;
            case Aws::S3::Model::ReplicationRuleStatus::Disabled:
                this->status = EAWSReplicationRuleStatus::Disabled;
                break;
            default:
                this->status = EAWSReplicationRuleStatus::NOT_SET;
                break;
        }

        this->sourceSelectionCriteria.fromAWS(awsReplicationRule.GetSourceSelectionCriteria());

        this->existingObjectReplication.fromAWS(awsReplicationRule.GetExistingObjectReplication());

        this->destination.fromAWS(awsReplicationRule.GetDestination());

        this->deleteMarkerReplication.fromAWS(awsReplicationRule.GetDeleteMarkerReplication());

        return *this;
    }
#endif
};
