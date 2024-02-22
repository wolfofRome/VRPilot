/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "RequestCharged.generated.h"

UENUM(BlueprintType)
enum class EAWSRequestCharged : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    requester        UMETA(DisplayName = "requester"),
};
