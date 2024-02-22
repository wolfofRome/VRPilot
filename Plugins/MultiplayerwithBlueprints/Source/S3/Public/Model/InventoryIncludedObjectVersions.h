/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "InventoryIncludedObjectVersions.generated.h"

UENUM(BlueprintType)
enum class EAWSInventoryIncludedObjectVersions : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    All        UMETA(DisplayName = "all"),
    Current        UMETA(DisplayName = "current"),
};
