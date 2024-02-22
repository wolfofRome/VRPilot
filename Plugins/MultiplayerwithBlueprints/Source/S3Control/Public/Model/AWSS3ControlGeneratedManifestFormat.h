/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlGeneratedManifestFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlGeneratedManifestFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    S3InventoryReport_CSV_20211130        UMETA(DisplayName = "s3 inventory report csv 20211130"),
};
