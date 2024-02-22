/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/core/client/AWSError.h"

#include "aws/s3-crt/model/SelectObjectContentHandler.h"

#endif

#include "Model/AWSS3CRTRecordsEvent.h"
#include "Model/AWSS3CRTStatsEvent.h"
#include "Model/AWSS3CRTProgressEvent.h"
#include "S3CRTError.h"

#include "AWSS3CRTSelectObjectContentHandler.generated.h"

UCLASS(Blueprintable)
class S3CRT_API UAWSS3CRTSelectObjectContentHandler : public UObject {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, Category = "S3CRT Client")
    void RecordsEventCallback(const FAWSS3CRTRecordsEvent &recordsEvent);

    UFUNCTION(BlueprintNativeEvent, Category = "S3CRT Client")
    void StatsEventCallback(const FAWSS3CRTStatsEvent &statsEvent);

    UFUNCTION(BlueprintNativeEvent, Category = "S3CRT Client")
    void ProgressEventCallback(const FAWSS3CRTProgressEvent &progressEvent);

    UFUNCTION(BlueprintNativeEvent, Category = "S3CRT Client")
    void ContinuationEventCallback();

    UFUNCTION(BlueprintNativeEvent, Category = "S3CRT Client")
    void EndEventCallback();

    UFUNCTION(BlueprintNativeEvent, Category = "S3CRT Client")
    void ErrorCallback(const ES3CRTError &error);

#if WITH_S3CRTCLIENTSDK && WITH_CORE
    Aws::S3Crt::Model::SelectObjectContentHandler toAWS();
#endif
};
