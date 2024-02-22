/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "JobManifestFieldName.generated.h"

UENUM(BlueprintType)
enum class EAWSJobManifestFieldName : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Ignore        UMETA(DisplayName = "ignore"),
    Bucket        UMETA(DisplayName = "bucket"),
    Key        UMETA(DisplayName = "key"),
    VersionId        UMETA(DisplayName = "versionid"),
};
