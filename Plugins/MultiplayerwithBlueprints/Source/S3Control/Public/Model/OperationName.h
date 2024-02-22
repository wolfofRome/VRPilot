/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "OperationName.generated.h"

UENUM(BlueprintType)
enum class EAWSOperationName : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    LambdaInvoke        UMETA(DisplayName = "lambda invoke"),
    S3PutObjectCopy        UMETA(DisplayName = "s3 put object copy"),
    S3PutObjectAcl        UMETA(DisplayName = "s3 put object acl"),
    S3PutObjectTagging        UMETA(DisplayName = "s3 put object tagging"),
    S3DeleteObjectTagging        UMETA(DisplayName = "s3 delete object tagging"),
    S3InitiateRestoreObject        UMETA(DisplayName = "s3 initiate restore object"),
    S3PutObjectLegalHold        UMETA(DisplayName = "s3 put object legal hold"),
    S3PutObjectRetention        UMETA(DisplayName = "s3 put object retention"),
    S3ReplicateObject        UMETA(DisplayName = "s3replicateobject"),
};
