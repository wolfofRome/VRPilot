/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ArchiveStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ArchiveStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ARCHIVE_ACCESS        UMETA(DisplayName = "archive access"),
    DEEP_ARCHIVE_ACCESS        UMETA(DisplayName = "deep archive access"),
};
