/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ObjectLockMode.generated.h"

UENUM(BlueprintType)
enum class EAWSObjectLockMode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    GOVERNANCE        UMETA(DisplayName = "governance"),
    COMPLIANCE        UMETA(DisplayName = "compliance"),
};
