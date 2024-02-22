/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "StorageClassAnalysisSchemaVersion.generated.h"

UENUM(BlueprintType)
enum class EAWSS3StorageClassAnalysisSchemaVersion : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    V_1        UMETA(DisplayName = "v 1"),
};
