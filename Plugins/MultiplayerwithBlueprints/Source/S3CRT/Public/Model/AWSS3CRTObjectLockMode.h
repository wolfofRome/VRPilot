/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTObjectLockMode.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTObjectLockMode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    GOVERNANCE        UMETA(DisplayName = "governance"),
    COMPLIANCE        UMETA(DisplayName = "compliance"),
};