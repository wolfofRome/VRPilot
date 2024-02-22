/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/LifecycleRule.h"

#endif

#include "Model/LifecycleExpiration.h"
#include "Model/LifecycleRuleFilter.h"
#include "Model/ExpirationStatus.h"
#include "Model/Transition.h"
#include "Model/NoncurrentVersionTransition.h"
#include "Model/NoncurrentVersionExpiration.h"
#include "Model/AbortIncompleteMultipartUpload.h"

#include "LifecycleRule.generated.h"

USTRUCT(BlueprintType)
struct FLifecycleRule {
GENERATED_BODY()

    /**
    *  <p>Specifies the expiration for the lifecycle of the object in the form of date, days and, whether the object has a delete marker.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FLifecycleExpiration expiration;

    /**
    *  <p>Unique identifier for the rule. The value cannot be longer than 255 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString iD;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FLifecycleRuleFilter filter;

    /**
    *  <p>If 'Enabled', the rule is currently being applied. If 'Disabled', the rule is not currently being applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSExpirationStatus status = EAWSExpirationStatus::NOT_SET;

    /**
    *  <p>Specifies when an Amazon S3 object transitions to a specified storage class.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FTransition> transitions;

    /**
    *  <p> Specifies the transition rule for the lifecycle rule that describes when noncurrent objects transition to a specific storage class. If your bucket is versioning-enabled (or versioning is suspended), you can set this action to request that Amazon S3 transition noncurrent object versions to a specific storage class at a set period in the object's lifetime. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FNoncurrentVersionTransition> noncurrentVersionTransitions;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FNoncurrentVersionExpiration noncurrentVersionExpiration;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAbortIncompleteMultipartUpload abortIncompleteMultipartUpload;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::LifecycleRule toAWS() const {
        Aws::S3::Model::LifecycleRule awsLifecycleRule;

        if (!(this->expiration.IsEmpty())) {
            awsLifecycleRule.SetExpiration(this->expiration.toAWS());
        }

		if (!(this->iD.IsEmpty())) {
            awsLifecycleRule.SetID(TCHAR_TO_UTF8(*this->iD));
        }

        if (!(this->filter.IsEmpty())) {
            awsLifecycleRule.SetFilter(this->filter.toAWS());
        }

        switch(this->status) {
            case EAWSExpirationStatus::Enabled:
                awsLifecycleRule.SetStatus(Aws::S3::Model::ExpirationStatus::Enabled);
                break;
            case EAWSExpirationStatus::Disabled:
                awsLifecycleRule.SetStatus(Aws::S3::Model::ExpirationStatus::Disabled);
                break;
            default:
                break;
        }

        for (const FTransition& elem : this->transitions) {
            awsLifecycleRule.AddTransitions(elem.toAWS());
        }

        for (const FNoncurrentVersionTransition& elem : this->noncurrentVersionTransitions) {
            awsLifecycleRule.AddNoncurrentVersionTransitions(elem.toAWS());
        }

        if (!(this->noncurrentVersionExpiration.IsEmpty())) {
            awsLifecycleRule.SetNoncurrentVersionExpiration(this->noncurrentVersionExpiration.toAWS());
        }

        if (!(this->abortIncompleteMultipartUpload.IsEmpty())) {
            awsLifecycleRule.SetAbortIncompleteMultipartUpload(this->abortIncompleteMultipartUpload.toAWS());
        }

        return awsLifecycleRule;
    }

    bool IsEmpty() const {
        return this->expiration.IsEmpty() && this->iD.IsEmpty() && this->filter.IsEmpty() && status == EAWSExpirationStatus::NOT_SET && this->transitions.Num() == 0 && this->noncurrentVersionTransitions.Num() == 0 && this->noncurrentVersionExpiration.IsEmpty() && this->abortIncompleteMultipartUpload.IsEmpty();
    }

    FLifecycleRule &fromAWS(const Aws::S3::Model::LifecycleRule &awsLifecycleRule) {
        this->expiration.fromAWS(awsLifecycleRule.GetExpiration());

        this->iD = UTF8_TO_TCHAR(awsLifecycleRule.GetID().c_str());

        this->filter.fromAWS(awsLifecycleRule.GetFilter());

        switch(awsLifecycleRule.GetStatus()) {
            case Aws::S3::Model::ExpirationStatus::NOT_SET:
                this->status = EAWSExpirationStatus::NOT_SET;
                break;
            case Aws::S3::Model::ExpirationStatus::Enabled:
                this->status = EAWSExpirationStatus::Enabled;
                break;
            case Aws::S3::Model::ExpirationStatus::Disabled:
                this->status = EAWSExpirationStatus::Disabled;
                break;
            default:
                this->status = EAWSExpirationStatus::NOT_SET;
                break;
        }

        this->transitions.Empty();
        for (const Aws::S3::Model::Transition& elem : awsLifecycleRule.GetTransitions()) {
            this->transitions.Add(FTransition().fromAWS(elem));
        }

        this->noncurrentVersionTransitions.Empty();
        for (const Aws::S3::Model::NoncurrentVersionTransition& elem : awsLifecycleRule.GetNoncurrentVersionTransitions()) {
            this->noncurrentVersionTransitions.Add(FNoncurrentVersionTransition().fromAWS(elem));
        }

        this->noncurrentVersionExpiration.fromAWS(awsLifecycleRule.GetNoncurrentVersionExpiration());

        this->abortIncompleteMultipartUpload.fromAWS(awsLifecycleRule.GetAbortIncompleteMultipartUpload());

        return *this;
    }
#endif
};
