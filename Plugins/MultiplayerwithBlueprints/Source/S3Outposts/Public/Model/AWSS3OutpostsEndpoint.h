/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/Endpoint.h"

#endif

#include "Model/AWSS3OutpostsEndpointStatus.h"
#include "Model/AWSS3OutpostsNetworkInterface.h"
#include "Model/AWSS3OutpostsEndpointAccessType.h"

#include "AWSS3OutpostsEndpoint.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsEndpoint {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString endpointArn;

    /**
    *  <p>The ID of the AWS Outpost.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString outpostsId;

    /**
    *  <p>The VPC CIDR committed by this endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString cidrBlock;

    /**
    *  <p>The status of the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    EAWSS3OutpostsEndpointStatus status = EAWSS3OutpostsEndpointStatus::NOT_SET;

    /**
    *  <p>The time the endpoint was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FDateTime creationTime;

    /**
    *  <p>The network interface of the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    TArray<FAWSS3OutpostsNetworkInterface> networkInterfaces;

    /**
    *  <p>The ID of the VPC used for the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString vpcId;

    /**
    *  <p>The ID of the subnet used for the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString subnetId;

    /**
    *  <p>The ID of the security group used for the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString securityGroupId;

    /**
    *  <p>The type of connectivity used to access the Amazon S3 on Outposts endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    EAWSS3OutpostsEndpointAccessType accessType = EAWSS3OutpostsEndpointAccessType::NOT_SET;

    /**
    *  <p>The ID of the customer-owned IPv4 address pool used for the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString customerOwnedIpv4Pool;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    FAWSS3OutpostsEndpoint &fromAWS(const Aws::S3Outposts::Model::Endpoint &awsEndpoint) {
        this->endpointArn = UTF8_TO_TCHAR(awsEndpoint.GetEndpointArn().c_str());

        this->outpostsId = UTF8_TO_TCHAR(awsEndpoint.GetOutpostsId().c_str());

        this->cidrBlock = UTF8_TO_TCHAR(awsEndpoint.GetCidrBlock().c_str());

        switch(awsEndpoint.GetStatus()) {
            case Aws::S3Outposts::Model::EndpointStatus::NOT_SET:
                this->status = EAWSS3OutpostsEndpointStatus::NOT_SET;
                break;
            case Aws::S3Outposts::Model::EndpointStatus::Pending:
                this->status = EAWSS3OutpostsEndpointStatus::Pending;
                break;
            case Aws::S3Outposts::Model::EndpointStatus::Available:
                this->status = EAWSS3OutpostsEndpointStatus::Available;
                break;
            case Aws::S3Outposts::Model::EndpointStatus::Deleting:
                this->status = EAWSS3OutpostsEndpointStatus::Deleting;
                break;
            default:
                this->status = EAWSS3OutpostsEndpointStatus::NOT_SET;
                break;
        }

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsEndpoint.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->networkInterfaces.Empty();
        for (const Aws::S3Outposts::Model::NetworkInterface& elem : awsEndpoint.GetNetworkInterfaces()) {
            this->networkInterfaces.Add(FAWSS3OutpostsNetworkInterface().fromAWS(elem));
        }

        this->vpcId = UTF8_TO_TCHAR(awsEndpoint.GetVpcId().c_str());

        this->subnetId = UTF8_TO_TCHAR(awsEndpoint.GetSubnetId().c_str());

        this->securityGroupId = UTF8_TO_TCHAR(awsEndpoint.GetSecurityGroupId().c_str());

        switch(awsEndpoint.GetAccessType()) {
            case Aws::S3Outposts::Model::EndpointAccessType::NOT_SET:
                this->accessType = EAWSS3OutpostsEndpointAccessType::NOT_SET;
                break;
            case Aws::S3Outposts::Model::EndpointAccessType::Private:
                this->accessType = EAWSS3OutpostsEndpointAccessType::Private;
                break;
            case Aws::S3Outposts::Model::EndpointAccessType::CustomerOwnedIp:
                this->accessType = EAWSS3OutpostsEndpointAccessType::CustomerOwnedIp;
                break;
            default:
                this->accessType = EAWSS3OutpostsEndpointAccessType::NOT_SET;
                break;
        }

        this->customerOwnedIpv4Pool = UTF8_TO_TCHAR(awsEndpoint.GetCustomerOwnedIpv4Pool().c_str());

        return *this;
    }
#endif
};
