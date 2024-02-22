/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTObjectStorageClass.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTObjectStorageClass : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    STANDARD        UMETA(DisplayName = "standard"),
    REDUCED_REDUNDANCY        UMETA(DisplayName = "reduced redundancy"),
    GLACIER        UMETA(DisplayName = "glacier"),
    STANDARD_IA        UMETA(DisplayName = "standard ia"),
    ONEZONE_IA        UMETA(DisplayName = "onezone ia"),
    INTELLIGENT_TIERING        UMETA(DisplayName = "intelligent tiering"),
    DEEP_ARCHIVE        UMETA(DisplayName = "deep archive"),
    OUTPOSTS        UMETA(DisplayName = "outposts"),
};
