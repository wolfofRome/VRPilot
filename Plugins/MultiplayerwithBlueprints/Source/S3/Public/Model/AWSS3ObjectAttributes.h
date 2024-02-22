/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ObjectAttributes.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ObjectAttributes : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ETag        UMETA(DisplayName = "etag"),
    Checksum        UMETA(DisplayName = "checksum"),
    ObjectParts        UMETA(DisplayName = "objectparts"),
    StorageClass        UMETA(DisplayName = "storageclass"),
    ObjectSize        UMETA(DisplayName = "objectsize"),
};
