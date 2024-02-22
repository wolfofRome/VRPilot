/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ObjectLockEnabled.generated.h"

UENUM(BlueprintType)
enum class EAWSObjectLockEnabled : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Enabled        UMETA(DisplayName = "enabled"),
};
