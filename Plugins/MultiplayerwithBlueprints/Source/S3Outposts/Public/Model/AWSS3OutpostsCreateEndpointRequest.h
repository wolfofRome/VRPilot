/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/model/CreateEndpointRequest.h"

#endif

#include "Model/AWSS3OutpostsEndpointAccessType.h"

#include "AWSS3OutpostsCreateEndpointRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OutpostsCreateEndpointRequest {
GENERATED_BODY()

    /**
    *  <p>The ID of the AWS Outpost. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString outpostId;

    /**
    *  <p>The ID of the subnet in the selected VPC.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString subnetId;

    /**
    *  <p>The ID of the security group to use with the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString securityGroupId;

    /**
    *  <p>The type of access for the network connectivity for the Amazon S3 on Outposts endpoint. To use the Amazon Web Services VPC, choose <code>Private</code>. To use the endpoint with an on-premises network, choose <code>CustomerOwnedIp</code>. If you choose <code>CustomerOwnedIp</code>, you must also provide the customer-owned IP address pool (CoIP pool).</p>  <p> <code>Private</code> is the default access type value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    EAWSS3OutpostsEndpointAccessType accessType = EAWSS3OutpostsEndpointAccessType::NOT_SET;

    /**
    *  <p>The ID of the customer-owned IPv4 address pool (CoIP pool) for the endpoint. IP addresses are allocated from this pool for the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Outposts Client")
    FString customerOwnedIpv4Pool;

#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
public:
    Aws::S3Outposts::Model::CreateEndpointRequest toAWS() const {
        Aws::S3Outposts::Model::CreateEndpointRequest awsCreateEndpointRequest;

        if (!(this->outpostId.IsEmpty())) {
            awsCreateEndpointRequest.SetOutpostId(TCHAR_TO_UTF8(*this->outpostId));
        }

        if (!(this->subnetId.IsEmpty())) {
            awsCreateEndpointRequest.SetSubnetId(TCHAR_TO_UTF8(*this->subnetId));
        }

        if (!(this->securityGroupId.IsEmpty())) {
            awsCreateEndpointRequest.SetSecurityGroupId(TCHAR_TO_UTF8(*this->securityGroupId));
        }

        switch(this->accessType) {
            case EAWSS3OutpostsEndpointAccessType::Private:
                awsCreateEndpointRequest.SetAccessType(Aws::S3Outposts::Model::EndpointAccessType::Private);
                break;
            case EAWSS3OutpostsEndpointAccessType::CustomerOwnedIp:
                awsCreateEndpointRequest.SetAccessType(Aws::S3Outposts::Model::EndpointAccessType::CustomerOwnedIp);
                break;
            default:
                break;
        }

        if (!(this->customerOwnedIpv4Pool.IsEmpty())) {
            awsCreateEndpointRequest.SetCustomerOwnedIpv4Pool(TCHAR_TO_UTF8(*this->customerOwnedIpv4Pool));
        }

        return awsCreateEndpointRequest;
    }

    bool IsEmpty() const {
        return this->outpostId.IsEmpty() && this->subnetId.IsEmpty() && this->securityGroupId.IsEmpty() && this->accessType == EAWSS3OutpostsEndpointAccessType::NOT_SET && this->customerOwnedIpv4Pool.IsEmpty();
    }
#endif
};
