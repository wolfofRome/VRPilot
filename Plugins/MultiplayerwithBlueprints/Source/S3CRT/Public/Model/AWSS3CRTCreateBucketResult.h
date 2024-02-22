/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CreateBucketResult.h"

#endif

#include "AWSS3CRTCreateBucketResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCreateBucketResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the Region where the bucket will be created. If you are creating a bucket on the US East (N. Virginia) Region (us-east-1), you do not need to specify the location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString location;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTCreateBucketResult &fromAWS(const Aws::S3Crt::Model::CreateBucketResult &awsCreateBucketResult) {
        this->location = UTF8_TO_TCHAR(awsCreateBucketResult.GetLocation().c_str());

        return *this;
    }
#endif
};
