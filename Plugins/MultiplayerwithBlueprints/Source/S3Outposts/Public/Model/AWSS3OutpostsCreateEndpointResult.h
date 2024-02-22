/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/CreateEndpointResult.h"

#endif

#include "AWSS3OutpostsCreateEndpointResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsCreateEndpointResult {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString endpointArn;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    FAWSS3OutpostsCreateEndpointResult &fromAWS(const Aws::S3Outposts::Model::CreateEndpointResult &awsCreateEndpointResult) {
        this->endpointArn = UTF8_TO_TCHAR(awsCreateEndpointResult.GetEndpointArn().c_str());

        return *this;
    }
#endif
};
