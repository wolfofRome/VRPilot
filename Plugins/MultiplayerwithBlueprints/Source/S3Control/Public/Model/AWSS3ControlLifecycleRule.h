/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/LifecycleRule.h"

#endif

#include "Model/AWSS3ControlLifecycleExpiration.h"
#include "Model/AWSS3ControlLifecycleRuleFilter.h"
#include "Model/AWSS3ControlExpirationStatus.h"
#include "Model/AWSS3ControlTransition.h"
#include "Model/AWSS3ControlNoncurrentVersionTransition.h"
#include "Model/AWSS3ControlNoncurrentVersionExpiration.h"
#include "Model/AWSS3ControlAbortIncompleteMultipartUpload.h"

#include "AWSS3ControlLifecycleRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlLifecycleRule {
GENERATED_BODY()

    /**
    *  <p>Specifies the expiration for the lifecycle of the object in the form of date, days and, whether the object has a delete marker.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlLifecycleExpiration expiration;

    /**
    *  <p>Unique identifier for the rule. The value cannot be longer than 255 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString iD;

    /**
    *  <p>The container for the filter of lifecycle rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlLifecycleRuleFilter filter;

    /**
    *  <p>If 'Enabled', the rule is currently being applied. If 'Disabled', the rule is not currently being applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlExpirationStatus status = EAWSS3ControlExpirationStatus::NOT_SET;

    /**
    *  <p>Specifies when an Amazon S3 object transitions to a specified storage class.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlTransition> transitions;

    /**
    *  <p> Specifies the transition rule for the lifecycle rule that describes when noncurrent objects transition to a specific storage class. If your bucket is versioning-enabled (or versioning is suspended), you can set this action to request that Amazon S3 transition noncurrent object versions to a specific storage class at a set period in the object's lifetime. </p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlNoncurrentVersionTransition> noncurrentVersionTransitions;

    /**
    *  <p>The noncurrent version expiration of the lifecycle rule.</p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlNoncurrentVersionExpiration noncurrentVersionExpiration;

    /**
    *  <p>Specifies the days since the initiation of an incomplete multipart upload that Amazon S3 waits before permanently removing all parts of the upload. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/mpuoverview.html#mpu-abort-incomplete-mpu-lifecycle-config"> Aborting Incomplete Multipart Uploads Using a Bucket Lifecycle Policy</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAbortIncompleteMultipartUpload abortIncompleteMultipartUpload;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::LifecycleRule toAWS() const {
        Aws::S3Control::Model::LifecycleRule awsLifecycleRule;

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
            case EAWSS3ControlExpirationStatus::Enabled:
                awsLifecycleRule.SetStatus(Aws::S3Control::Model::ExpirationStatus::Enabled);
                break;
            case EAWSS3ControlExpirationStatus::Disabled:
                awsLifecycleRule.SetStatus(Aws::S3Control::Model::ExpirationStatus::Disabled);
                break;
            default:
                break;
        }

        for (const FAWSS3ControlTransition& elem : this->transitions) {
            awsLifecycleRule.AddTransitions(elem.toAWS());
        }

        for (const FAWSS3ControlNoncurrentVersionTransition& elem : this->noncurrentVersionTransitions) {
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
        return this->expiration.IsEmpty() && this->iD.IsEmpty() && this->filter.IsEmpty() && this->status == EAWSS3ControlExpirationStatus::NOT_SET && this->transitions.Num() == 0 && this->noncurrentVersionTransitions.Num() == 0 && this->noncurrentVersionExpiration.IsEmpty() && this->abortIncompleteMultipartUpload.IsEmpty();
    }

    FAWSS3ControlLifecycleRule &fromAWS(const Aws::S3Control::Model::LifecycleRule &awsLifecycleRule) {
        this->expiration.fromAWS(awsLifecycleRule.GetExpiration());

        this->iD = UTF8_TO_TCHAR(awsLifecycleRule.GetID().c_str());

        this->filter.fromAWS(awsLifecycleRule.GetFilter());

        switch(awsLifecycleRule.GetStatus()) {
            case Aws::S3Control::Model::ExpirationStatus::NOT_SET:
                this->status = EAWSS3ControlExpirationStatus::NOT_SET;
                break;
            case Aws::S3Control::Model::ExpirationStatus::Enabled:
                this->status = EAWSS3ControlExpirationStatus::Enabled;
                break;
            case Aws::S3Control::Model::ExpirationStatus::Disabled:
                this->status = EAWSS3ControlExpirationStatus::Disabled;
                break;
            default:
                this->status = EAWSS3ControlExpirationStatus::NOT_SET;
                break;
        }

        this->transitions.Empty();
        for (const Aws::S3Control::Model::Transition& elem : awsLifecycleRule.GetTransitions()) {
            this->transitions.Add(FAWSS3ControlTransition().fromAWS(elem));
        }

        this->noncurrentVersionTransitions.Empty();
        for (const Aws::S3Control::Model::NoncurrentVersionTransition& elem : awsLifecycleRule.GetNoncurrentVersionTransitions()) {
            this->noncurrentVersionTransitions.Add(FAWSS3ControlNoncurrentVersionTransition().fromAWS(elem));
        }

        this->noncurrentVersionExpiration.fromAWS(awsLifecycleRule.GetNoncurrentVersionExpiration());

        this->abortIncompleteMultipartUpload.fromAWS(awsLifecycleRule.GetAbortIncompleteMultipartUpload());

        return *this;
    }
#endif
};
