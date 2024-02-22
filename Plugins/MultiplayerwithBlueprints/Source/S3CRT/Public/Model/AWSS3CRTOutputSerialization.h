/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/OutputSerialization.h"

#endif

#include "Model/AWSS3CRTCSVOutput.h"
#include "Model/AWSS3CRTJSONOutput.h"

#include "AWSS3CRTOutputSerialization.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTOutputSerialization {
GENERATED_BODY()

    /**
    *  <p>Describes the serialization of CSV-encoded Select results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTCSVOutput cSV;

    /**
    *  <p>Specifies JSON as request's output serialization format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTJSONOutput jSON;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::OutputSerialization toAWS() const {
        Aws::S3Crt::Model::OutputSerialization awsOutputSerialization;

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
