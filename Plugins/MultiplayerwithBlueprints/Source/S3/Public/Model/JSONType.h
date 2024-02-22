/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "JSONType.generated.h"

UENUM(BlueprintType)
enum class EAWSJSONType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    DOCUMENT        UMETA(DisplayName = "document"),
    LINES        UMETA(DisplayName = "lines"),
};
