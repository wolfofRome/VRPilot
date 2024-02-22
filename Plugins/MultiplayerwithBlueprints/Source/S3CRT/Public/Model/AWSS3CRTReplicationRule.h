/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ReplicationRule.h"

#endif

#include "Model/AWSS3CRTReplicationRuleFilter.h"
#include "Model/AWSS3CRTReplicationRuleStatus.h"
#include "Model/AWSS3CRTSourceSelectionCriteria.h"
#include "Model/AWSS3CRTExistingObjectReplication.h"
#include "Model/AWSS3CRTDestination.h"
#include "Model/AWSS3CRTDeleteMarkerReplication.h"

#include "AWSS3CRTReplicationRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTReplicationRule {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the rule. The maximum value is 255 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString iD;

    /**
    *  <p>The priority indicates which rule has precedence whenever two or more replication rules conflict. Amazon S3 will attempt to replicate objects according to all replication rules. However, if there are two or more rules with the same destination bucket, then objects will be replicated according to the rule with the highest priority. The higher the number, the higher the priority. </p> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/replication.html">Replication</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int priority = 0;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTReplicationRuleFilter filter;

    /**
    *  <p>Specifies whether the rule is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTReplicationRuleStatus status = EAWSS3CRTReplicationRuleStatus::NOT_SET;

    /**
    *  <p>A container that describes additional filters for identifying the source objects that you want to replicate. You can choose to enable or disable the replication of these objects. Currently, Amazon S3 supports only the filter that you can specify for objects created with server-side encryption using a customer master key (CMK) stored in AWS Key Management Service (SSE-KMS).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTSourceSelectionCriteria sourceSelectionCriteria;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTExistingObjectReplication existingObjectReplication;

    /**
    *  <p>A container for information about the replication destination and its configurations including enabling the S3 Replication Time Control (S3 RTC).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTDestination destination;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTDeleteMarkerReplication deleteMarkerReplication;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ReplicationRule toAWS() const {
        Aws::S3Crt::Model::ReplicationRule awsReplicationRule;

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
            case EAWSS3CRTReplicationRuleStatus::Enabled:
                awsReplicationRule.SetStatus(Aws::S3Crt::Model::ReplicationRuleStatus::Enabled);
                break;
            case EAWSS3CRTReplicationRuleStatus::Disabled:
                awsReplicationRule.SetStatus(Aws::S3Crt::Model::ReplicationRuleStatus::Disabled);
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
        return this->iD.IsEmpty() && this->priority == 0 && this->filter.IsEmpty() && this->status == EAWSS3CRTReplicationRuleStatus::NOT_SET && this->sourceSelectionCriteria.IsEmpty() && this->existingObjectReplication.IsEmpty() && this->destination.IsEmpty() && this->deleteMarkerReplication.IsEmpty();
    }

    FAWSS3CRTReplicationRule &fromAWS(const Aws::S3Crt::Model::ReplicationRule &awsReplicationRule) {
        this->iD = UTF8_TO_TCHAR(awsReplicationRule.GetID().c_str());

		this->priority = awsReplicationRule.GetPriority();

		this->filter = FAWSS3CRTReplicationRuleFilter().fromAWS(awsReplicationRule.GetFilter());

        switch(awsReplicationRule.GetStatus()) {
            case Aws::S3Crt::Model::ReplicationRuleStatus::NOT_SET:
                this->status = EAWSS3CRTReplicationRuleStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ReplicationRuleStatus::Enabled:
                this->status = EAWSS3CRTReplicationRuleStatus::Enabled;
                break;
            case Aws::S3Crt::Model::ReplicationRuleStatus::Disabled:
                this->status = EAWSS3CRTReplicationRuleStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTReplicationRuleStatus::NOT_SET;
                break;
        }

        this->sourceSelectionCriteria = FAWSS3CRTSourceSelectionCriteria().fromAWS(awsReplicationRule.GetSourceSelectionCriteria());

        this->existingObjectReplication = FAWSS3CRTExistingObjectReplication().fromAWS(awsReplicationRule.GetExistingObjectReplication());

        this->destination = FAWSS3CRTDestination().fromAWS(awsReplicationRule.GetDestination());

        this->deleteMarkerReplication = FAWSS3CRTDeleteMarkerReplication().fromAWS(awsReplicationRule.GetDeleteMarkerReplication());

        return *this;
    }
#endif
};
