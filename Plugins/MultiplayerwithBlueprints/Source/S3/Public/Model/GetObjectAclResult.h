/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectAclResult.h"

#endif

#include "Model/Owner.h"
#include "Model/Grant.h"
#include "Model/RequestCharged.h"

#include "GetObjectAclResult.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectAclResult {
GENERATED_BODY()

    /**
    *  <p> Container for the bucket owner's display name and ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOwner owner;

    /**
    *  <p>A list of grants.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FGrant> grants;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetObjectAclResult &fromAWS(const Aws::S3::Model::GetObjectAclResult &awsGetObjectAclResult) {
        this->owner.fromAWS(awsGetObjectAclResult.GetOwner());

        this->grants.Empty();
        for (const Aws::S3::Model::Grant& elem : awsGetObjectAclResult.GetGrants()) {
            this->grants.Add(FGrant().fromAWS(elem));
        }

        switch(awsGetObjectAclResult.GetRequestCharged()) {
            case Aws::S3::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
            case Aws::S3::Model::RequestCharged::requester:
                this->requestCharged = EAWSRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
