/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTEvent.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTEvent : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    s3_ReducedRedundancyLostObject        UMETA(DisplayName = "s3 reducedredundancylostobject"),
    s3_ObjectCreated        UMETA(DisplayName = "s3 objectcreated"),
    s3_ObjectCreated_Put        UMETA(DisplayName = "s3 objectcreated put"),
    s3_ObjectCreated_Post        UMETA(DisplayName = "s3 objectcreated post"),
    s3_ObjectCreated_Copy        UMETA(DisplayName = "s3 objectcreated copy"),
    s3_ObjectCreated_CompleteMultipartUpload        UMETA(DisplayName = "s3 objectcreated completemultipartupload"),
    s3_ObjectRemoved        UMETA(DisplayName = "s3 objectremoved"),
    s3_ObjectRemoved_Delete        UMETA(DisplayName = "s3 objectremoved delete"),
    s3_ObjectRemoved_DeleteMarkerCreated        UMETA(DisplayName = "s3 objectremoved deletemarkercreated"),
    s3_ObjectRestore        UMETA(DisplayName = "s3 objectrestore"),
    s3_ObjectRestore_Post        UMETA(DisplayName = "s3 objectrestore post"),
    s3_ObjectRestore_Completed        UMETA(DisplayName = "s3 objectrestore completed"),
    s3_Replication        UMETA(DisplayName = "s3 replication"),
    s3_Replication_OperationFailedReplication        UMETA(DisplayName = "s3 replication operationfailedreplication"),
    s3_Replication_OperationNotTracked        UMETA(DisplayName = "s3 replication operationnottracked"),
    s3_Replication_OperationMissedThreshold        UMETA(DisplayName = "s3 replication operationmissedthreshold"),
    s3_Replication_OperationReplicatedAfterThreshold        UMETA(DisplayName = "s3 replication operationreplicatedafterthreshold"),
};
