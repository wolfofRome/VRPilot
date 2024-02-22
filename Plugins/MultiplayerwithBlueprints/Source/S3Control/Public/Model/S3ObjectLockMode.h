/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "S3ObjectLockMode.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ObjectLockMode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    COMPLIANCE        UMETA(DisplayName = "compliance"),
    GOVERNANCE        UMETA(DisplayName = "governance"),
};
