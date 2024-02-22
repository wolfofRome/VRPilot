/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTAnalyticsS3ExportFileFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTAnalyticsS3ExportFileFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CSV        UMETA(DisplayName = "csv"),
};
