/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTInventoryFrequency.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTInventoryFrequency : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Daily        UMETA(DisplayName = "daily"),
    Weekly        UMETA(DisplayName = "weekly"),
};
