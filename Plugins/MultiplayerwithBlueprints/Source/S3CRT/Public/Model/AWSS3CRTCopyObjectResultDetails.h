/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CopyObjectResultDetails.h"

#endif

#include "AWSS3CRTCopyObjectResultDetails.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCopyObjectResultDetails {
GENERATED_BODY()

    /**
    *  <p>Returns the ETag of the new object. The ETag reflects only changes to the contents of an object, not its metadata. The source and destination ETag is identical for a successfully copied non-multipart object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString eTag;

    /**
    *  <p>Creation date of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FDateTime lastModified;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTCopyObjectResultDetails &fromAWS(const Aws::S3Crt::Model::CopyObjectResultDetails &awsCopyObjectResultDetails) {
        this->eTag = UTF8_TO_TCHAR(awsCopyObjectResultDetails.GetETag().c_str());

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsCopyObjectResultDetails.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
