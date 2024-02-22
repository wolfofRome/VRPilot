/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CreateBucketResult.h"

#endif

#include "CreateBucketResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateBucketResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the Region where the bucket will be created. If you are creating a bucket on the US East (N. Virginia) Region (us-east-1), you do not need to specify the location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString location;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FCreateBucketResult &fromAWS(const Aws::S3::Model::CreateBucketResult &awsCreateBucketResult) {
        this->location = UTF8_TO_TCHAR(awsCreateBucketResult.GetLocation().c_str());

        return *this;
    }
#endif
};
