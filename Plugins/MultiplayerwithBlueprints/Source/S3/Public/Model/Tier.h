/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "Tier.generated.h"

UENUM(BlueprintType)
enum class EAWSTier : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Standard        UMETA(DisplayName = "standard"),
    Bulk        UMETA(DisplayName = "bulk"),
    Expedited        UMETA(DisplayName = "expedited"),
};
