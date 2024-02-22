/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlOutputSchemaVersion.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlOutputSchemaVersion : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    V_1        UMETA(DisplayName = "v 1"),
};
