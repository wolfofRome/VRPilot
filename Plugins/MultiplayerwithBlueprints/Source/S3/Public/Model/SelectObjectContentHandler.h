/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/core/client/AWSError.h"
#include "aws/s3/model/SelectObjectContentHandler.h"

#endif

#include "Model/RecordsEvent.h"
#include "Model/StatsEvent.h"
#include "Model/ProgressEvent.h"
#include "S3Error.h"

#include "SelectObjectContentHandler.generated.h"

UCLASS(Blueprintable)
class S3_API USelectObjectContentHandler : public UObject {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, Category = "S3 Client")
    void RecordsEventCallback(const FRecordsEvent &recordsEvent);

    UFUNCTION(BlueprintNativeEvent, Category = "S3 Client")
    void StatsEventCallback(const FStatsEvent &statsEvent);

    UFUNCTION(BlueprintNativeEvent, Category = "S3 Client")
    void ProgressEventCallback(const FProgressEvent &progressEvent);

    UFUNCTION(BlueprintNativeEvent, Category = "S3 Client")
    void ContinuationEventCallback();

    UFUNCTION(BlueprintNativeEvent, Category = "S3 Client")
    void EndEventCallback();

    UFUNCTION(BlueprintNativeEvent, Category = "S3 Client")
    void ErrorCallback(const ES3Error &error);

#if WITH_S3CLIENTSDK && WITH_CORE
    Aws::S3::Model::SelectObjectContentHandler toAWS();
#endif
};
