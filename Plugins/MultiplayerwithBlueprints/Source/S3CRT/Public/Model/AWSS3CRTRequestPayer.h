/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTRequestPayer.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTRequestPayer : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    requester        UMETA(DisplayName = "requester"),
};
