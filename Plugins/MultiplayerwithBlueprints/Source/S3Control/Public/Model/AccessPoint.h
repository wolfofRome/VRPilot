/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/AccessPoint.h"

#endif

#include "Model/NetworkOrigin.h"
#include "Model/VpcConfiguration.h"

#include "AccessPoint.generated.h"

USTRUCT(BlueprintType)
struct FAccessPoint {
GENERATED_BODY()

    /**
    *  <p>The name of this access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>Indicates whether this access point allows access from the public internet. If <code>VpcConfiguration</code> is specified for this access point, then <code>NetworkOrigin</code> is <code>VPC</code>, and the access point doesn't allow access from the public internet. Otherwise, <code>NetworkOrigin</code> is <code>Internet</code>, and the access point allows access from the public internet, subject to the access point and bucket access policies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSNetworkOrigin networkOrigin = EAWSNetworkOrigin::NOT_SET;

    /**
    *  <p>The virtual private cloud (VPC) configuration for this access point, if one exists.</p>  <p>This element is empty if this access point is an Amazon S3 on Outposts access point that is used by other Amazon Web Services.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FVpcConfiguration vpcConfiguration;

    /**
    *  <p>The name of the bucket associated with this access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>The ARN for the access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accessPointArn;

    /**
    *  <p>The name or alias of the access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString alias;

    /**
    *  <p>The Amazon Web Services account ID associated with the S3 bucket associated with this access point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucketAccountId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAccessPoint &fromAWS(const Aws::S3Control::Model::AccessPoint &awsAccessPoint) {
        this->name = UTF8_TO_TCHAR(awsAccessPoint.GetName().c_str());

        switch(awsAccessPoint.GetNetworkOrigin()) {
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

        this->vpcConfiguration.fromAWS(awsAccessPoint.GetVpcConfiguration());

        this->bucket = UTF8_TO_TCHAR(awsAccessPoint.GetBucket().c_str());

        this->accessPointArn = UTF8_TO_TCHAR(awsAccessPoint.GetAccessPointArn().c_str());

        this->alias = UTF8_TO_TCHAR(awsAccessPoint.GetAlias().c_str());

        this->bucketAccountId = UTF8_TO_TCHAR(awsAccessPoint.GetBucketAccountId().c_str());

        return *this;
    }
#endif
};
