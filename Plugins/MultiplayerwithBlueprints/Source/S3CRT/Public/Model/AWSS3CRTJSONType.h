/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTJSONType.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTJSONType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    DOCUMENT        UMETA(DisplayName = "document"),
    LINES        UMETA(DisplayName = "lines"),
};
