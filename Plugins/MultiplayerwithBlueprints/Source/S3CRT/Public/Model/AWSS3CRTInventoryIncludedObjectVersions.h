/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTInventoryIncludedObjectVersions.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTInventoryIncludedObjectVersions : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    All        UMETA(DisplayName = "all"),
    Current        UMETA(DisplayName = "current"),
};
