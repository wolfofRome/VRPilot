/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "JobReportFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSJobReportFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Report_CSV_20180820        UMETA(DisplayName = "report csv 20180820"),
};
