/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "JobReportScope.generated.h"

UENUM(BlueprintType)
enum class EAWSJobReportScope : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AllTasks        UMETA(DisplayName = "alltasks"),
    FailedTasksOnly        UMETA(DisplayName = "failedtasksonly"),
};
