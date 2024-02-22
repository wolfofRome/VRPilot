/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTQuoteFields.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTQuoteFields : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ALWAYS        UMETA(DisplayName = "always"),
    ASNEEDED        UMETA(DisplayName = "asneeded"),
};
