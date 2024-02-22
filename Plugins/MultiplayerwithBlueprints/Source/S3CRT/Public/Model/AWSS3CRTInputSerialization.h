/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/InputSerialization.h"

#endif

#include "Model/AWSS3CRTCSVInput.h"
#include "Model/AWSS3CRTCompressionType.h"
#include "Model/AWSS3CRTJSONInput.h"
#include "Model/AWSS3CRTParquetInput.h"

#include "AWSS3CRTInputSerialization.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTInputSerialization {
GENERATED_BODY()

    /**
    *  <p>Describes the serialization of a CSV-encoded object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTCSVInput cSV;

    /**
    *  <p>Specifies object's compression format. Valid values: NONE, GZIP, BZIP2. Default Value: NONE.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTCompressionType compressionType = EAWSS3CRTCompressionType::NOT_SET;

    /**
    *  <p>Specifies JSON as object's input serialization format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTJSONInput jSON;

    /**
    *  <p>Specifies Parquet as object's input serialization format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTParquetInput parquet;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::InputSerialization toAWS() const {
        Aws::S3Crt::Model::InputSerialization awsInputSerialization;

        if (!(this->cSV.IsEmpty())) {
            awsInputSerialization.SetCSV(this->cSV.toAWS());
        }

        switch(this->compressionType) {
            case EAWSS3CRTCompressionType::NONE:
                awsInputSerialization.SetCompressionType(Aws::S3Crt::Model::CompressionType::NONE);
                break;
            case EAWSS3CRTCompressionType::GZIP:
                awsInputSerialization.SetCompressionType(Aws::S3Crt::Model::CompressionType::GZIP);
                break;
            case EAWSS3CRTCompressionType::BZIP2:
                awsInputSerialization.SetCompressionType(Aws::S3Crt::Model::CompressionType::BZIP2);
                break;
            default:
                break;
        }

        if (!(this->jSON.IsEmpty())) {
            awsInputSerialization.SetJSON(this->jSON.toAWS());
        }

        if (!(this->parquet.IsEmpty())) {
            awsInputSerialization.SetParquet(this->parquet.toAWS());
        }

        return awsInputSerialization;
    }

    bool IsEmpty() const {
        return this->cSV.IsEmpty() && this->compressionType == EAWSS3CRTCompressionType::NOT_SET && this->jSON.IsEmpty() && this->parquet.IsEmpty();
    }
#endif
};
