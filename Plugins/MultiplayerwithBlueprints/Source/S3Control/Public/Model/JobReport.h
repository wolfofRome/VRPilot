/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobReport.h"

#endif

#include "Model/JobReportFormat.h"
#include "Model/JobReportScope.h"

#include "JobReport.generated.h"

USTRUCT(BlueprintType)
struct FJobReport {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) for the bucket where specified job-completion report will be stored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>The format of the specified job-completion report.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSJobReportFormat format = EAWSJobReportFormat::NOT_SET;

    /**
    *  <p>Indicates whether the specified job will generate a job-completion report.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool enabled = false;

    /**
    *  <p>An optional prefix to describe where in the specified bucket the job-completion report will be stored. Amazon S3 will store the job-completion report at &lt;prefix&gt;/job-&lt;job-id&gt;/report.json.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString prefix;

    /**
    *  <p>Indicates whether the job-completion report will include details of all tasks or only failed tasks.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSJobReportScope reportScope = EAWSJobReportScope::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::JobReport toAWS() const {
        Aws::S3Control::Model::JobReport awsJobReport;

		if (!(this->bucket.IsEmpty())) {
            awsJobReport.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        switch(this->format) {
            case EAWSJobReportFormat::Report_CSV_20180820:
                awsJobReport.SetFormat(Aws::S3Control::Model::JobReportFormat::Report_CSV_20180820);
                break;
            default:
                break;
		}

        if (!(false)) {
            awsJobReport.SetEnabled(this->enabled);
        }

		if (!(this->prefix.IsEmpty())) {
            awsJobReport.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        switch(this->reportScope) {
            case EAWSJobReportScope::AllTasks:
                awsJobReport.SetReportScope(Aws::S3Control::Model::JobReportScope::AllTasks);
                break;
            case EAWSJobReportScope::FailedTasksOnly:
                awsJobReport.SetReportScope(Aws::S3Control::Model::JobReportScope::FailedTasksOnly);
                break;
            default:
                break;
		}

        return awsJobReport;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && format == EAWSJobReportFormat::NOT_SET && false && this->prefix.IsEmpty() && reportScope == EAWSJobReportScope::NOT_SET;
    }

    FJobReport &fromAWS(const Aws::S3Control::Model::JobReport &awsJobReport) {
        this->bucket = UTF8_TO_TCHAR(awsJobReport.GetBucket().c_str());

        switch(awsJobReport.GetFormat()) {
            case Aws::S3Control::Model::JobReportFormat::NOT_SET:
                this->format = EAWSJobReportFormat::NOT_SET;
                break;
            case Aws::S3Control::Model::JobReportFormat::Report_CSV_20180820:
                this->format = EAWSJobReportFormat::Report_CSV_20180820;
                break;
            default:
                this->format = EAWSJobReportFormat::NOT_SET;
                break;
        }

        this->enabled = awsJobReport.GetEnabled();

        this->prefix = UTF8_TO_TCHAR(awsJobReport.GetPrefix().c_str());

        switch(awsJobReport.GetReportScope()) {
            case Aws::S3Control::Model::JobReportScope::NOT_SET:
                this->reportScope = EAWSJobReportScope::NOT_SET;
                break;
            case Aws::S3Control::Model::JobReportScope::AllTasks:
                this->reportScope = EAWSJobReportScope::AllTasks;
                break;
            case Aws::S3Control::Model::JobReportScope::FailedTasksOnly:
                this->reportScope = EAWSJobReportScope::FailedTasksOnly;
                break;
            default:
                this->reportScope = EAWSJobReportScope::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
