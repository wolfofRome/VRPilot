/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "S3GlacierJobTier.generated.h"

UENUM(BlueprintType)
enum class EAWSS3GlacierJobTier : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    BULK        UMETA(DisplayName = "bulk"),
    STANDARD        UMETA(DisplayName = "standard"),
};
