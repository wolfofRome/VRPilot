/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTInventoryFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTInventoryFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CSV        UMETA(DisplayName = "csv"),
    ORC        UMETA(DisplayName = "orc"),
    Parquet        UMETA(DisplayName = "parquet"),
};
