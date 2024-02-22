/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/LifecycleRule.h"

#endif

#include "Model/AWSS3CRTLifecycleExpiration.h"
#include "Model/AWSS3CRTLifecycleRuleFilter.h"
#include "Model/AWSS3CRTExpirationStatus.h"
#include "Model/AWSS3CRTTransition.h"
#include "Model/AWSS3CRTNoncurrentVersionTransition.h"
#include "Model/AWSS3CRTNoncurrentVersionExpiration.h"
#include "Model/AWSS3CRTAbortIncompleteMultipartUpload.h"

#include "AWSS3CRTLifecycleRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTLifecycleRule {
GENERATED_BODY()

    /**
    *  <p>Specifies the expiration for the lifecycle of the object in the form of date, days and, whether the object has a delete marker.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTLifecycleExpiration expiration;

    /**
    *  <p>Unique identifier for the rule. The value cannot be longer than 255 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString iD;

    /**
    *  <p>The <code>Filter</code> is used to identify objects that a Lifecycle Rule applies to. A <code>Filter</code> must have exactly one of <code>Prefix</code>, <code>Tag</code>, or <code>And</code> specified. <code>Filter</code> is required if the <code>LifecycleRule</code> does not containt a <code>Prefix</code> element.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTLifecycleRuleFilter filter;

    /**
    *  <p>If 'Enabled', the rule is currently being applied. If 'Disabled', the rule is not currently being applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTExpirationStatus status = EAWSS3CRTExpirationStatus::NOT_SET;

    /**
    *  <p>Specifies when an Amazon S3 object transitions to a specified storage class.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTransition> transitions;

    /**
    *  <p> Specifies the transition rule for the lifecycle rule that describes when noncurrent objects transition to a specific storage class. If your bucket is versioning-enabled (or versioning is suspended), you can set this action to request that Amazon S3 transition noncurrent object versions to a specific storage class at a set period in the object's lifetime. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTNoncurrentVersionTransition> noncurrentVersionTransitions;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTNoncurrentVersionExpiration noncurrentVersionExpiration;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAbortIncompleteMultipartUpload abortIncompleteMultipartUpload;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::LifecycleRule toAWS() const {
        Aws::S3Crt::Model::LifecycleRule awsLifecycleRule;

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
            case EAWSS3CRTExpirationStatus::Enabled:
                awsLifecycleRule.SetStatus(Aws::S3Crt::Model::ExpirationStatus::Enabled);
                break;
            case EAWSS3CRTExpirationStatus::Disabled:
                awsLifecycleRule.SetStatus(Aws::S3Crt::Model::ExpirationStatus::Disabled);
                break;
            default:
                break;
        }

        for (const FAWSS3CRTTransition& elem : this->transitions) {
            awsLifecycleRule.AddTransitions(elem.toAWS());
        }

        for (const FAWSS3CRTNoncurrentVersionTransition& elem : this->noncurrentVersionTransitions) {
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
        return this->expiration.IsEmpty() && this->iD.IsEmpty() && this->filter.IsEmpty() && this->status == EAWSS3CRTExpirationStatus::NOT_SET && this->transitions.Num() == 0 && this->noncurrentVersionTransitions.Num() == 0 && this->noncurrentVersionExpiration.IsEmpty() && this->abortIncompleteMultipartUpload.IsEmpty();
    }

    FAWSS3CRTLifecycleRule &fromAWS(const Aws::S3Crt::Model::LifecycleRule &awsLifecycleRule) {
        this->expiration = FAWSS3CRTLifecycleExpiration().fromAWS(awsLifecycleRule.GetExpiration());

        this->iD = UTF8_TO_TCHAR(awsLifecycleRule.GetID().c_str());

        this->filter = FAWSS3CRTLifecycleRuleFilter().fromAWS(awsLifecycleRule.GetFilter());

        switch(awsLifecycleRule.GetStatus()) {
            case Aws::S3Crt::Model::ExpirationStatus::NOT_SET:
                this->status = EAWSS3CRTExpirationStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::ExpirationStatus::Enabled:
                this->status = EAWSS3CRTExpirationStatus::Enabled;
                break;
            case Aws::S3Crt::Model::ExpirationStatus::Disabled:
                this->status = EAWSS3CRTExpirationStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTExpirationStatus::NOT_SET;
                break;
        }

        this->transitions.Empty();
        for (const Aws::S3Crt::Model::Transition& elem : awsLifecycleRule.GetTransitions()) {
            this->transitions.Add(FAWSS3CRTTransition().fromAWS(elem));
        }

        this->noncurrentVersionTransitions.Empty();
        for (const Aws::S3Crt::Model::NoncurrentVersionTransition& elem : awsLifecycleRule.GetNoncurrentVersionTransitions()) {
            this->noncurrentVersionTransitions.Add(FAWSS3CRTNoncurrentVersionTransition().fromAWS(elem));
        }

        this->noncurrentVersionExpiration = FAWSS3CRTNoncurrentVersionExpiration().fromAWS(awsLifecycleRule.GetNoncurrentVersionExpiration());

        this->abortIncompleteMultipartUpload = FAWSS3CRTAbortIncompleteMultipartUpload().fromAWS(awsLifecycleRule.GetAbortIncompleteMultipartUpload());

        return *this;
    }
#endif
};
