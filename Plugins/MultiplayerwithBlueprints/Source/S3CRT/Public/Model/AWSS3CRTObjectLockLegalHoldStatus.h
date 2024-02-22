/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTObjectLockLegalHoldStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTObjectLockLegalHoldStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ON        UMETA(DisplayName = "on"),
    OFF        UMETA(DisplayName = "off"),
};
