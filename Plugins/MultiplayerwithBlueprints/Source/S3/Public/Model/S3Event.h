/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "S3Event.generated.h"

UENUM(BlueprintType)
enum class ES3Event : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    s3_ReducedRedundancyLostObject        UMETA(DisplayName = "s3 reduced redundancy lost object"),
    s3_ObjectCreated        UMETA(DisplayName = "s3 object created"),
    s3_ObjectCreated_Put        UMETA(DisplayName = "s3 object created put"),
    s3_ObjectCreated_Post        UMETA(DisplayName = "s3 object created post"),
    s3_ObjectCreated_Copy        UMETA(DisplayName = "s3 object created copy"),
    s3_ObjectCreated_CompleteMultipartUpload        UMETA(DisplayName = "s3 object created complete multipart upload"),
    s3_ObjectRemoved        UMETA(DisplayName = "s3 object removed"),
    s3_ObjectRemoved_Delete        UMETA(DisplayName = "s3 object removed delete"),
    s3_ObjectRemoved_DeleteMarkerCreated        UMETA(DisplayName = "s3 object removed delete marker created"),
    s3_ObjectRestore        UMETA(DisplayName = "s3 object restore"),
    s3_ObjectRestore_Post        UMETA(DisplayName = "s3 object restore post"),
    s3_ObjectRestore_Completed        UMETA(DisplayName = "s3 object restore completed"),
    s3_Replication        UMETA(DisplayName = "s3 replication"),
    s3_Replication_OperationFailedReplication        UMETA(DisplayName = "s3 replication operation failed replication"),
    s3_Replication_OperationNotTracked        UMETA(DisplayName = "s3 replication operation not tracked"),
    s3_Replication_OperationMissedThreshold        UMETA(DisplayName = "s3 replication operation missed threshold"),
    s3_Replication_OperationReplicatedAfterThreshold        UMETA(DisplayName = "s3 replication operation replicated after threshold"),
    s3_ObjectRestore_Delete        UMETA(DisplayName = "s3 objectrestore delete"),
    s3_LifecycleTransition        UMETA(DisplayName = "s3 lifecycletransition"),
    s3_IntelligentTiering        UMETA(DisplayName = "s3 intelligenttiering"),
    s3_ObjectAcl_Put        UMETA(DisplayName = "s3 objectacl put"),
    s3_LifecycleExpiration        UMETA(DisplayName = "s3 lifecycleexpiration"),
    s3_LifecycleExpiration_Delete        UMETA(DisplayName = "s3 lifecycleexpiration delete"),
    s3_LifecycleExpiration_DeleteMarkerCreated        UMETA(DisplayName = "s3 lifecycleexpiration deletemarkercreated"),
    s3_ObjectTagging        UMETA(DisplayName = "s3 objecttagging"),
    s3_ObjectTagging_Put        UMETA(DisplayName = "s3 objecttagging put"),
    s3_ObjectTagging_Delete        UMETA(DisplayName = "s3 objecttagging delete"),
};
