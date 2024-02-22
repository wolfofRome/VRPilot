/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3StorageClass.generated.h"

UENUM(BlueprintType)
enum class EAWSS3StorageClass : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    STANDARD        UMETA(DisplayName = "standard"),
    REDUCED_REDUNDANCY        UMETA(DisplayName = "reduced redundancy"),
    STANDARD_IA        UMETA(DisplayName = "standard ia"),
    ONEZONE_IA        UMETA(DisplayName = "onezone ia"),
    INTELLIGENT_TIERING        UMETA(DisplayName = "intelligent tiering"),
    GLACIER        UMETA(DisplayName = "glacier"),
    DEEP_ARCHIVE        UMETA(DisplayName = "deep archive"),
    OUTPOSTS        UMETA(DisplayName = "outposts"),
    GLACIER_IR        UMETA(DisplayName = "glacier ir"),
};
