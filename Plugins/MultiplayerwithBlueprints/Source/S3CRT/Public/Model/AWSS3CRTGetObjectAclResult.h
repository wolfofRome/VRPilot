/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetObjectAclResult.h"

#endif

#include "Model/AWSS3CRTOwner.h"
#include "Model/AWSS3CRTGrant.h"
#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTGetObjectAclResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetObjectAclResult {
GENERATED_BODY()

    /**
    *  <p> Container for the bucket owner's display name and ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOwner owner;

    /**
    *  <p>A list of grants.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTGrant> grants;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetObjectAclResult &fromAWS(const Aws::S3Crt::Model::GetObjectAclResult &awsGetObjectAclResult) {
        this->owner = FAWSS3CRTOwner().fromAWS(awsGetObjectAclResult.GetOwner());

        this->grants.Empty();
        for (const Aws::S3Crt::Model::Grant& elem : awsGetObjectAclResult.GetGrants()) {
            this->grants.Add(FAWSS3CRTGrant().fromAWS(elem));
        }

        switch(awsGetObjectAclResult.GetRequestCharged()) {
            case Aws::S3Crt::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
            case Aws::S3Crt::Model::RequestCharged::requester:
                this->requestCharged = EAWSS3CRTRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
