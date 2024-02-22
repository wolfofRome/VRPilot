/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/InputSerialization.h"

#endif

#include "Model/CSVInput.h"
#include "Model/CompressionType.h"
#include "Model/JSONInput.h"
#include "Model/ParquetInput.h"

#include "InputSerialization.generated.h"

USTRUCT(BlueprintType)
struct FInputSerialization {
GENERATED_BODY()

    /**
    *  <p>Describes the serialization of a CSV-encoded object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FCSVInput cSV;

    /**
    *  <p>Specifies object's compression format. Valid values: NONE, GZIP, BZIP2. Default Value: NONE.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSCompressionType compressionType = EAWSCompressionType::NOT_SET;

    /**
    *  <p>Specifies JSON as object's input serialization format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FJSONInput jSON;

    /**
    *  <p>Specifies Parquet as object's input serialization format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FParquetInput parquet;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::InputSerialization toAWS() const {
        Aws::S3::Model::InputSerialization awsInputSerialization;

        if (!(this->cSV.IsEmpty())) {
            awsInputSerialization.SetCSV(this->cSV.toAWS());
        }

        switch(this->compressionType) {
            case EAWSCompressionType::NONE:
                awsInputSerialization.SetCompressionType(Aws::S3::Model::CompressionType::NONE);
                break;
            case EAWSCompressionType::GZIP:
                awsInputSerialization.SetCompressionType(Aws::S3::Model::CompressionType::GZIP);
                break;
            case EAWSCompressionType::BZIP2:
                awsInputSerialization.SetCompressionType(Aws::S3::Model::CompressionType::BZIP2);
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
        return this->cSV.IsEmpty() && compressionType == EAWSCompressionType::NOT_SET && this->jSON.IsEmpty() && this->parquet.IsEmpty();
    }
#endif
};
