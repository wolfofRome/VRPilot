/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ScanRange.h"

#endif

#include "AWSS3CRTScanRange.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTScanRange {
GENERATED_BODY()

    /**
    *  <p>Specifies the start of the byte range. This parameter is optional. Valid values: non-negative integers. The default value is 0. If only start is supplied, it means scan from that point to the end of the file.For example; <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;/scanrange&gt;</code> means scan from byte 50 until the end of the file.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 start = 0;

    /**
    *  <p>Specifies the end of the byte range. This parameter is optional. Valid values: non-negative integers. The default value is one less than the size of the object being queried. If only the End parameter is supplied, it is interpreted to mean scan the last N bytes of the file. For example, <code>&lt;scanrange&gt;&lt;end&gt;50&lt;/end&gt;&lt;/scanrange&gt;</code> means scan the last 50 bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int64 end = 0;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ScanRange toAWS() const {
        Aws::S3Crt::Model::ScanRange awsScanRange;

        if (!(this->start == 0)) {
            awsScanRange.SetStart(this->start);
        }

        if (!(this->end == 0)) {
            awsScanRange.SetEnd(this->end);
        }

        return awsScanRange;
    }

    bool IsEmpty() const {
        return this->start == 0 && this->end == 0;
    }
#endif
};
