/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "InventoryOptionalField.generated.h"

UENUM(BlueprintType)
enum class EAWSInventoryOptionalField : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Size        UMETA(DisplayName = "size"),
    LastModifiedDate        UMETA(DisplayName = "lastmodifieddate"),
    StorageClass        UMETA(DisplayName = "storageclass"),
    ETag        UMETA(DisplayName = "etag"),
    IsMultipartUploaded        UMETA(DisplayName = "ismultipartuploaded"),
    ReplicationStatus        UMETA(DisplayName = "replicationstatus"),
    EncryptionStatus        UMETA(DisplayName = "encryptionstatus"),
    ObjectLockRetainUntilDate        UMETA(DisplayName = "objectlockretainuntildate"),
    ObjectLockMode        UMETA(DisplayName = "objectlockmode"),
    ObjectLockLegalHoldStatus        UMETA(DisplayName = "objectlocklegalholdstatus"),
    IntelligentTieringAccessTier        UMETA(DisplayName = "intelligenttieringaccesstier"),
    BucketKeyStatus        UMETA(DisplayName = "bucketkeystatus"),
    ChecksumAlgorithm        UMETA(DisplayName = "checksumalgorithm"),
};
