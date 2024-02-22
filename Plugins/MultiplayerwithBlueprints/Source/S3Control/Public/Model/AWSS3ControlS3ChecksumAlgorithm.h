/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlS3ChecksumAlgorithm.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlS3ChecksumAlgorithm : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CRC32        UMETA(DisplayName = "crc32"),
    CRC32C        UMETA(DisplayName = "crc32c"),
    SHA1        UMETA(DisplayName = "sha1"),
    SHA256        UMETA(DisplayName = "sha256"),
};
