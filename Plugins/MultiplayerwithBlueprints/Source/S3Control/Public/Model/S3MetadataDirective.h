/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "S3MetadataDirective.generated.h"

UENUM(BlueprintType)
enum class EAWSS3MetadataDirective : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    COPY        UMETA(DisplayName = "copy"),
    REPLACE        UMETA(DisplayName = "replace"),
};
