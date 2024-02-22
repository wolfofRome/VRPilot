/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Rule.h"

#endif

#include "Model/AWSS3CRTLifecycleExpiration.h"
#include "Model/AWSS3CRTExpirationStatus.h"
#include "Model/AWSS3CRTTransition.h"
#include "Model/AWSS3CRTNoncurrentVersionTransition.h"
#include "Model/AWSS3CRTNoncurrentVersionExpiration.h"
#include "Model/AWSS3CRTAbortIncompleteMultipartUpload.h"

#include "AWSS3CRTRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTRule {
GENERATED_BODY()

    /**
     * <p>Specifies the expiration for the lifecycle of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTLifecycleExpiration expiration;

    /**
     * <p>Unique identifier for the rule. The value can't be longer than 255 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
     * <p>Object key prefix that identifies one or more objects to which this rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
     * <p>If <code>Enabled</code>, the rule is currently being applied. If <code>Disabled</code>, the rule is not currently being applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTExpirationStatus status = EAWSS3CRTExpirationStatus::NOT_SET;

    /**
     * <p>Specifies when an object transitions to a specified storage class. For more information about Amazon S3 lifecycle configuration rules, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/lifecycle-transition-general-considerations.html">Transitioning Objects Using Amazon S3 Lifecycle</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTTransition transition;

    /**
     *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTNoncurrentVersionTransition noncurrentVersionTransition;

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
#endif
};
