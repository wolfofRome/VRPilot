/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/StorageClassAnalysisDataExport.h"

#endif

#include "Model/AWSS3CRTStorageClassAnalysisSchemaVersion.h"
#include "Model/AWSS3CRTAnalyticsExportDestination.h"

#include "AWSS3CRTStorageClassAnalysisDataExport.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTStorageClassAnalysisDataExport {
GENERATED_BODY()

    /**
    *  <p>The version of the output schema to use when exporting data. Must be <code>V_1</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTStorageClassAnalysisSchemaVersion outputSchemaVersion = EAWSS3CRTStorageClassAnalysisSchemaVersion::NOT_SET;

    /**
    *  <p>The place to store the data for an analysis.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTAnalyticsExportDestination destination;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::StorageClassAnalysisDataExport toAWS() const {
        Aws::S3Crt::Model::StorageClassAnalysisDataExport awsStorageClassAnalysisDataExport;
        switch(this->outputSchemaVersion) {
            case EAWSS3CRTStorageClassAnalysisSchemaVersion::V_1:
                awsStorageClassAnalysisDataExport.SetOutputSchemaVersion(Aws::S3Crt::Model::StorageClassAnalysisSchemaVersion::V_1);
                break;
            default:
                break;
        }

        if (!(this->destination.IsEmpty())) {
            awsStorageClassAnalysisDataExport.SetDestination(this->destination.toAWS());
        }

        return awsStorageClassAnalysisDataExport;
    }

    bool IsEmpty() const {
        return this->outputSchemaVersion == EAWSS3CRTStorageClassAnalysisSchemaVersion::NOT_SET && this->destination.IsEmpty();
    }

    FAWSS3CRTStorageClassAnalysisDataExport &fromAWS(const Aws::S3Crt::Model::StorageClassAnalysisDataExport &awsStorageClassAnalysisDataExport) {
        switch(awsStorageClassAnalysisDataExport.GetOutputSchemaVersion()) {
            case Aws::S3Crt::Model::StorageClassAnalysisSchemaVersion::NOT_SET:
                this->outputSchemaVersion = EAWSS3CRTStorageClassAnalysisSchemaVersion::NOT_SET;
                break;
            case Aws::S3Crt::Model::StorageClassAnalysisSchemaVersion::V_1:
                this->outputSchemaVersion = EAWSS3CRTStorageClassAnalysisSchemaVersion::V_1;
                break;
            default:
                this->outputSchemaVersion = EAWSS3CRTStorageClassAnalysisSchemaVersion::NOT_SET;
                break;
        }

        this->destination = FAWSS3CRTAnalyticsExportDestination().fromAWS(awsStorageClassAnalysisDataExport.GetDestination());

        return *this;
    }
#endif
};
