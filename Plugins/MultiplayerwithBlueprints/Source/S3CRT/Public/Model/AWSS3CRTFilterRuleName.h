/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTFilterRuleName.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTFilterRuleName : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    prefix        UMETA(DisplayName = "prefix"),
    suffix        UMETA(DisplayName = "suffix"),
};
