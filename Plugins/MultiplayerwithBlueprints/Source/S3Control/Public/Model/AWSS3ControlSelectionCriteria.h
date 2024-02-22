/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/SelectionCriteria.h"

#endif

#include "AWSS3ControlSelectionCriteria.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlSelectionCriteria {
GENERATED_BODY()

    /**
    *  <p>A container for the delimiter of the selection criteria being used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString delimiter;

    /**
    *  <p>The max depth of the selection criteria</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int maxDepth = 0;

    /**
    *  <p>The minimum number of storage bytes percentage whose metrics will be selected.</p>  <p>You must choose a value greater than or equal to <code>1.0</code>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    float minStorageBytesPercentage = 0.0f;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::SelectionCriteria toAWS() const {
        Aws::S3Control::Model::SelectionCriteria awsSelectionCriteria;

        if (!(this->delimiter.IsEmpty())) {
            awsSelectionCriteria.SetDelimiter(TCHAR_TO_UTF8(*this->delimiter));
        }

        if (!(this->maxDepth == 0)) {
            awsSelectionCriteria.SetMaxDepth(this->maxDepth);
        }

        if (!(this->minStorageBytesPercentage == 0)) {
            awsSelectionCriteria.SetMinStorageBytesPercentage(this->minStorageBytesPercentage);
        }

        return awsSelectionCriteria;
    }

    bool IsEmpty() const {
        return this->delimiter.IsEmpty() && this->maxDepth == 0 && this->minStorageBytesPercentage == 0;
    }

    FAWSS3ControlSelectionCriteria &fromAWS(const Aws::S3Control::Model::SelectionCriteria &awsSelectionCriteria) {
        this->delimiter = UTF8_TO_TCHAR(awsSelectionCriteria.GetDelimiter().c_str());

		this->maxDepth = awsSelectionCriteria.GetMaxDepth();

        this->minStorageBytesPercentage = (float)awsSelectionCriteria.GetMinStorageBytesPercentage();

        return *this;
    }
#endif
};
