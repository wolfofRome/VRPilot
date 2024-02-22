/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetObjectAttributesParts.h"

#endif

#include "Model/AWSS3ObjectPart.h"

#include "AWSS3GetObjectAttributesParts.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3GetObjectAttributesParts {
GENERATED_BODY()

    /**
    *  <p>The total number of parts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int totalPartsCount = 0;

    /**
    *  <p>The marker for the current part.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int partNumberMarker = 0;

    /**
    *  <p>When a list is truncated, this element specifies the last part in the list, as well as the value to use for the <code>PartNumberMarker</code> request parameter in a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int nextPartNumberMarker = 0;

    /**
    *  <p>The maximum number of parts allowed in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int maxParts = 0;

    /**
    *  <p>Indicates whether the returned list of parts is truncated. A value of <code>true</code> indicates that the list was truncated. A list can be truncated if the number of parts exceeds the limit returned in the <code>MaxParts</code> element.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isTruncated = false;

    /**
    *  <p>A container for elements related to a particular part. A response can contain zero or more <code>Parts</code> elements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FAWSS3ObjectPart> parts;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FAWSS3GetObjectAttributesParts &fromAWS(const Aws::S3::Model::GetObjectAttributesParts &awsGetObjectAttributesParts) {
		this->totalPartsCount = awsGetObjectAttributesParts.GetTotalPartsCount();

		this->partNumberMarker = awsGetObjectAttributesParts.GetPartNumberMarker();

		this->nextPartNumberMarker = awsGetObjectAttributesParts.GetNextPartNumberMarker();

		this->maxParts = awsGetObjectAttributesParts.GetMaxParts();

        this->isTruncated = awsGetObjectAttributesParts.GetIsTruncated();

        this->parts.Empty();
        for (const Aws::S3::Model::ObjectPart& elem : awsGetObjectAttributesParts.GetParts()) {
            this->parts.Add(FAWSS3ObjectPart().fromAWS(elem));
        }

        return *this;
    }
#endif
};
