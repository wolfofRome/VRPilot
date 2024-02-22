/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlMFADelete.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlMFADelete : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Enabled        UMETA(DisplayName = "enabled"),
    Disabled        UMETA(DisplayName = "disabled"),
};
