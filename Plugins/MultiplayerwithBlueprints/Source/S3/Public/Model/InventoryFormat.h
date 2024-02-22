/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "InventoryFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSInventoryFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CSV        UMETA(DisplayName = "csv"),
    ORC        UMETA(DisplayName = "orc"),
    Parquet        UMETA(DisplayName = "parquet"),
};
