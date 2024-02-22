/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlMultiRegionAccessPointStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlMultiRegionAccessPointStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    READY        UMETA(DisplayName = "ready"),
    INCONSISTENT_ACROSS_REGIONS        UMETA(DisplayName = "inconsistent across regions"),
    CREATING        UMETA(DisplayName = "creating"),
    PARTIALLY_CREATED        UMETA(DisplayName = "partially created"),
    PARTIALLY_DELETED        UMETA(DisplayName = "partially deleted"),
    DELETING        UMETA(DisplayName = "deleting"),
};
