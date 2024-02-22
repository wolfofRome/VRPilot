/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ObjectLockLegalHoldStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSObjectLockLegalHoldStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ON        UMETA(DisplayName = "on"),
    OFF        UMETA(DisplayName = "off"),
};
