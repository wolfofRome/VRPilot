/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlExpirationStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlExpirationStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Enabled        UMETA(DisplayName = "enabled"),
    Disabled        UMETA(DisplayName = "disabled"),
};
