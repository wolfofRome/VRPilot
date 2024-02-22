/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/OutputSerialization.h"

#endif

#include "Model/CSVOutput.h"
#include "Model/JSONOutput.h"

#include "OutputSerialization.generated.h"

USTRUCT(BlueprintType)
struct FOutputSerialization {
GENERATED_BODY()

    /**
    *  <p>Describes the serialization of CSV-encoded Select results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FCSVOutput cSV;

    /**
    *  <p>Specifies JSON as request's output serialization format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FJSONOutput jSON;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::OutputSerialization toAWS() const {
        Aws::S3::Model::OutputSerialization awsOutputSerialization;

        if (!(this->cSV.IsEmpty())) {
            awsOutputSerialization.SetCSV(this->cSV.toAWS());
        }

        if (!(this->jSON.IsEmpty())) {
            awsOutputSerialization.SetJSON(this->jSON.toAWS());
        }

        return awsOutputSerialization;
    }

    bool IsEmpty() const {
        return this->cSV.IsEmpty() && this->jSON.IsEmpty();
    }
#endif
};
