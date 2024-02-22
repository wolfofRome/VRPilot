/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/NetworkInterface.h"

#endif

#include "AWSS3OutpostsNetworkInterface.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsNetworkInterface {
GENERATED_BODY()

    /**
    *  <p>The ID for the network interface.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString networkInterfaceId;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    FAWSS3OutpostsNetworkInterface &fromAWS(const Aws::S3Outposts::Model::NetworkInterface &awsNetworkInterface) {
        this->networkInterfaceId = UTF8_TO_TCHAR(awsNetworkInterface.GetNetworkInterfaceId().c_str());

        return *this;
    }
#endif
};
