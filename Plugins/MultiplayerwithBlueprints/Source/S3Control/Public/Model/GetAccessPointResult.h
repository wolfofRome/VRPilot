/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetAccessPointResult.h"

#endif

#include "Model/NetworkOrigin.h"
#include "Model/VpcConfiguration.h"
#include "Model/S3ControlPublicAccessBlockConfiguration.h"

#include "GetAccessPointResult.generated.h"

USTRUCT(BlueprintType)
struct FGetAccessPointResult {
GENERATED_BODY()

    /**
    *  <p>The name of the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>The name of the bucket associated with the specified access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>Indicates whether this access point allows access from the public internet. If <code>VpcConfiguration</code> is specified for this access point, then <code>NetworkOrigin</code> is <code>VPC</code>, and the access point doesn't allow access from the public internet. Otherwise, <code>NetworkOrigin</code> is <code>Internet</code>, and the access point allows access from the public internet, subject to the access point and bucket access policies.</p> <p>This will always be true for an Amazon S3 on Outposts access point</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSNetworkOrigin networkOrigin = EAWSNetworkOrigin::NOT_SET;

    /**
    *  <p>Contains the virtual private cloud (VPC) configuration for the specified access point.</p>  <p>This element is empty if this access point is an Amazon S3 on Outposts access point that is used by other Amazon Web Services.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FVpcConfiguration vpcConfiguration;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPublicAccessBlockConfiguration publicAccessBlockConfiguration;

    /**
    *  <p>The date and time when the specified access point was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime creationDate;

    /**
    *  <p>The name or alias of the access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString alias;

    /**
    *  <p>The ARN of the access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accessPointArn;

    /**
    *  <p>The VPC endpoint for the access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TMap<FString, FString> endpoints;

    /**
    *  <p>The Amazon Web Services account ID associated with the S3 bucket associated with this access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucketAccountId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FGetAccessPointResult &fromAWS(const Aws::S3Control::Model::GetAccessPointResult &awsGetAccessPointResult) {
        this->name = UTF8_TO_TCHAR(awsGetAccessPointResult.GetName().c_str());

        this->bucket = UTF8_TO_TCHAR(awsGetAccessPointResult.GetBucket().c_str());

        switch(awsGetAccessPointResult.GetNetworkOrigin()) {
            case Aws::S3Control::Model::NetworkOrigin::NOT_SET:
                this->networkOrigin = EAWSNetworkOrigin::NOT_SET;
                break;
            case Aws::S3Control::Model::NetworkOrigin::Internet:
                this->networkOrigin = EAWSNetworkOrigin::Internet;
                break;
            case Aws::S3Control::Model::NetworkOrigin::VPC:
                this->networkOrigin = EAWSNetworkOrigin::VPC;
                break;
            default:
                this->networkOrigin = EAWSNetworkOrigin::NOT_SET;
                break;
        }

        this->vpcConfiguration.fromAWS(awsGetAccessPointResult.GetVpcConfiguration());

        this->publicAccessBlockConfiguration.fromAWS(awsGetAccessPointResult.GetPublicAccessBlockConfiguration());

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsGetAccessPointResult.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        this->alias = UTF8_TO_TCHAR(awsGetAccessPointResult.GetAlias().c_str());

        this->accessPointArn = UTF8_TO_TCHAR(awsGetAccessPointResult.GetAccessPointArn().c_str());

        this->endpoints.Empty();
        for (const auto& elem : awsGetAccessPointResult.GetEndpoints()) {
            this->endpoints.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }

        this->bucketAccountId = UTF8_TO_TCHAR(awsGetAccessPointResult.GetBucketAccountId().c_str());

        return *this;
    }
#endif
};
