/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "InventoryFrequency.generated.h"

UENUM(BlueprintType)
enum class EAWSInventoryFrequency : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Daily        UMETA(DisplayName = "daily"),
    Weekly        UMETA(DisplayName = "weekly"),
};
