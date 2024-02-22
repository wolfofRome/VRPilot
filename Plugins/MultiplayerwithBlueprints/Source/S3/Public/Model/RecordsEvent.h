/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/RecordsEvent.h"
#include "aws/core/utils/memory/stl/AWSString.h"

#endif

#include "RecordsEvent.generated.h"

USTRUCT(BlueprintType)
struct FRecordsEvent {
    GENERATED_BODY()

    /**
    * <p>The byte array of partial, one or more result records.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString payload;

#if WITH_S3CLIENTSDK && WITH_CORE
    public:
    Aws::S3::Model::RecordsEvent toAWS() const {
        Aws::S3::Model::RecordsEvent awsRecordsEvent;

		if (!(this->payload.IsEmpty())) {
		    Aws::String awsPayload = TCHAR_TO_UTF8(*this->payload);
            awsRecordsEvent.SetPayload(Aws::Vector<unsigned char>(awsPayload.begin(), awsPayload.end()));
        }

        return awsRecordsEvent;
    }

    bool IsEmpty() const {
        return this->payload.IsEmpty();
    }
    
    FRecordsEvent &fromAWS(const Aws::S3::Model::RecordsEvent &awsRecordsEvent) {
        const Aws::Vector<unsigned char> awsPayload = awsRecordsEvent.GetPayload();
        this->payload = UTF8_TO_TCHAR(Aws::String(awsPayload.begin(), awsPayload.end()).c_str());
                
        return *this;
    }
#endif
};
