/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTTier.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTTier : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Standard        UMETA(DisplayName = "standard"),
    Bulk        UMETA(DisplayName = "bulk"),
    Expedited        UMETA(DisplayName = "expedited"),
};
