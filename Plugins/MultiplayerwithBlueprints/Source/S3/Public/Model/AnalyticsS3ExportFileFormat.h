/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "AnalyticsS3ExportFileFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSAnalyticsS3ExportFileFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CSV        UMETA(DisplayName = "csv"),
};
