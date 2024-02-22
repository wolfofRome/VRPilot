/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTRestoreRequestType.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTRestoreRequestType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SELECT        UMETA(DisplayName = "select"),
};
