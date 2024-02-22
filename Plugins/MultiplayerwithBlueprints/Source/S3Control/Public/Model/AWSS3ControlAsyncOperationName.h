/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlAsyncOperationName.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlAsyncOperationName : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CreateMultiRegionAccessPoint        UMETA(DisplayName = "create multi region access point"),
    DeleteMultiRegionAccessPoint        UMETA(DisplayName = "delete multi region access point"),
    PutMultiRegionAccessPointPolicy        UMETA(DisplayName = "put multi region access point policy"),
};
