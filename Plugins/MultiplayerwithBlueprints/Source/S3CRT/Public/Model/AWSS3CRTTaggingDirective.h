/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTTaggingDirective.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTTaggingDirective : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    COPY        UMETA(DisplayName = "copy"),
    REPLACE        UMETA(DisplayName = "replace"),
};
