/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "JobManifestFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSJobManifestFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    S3BatchOperations_CSV_20180820        UMETA(DisplayName = "s3batchoperations csv 20180820"),
    S3InventoryReport_CSV_20161130        UMETA(DisplayName = "s3inventoryreport csv 20161130"),
};
