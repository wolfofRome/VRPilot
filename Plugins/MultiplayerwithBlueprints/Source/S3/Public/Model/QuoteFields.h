/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "QuoteFields.generated.h"

UENUM(BlueprintType)
enum class EAWSQuoteFields : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ALWAYS        UMETA(DisplayName = "always"),
    ASNEEDED        UMETA(DisplayName = "asneeded"),
};
