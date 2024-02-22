/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTInventoryOptionalField.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTInventoryOptionalField : uint8 {
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
};
