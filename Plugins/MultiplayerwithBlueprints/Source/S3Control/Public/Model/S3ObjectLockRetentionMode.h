/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "S3ObjectLockRetentionMode.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ObjectLockRetentionMode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    COMPLIANCE        UMETA(DisplayName = "compliance"),
    GOVERNANCE        UMETA(DisplayName = "governance"),
};
