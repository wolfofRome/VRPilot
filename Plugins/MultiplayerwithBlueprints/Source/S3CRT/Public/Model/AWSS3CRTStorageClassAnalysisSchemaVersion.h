/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTStorageClassAnalysisSchemaVersion.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTStorageClassAnalysisSchemaVersion : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    V_1        UMETA(DisplayName = "v 1"),
};
