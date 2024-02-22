/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ReplicationTimeValue.h"

#endif

#include "AWSS3CRTReplicationTimeValue.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTReplicationTimeValue {
GENERATED_BODY()

    /**
    *  <p> Contains an integer specifying time in minutes. </p> <p> Valid values: 15 minutes. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int minutes = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ReplicationTimeValue toAWS() const {
        Aws::S3Crt::Model::ReplicationTimeValue awsReplicationTimeValue;

        if (!(this->minutes == 0)) {
            awsReplicationTimeValue.SetMinutes(this->minutes);
        }

        return awsReplicationTimeValue;
    }

    bool IsEmpty() const {
        return this->minutes == 0;
    }

    FAWSS3CRTReplicationTimeValue &fromAWS(const Aws::S3Crt::Model::ReplicationTimeValue &awsReplicationTimeValue) {
		this->minutes = awsReplicationTimeValue.GetMinutes();

        return *this;
    }
#endif
};
