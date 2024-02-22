/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTFileHeaderInfo.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTFileHeaderInfo : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    USE        UMETA(DisplayName = "use"),
    IGNORE        UMETA(DisplayName = "ignore"),
    NONE        UMETA(DisplayName = "none"),
};
