/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlObjectLambdaTransformationConfigurationAction.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlObjectLambdaTransformationConfigurationAction : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    GetObject        UMETA(DisplayName = "getobject"),
    HeadObject        UMETA(DisplayName = "headobject"),
    ListObjects        UMETA(DisplayName = "listobjects"),
    ListObjectsV2        UMETA(DisplayName = "listobjectsv2"),
};
