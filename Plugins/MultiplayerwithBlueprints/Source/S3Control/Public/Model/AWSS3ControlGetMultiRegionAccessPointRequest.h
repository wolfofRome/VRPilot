/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetMultiRegionAccessPointRequest.h"

#endif

#include "AWSS3ControlGetMultiRegionAccessPointRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlGetMultiRegionAccessPointRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID for the owner of the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The name of the Multi-Region Access Point whose configuration information you want to receive. The name of the Multi-Region Access Point is different from the alias. For more information about the distinction between the name and the alias of an Multi-Region Access Point, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/CreatingMultiRegionAccessPoints.html#multi-region-access-point-naming">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetMultiRegionAccessPointRequest toAWS() const {
        Aws::S3Control::Model::GetMultiRegionAccessPointRequest awsGetMultiRegionAccessPointRequest;

		if (!(this->accountId.IsEmpty())) {
            awsGetMultiRegionAccessPointRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->name.IsEmpty())) {
            awsGetMultiRegionAccessPointRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsGetMultiRegionAccessPointRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
