/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Rule.h"

#endif

#include "Model/LifecycleExpiration.h"
#include "Model/ExpirationStatus.h"
#include "Model/Transition.h"
#include "Model/NoncurrentVersionTransition.h"
#include "Model/NoncurrentVersionExpiration.h"
#include "Model/AbortIncompleteMultipartUpload.h"

#include "S3Rule.generated.h"

USTRUCT(BlueprintType)
struct FS3Rule {
GENERATED_BODY()

    /**
     * <p>Specifies the expiration for the lifecycle of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FLifecycleExpiration expiration;

    /**
     * <p>Unique identifier for the rule. The value can't be longer than 255 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
     * <p>Object key prefix that identifies one or more objects to which this rule applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString prefix;

    /**
     * <p>If <code>Enabled</code>, the rule is currently being applied. If <code>Disabled</code>, the rule is not currently being applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSExpirationStatus status = EAWSExpirationStatus::NOT_SET;

    /**
     * <p>Specifies when an object transitions to a specified storage class. For more information about Amazon S3 lifecycle configuration rules, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/lifecycle-transition-general-considerations.html">Transitioning Objects Using Amazon S3 Lifecycle</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FTransition transition;

    /**
     *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FNoncurrentVersionTransition noncurrentVersionTransition;

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
#endif
};
