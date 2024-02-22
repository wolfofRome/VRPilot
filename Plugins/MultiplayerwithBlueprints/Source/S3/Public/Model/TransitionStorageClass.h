/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "TransitionStorageClass.generated.h"

UENUM(BlueprintType)
enum class EAWSTransitionStorageClass : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    GLACIER        UMETA(DisplayName = "glacier"),
    STANDARD_IA        UMETA(DisplayName = "standard ia"),
    ONEZONE_IA        UMETA(DisplayName = "onezone ia"),
    INTELLIGENT_TIERING        UMETA(DisplayName = "intelligent tiering"),
    DEEP_ARCHIVE        UMETA(DisplayName = "deep archive"),
    GLACIER_IR        UMETA(DisplayName = "glacier ir"),
};
