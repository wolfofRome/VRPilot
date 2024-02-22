/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ReplicationTimeValue.h"

#endif

#include "ReplicationTimeValue.generated.h"

USTRUCT(BlueprintType)
struct FReplicationTimeValue {
GENERATED_BODY()

    /**
    *  <p> Contains an integer specifying time in minutes. </p> <p> Valid values: 15 minutes. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int minutes = 0;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ReplicationTimeValue toAWS() const {
        Aws::S3::Model::ReplicationTimeValue awsReplicationTimeValue;

        if (!(this->minutes == 0)) {
            awsReplicationTimeValue.SetMinutes(this->minutes);
        }

        return awsReplicationTimeValue;
    }

    bool IsEmpty() const {
        return this->minutes == 0;
    }

    FReplicationTimeValue &fromAWS(const Aws::S3::Model::ReplicationTimeValue &awsReplicationTimeValue) {
		this->minutes = awsReplicationTimeValue.GetMinutes();

        return *this;
    }
#endif
};
