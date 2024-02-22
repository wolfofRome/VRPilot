/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "Protocol.generated.h"

UENUM(BlueprintType)
enum class EAWSProtocol : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    http        UMETA(DisplayName = "http"),
    https        UMETA(DisplayName = "https"),
};
