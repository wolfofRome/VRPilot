/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobManifestSpec.h"

#endif

#include "Model/JobManifestFormat.h"
#include "Model/JobManifestFieldName.h"

#include "JobManifestSpec.generated.h"

USTRUCT(BlueprintType)
struct FJobManifestSpec {
GENERATED_BODY()

    /**
    *  <p>Indicates which of the available formats the specified manifest uses.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSJobManifestFormat format = EAWSJobManifestFormat::NOT_SET;

    /**
    *  <p>If the specified manifest object is in the <code>S3BatchOperations_CSV_20180820</code> format, this element describes which columns contain the required data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<EAWSJobManifestFieldName> fields;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::JobManifestSpec toAWS() const {
        Aws::S3Control::Model::JobManifestSpec awsJobManifestSpec;

        switch(this->format) {
            case EAWSJobManifestFormat::S3BatchOperations_CSV_20180820:
                awsJobManifestSpec.SetFormat(Aws::S3Control::Model::JobManifestFormat::S3BatchOperations_CSV_20180820);
                break;
            case EAWSJobManifestFormat::S3InventoryReport_CSV_20161130:
                awsJobManifestSpec.SetFormat(Aws::S3Control::Model::JobManifestFormat::S3InventoryReport_CSV_20161130);
                break;
            default:
                break;
        }

        for (const EAWSJobManifestFieldName& elem : this->fields) {
            // @TODO: check
		    switch(elem) {
                case EAWSJobManifestFieldName::Ignore:
                    awsJobManifestSpec.AddFields(Aws::S3Control::Model::JobManifestFieldName::Ignore);
                    break;
                case EAWSJobManifestFieldName::Bucket:
                    awsJobManifestSpec.AddFields(Aws::S3Control::Model::JobManifestFieldName::Bucket);
                    break;
                case EAWSJobManifestFieldName::Key:
                    awsJobManifestSpec.AddFields(Aws::S3Control::Model::JobManifestFieldName::Key);
                    break;
                case EAWSJobManifestFieldName::VersionId:
                    awsJobManifestSpec.AddFields(Aws::S3Control::Model::JobManifestFieldName::VersionId);
                    break;
                default:
                    break;
            };
        }

        return awsJobManifestSpec;
    }

    bool IsEmpty() const {
        return format == EAWSJobManifestFormat::NOT_SET && this->fields.Num() == 0;
    }

    FJobManifestSpec &fromAWS(const Aws::S3Control::Model::JobManifestSpec &awsJobManifestSpec) {
        switch(awsJobManifestSpec.GetFormat()) {
            case Aws::S3Control::Model::JobManifestFormat::NOT_SET:
                this->format = EAWSJobManifestFormat::NOT_SET;
                break;
            case Aws::S3Control::Model::JobManifestFormat::S3BatchOperations_CSV_20180820:
                this->format = EAWSJobManifestFormat::S3BatchOperations_CSV_20180820;
                break;
            case Aws::S3Control::Model::JobManifestFormat::S3InventoryReport_CSV_20161130:
                this->format = EAWSJobManifestFormat::S3InventoryReport_CSV_20161130;
                break;
            default:
                this->format = EAWSJobManifestFormat::NOT_SET;
                break;
        }

        this->fields.Empty();
        for (const Aws::S3Control::Model::JobManifestFieldName& elem : awsJobManifestSpec.GetFields()) {
            switch(elem) {
                case Aws::S3Control::Model::JobManifestFieldName::NOT_SET:
                    this->fields.Add(EAWSJobManifestFieldName::NOT_SET);
                    break;
                case Aws::S3Control::Model::JobManifestFieldName::Ignore:
                    this->fields.Add(EAWSJobManifestFieldName::Ignore);
                    break;
                case Aws::S3Control::Model::JobManifestFieldName::Bucket:
                    this->fields.Add(EAWSJobManifestFieldName::Bucket);
                    break;
                case Aws::S3Control::Model::JobManifestFieldName::Key:
                    this->fields.Add(EAWSJobManifestFieldName::Key);
                    break;
                case Aws::S3Control::Model::JobManifestFieldName::VersionId:
                    this->fields.Add(EAWSJobManifestFieldName::VersionId);
                    break;
                default:
                    this->fields.Add(EAWSJobManifestFieldName::NOT_SET);
                    break;
		    };
        }

        return *this;
    }
#endif
};
