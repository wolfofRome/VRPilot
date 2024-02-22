/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3ObjectMetadata.h"

#endif

#include "Model/S3SSEAlgorithm.h"

#include "S3ObjectMetadata.generated.h"

USTRUCT(BlueprintType)
struct FS3ObjectMetadata {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString cacheControl;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString contentDisposition;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString contentEncoding;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString contentLanguage;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TMap<FString, FString> userMetadata;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int64 contentLength = 0;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString contentMD5;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString contentType;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime httpExpiresDate;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool requesterCharged = false;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3SSEAlgorithm SSEAlgorithm = EAWSS3SSEAlgorithm::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3ObjectMetadata toAWS() const {
        Aws::S3Control::Model::S3ObjectMetadata awsS3ObjectMetadata;

		if (!(this->cacheControl.IsEmpty())) {
            awsS3ObjectMetadata.SetCacheControl(TCHAR_TO_UTF8(*this->cacheControl));
        }

		if (!(this->contentDisposition.IsEmpty())) {
            awsS3ObjectMetadata.SetContentDisposition(TCHAR_TO_UTF8(*this->contentDisposition));
        }

		if (!(this->contentEncoding.IsEmpty())) {
            awsS3ObjectMetadata.SetContentEncoding(TCHAR_TO_UTF8(*this->contentEncoding));
        }

		if (!(this->contentLanguage.IsEmpty())) {
            awsS3ObjectMetadata.SetContentLanguage(TCHAR_TO_UTF8(*this->contentLanguage));
        }

        for (const TPair<FString, FString>& elem : this->userMetadata) {
            awsS3ObjectMetadata.AddUserMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (!(this->contentLength == 0)) {
            awsS3ObjectMetadata.SetContentLength(this->contentLength);
        }

		if (!(this->contentMD5.IsEmpty())) {
            awsS3ObjectMetadata.SetContentMD5(TCHAR_TO_UTF8(*this->contentMD5));
        }

		if (!(this->contentType.IsEmpty())) {
            awsS3ObjectMetadata.SetContentType(TCHAR_TO_UTF8(*this->contentType));
        }

        if (!(this->httpExpiresDate.ToUnixTimestamp() <= 0)) {
            awsS3ObjectMetadata.SetHttpExpiresDate(Aws::Utils::DateTime((int64_t)((this->httpExpiresDate - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(false)) {
            awsS3ObjectMetadata.SetRequesterCharged(this->requesterCharged);
        }

        switch(this->SSEAlgorithm) {
            case EAWSS3SSEAlgorithm::AES256:
                awsS3ObjectMetadata.SetSSEAlgorithm(Aws::S3Control::Model::S3SSEAlgorithm::AES256);
                break;
            case EAWSS3SSEAlgorithm::KMS:
                awsS3ObjectMetadata.SetSSEAlgorithm(Aws::S3Control::Model::S3SSEAlgorithm::KMS);
                break;
            default:
                break;
        }

        return awsS3ObjectMetadata;
    }

    bool IsEmpty() const {
        return this->cacheControl.IsEmpty() && this->contentDisposition.IsEmpty() && this->contentEncoding.IsEmpty() && this->contentLanguage.IsEmpty() && this->userMetadata.Num() == 0 && this->contentLength == 0 && this->contentMD5.IsEmpty() && this->contentType.IsEmpty() && httpExpiresDate.ToUnixTimestamp() <= 0 && false && SSEAlgorithm == EAWSS3SSEAlgorithm::NOT_SET;
    }

    FS3ObjectMetadata &fromAWS(const Aws::S3Control::Model::S3ObjectMetadata &awsS3ObjectMetadata) {
        this->cacheControl = UTF8_TO_TCHAR(awsS3ObjectMetadata.GetCacheControl().c_str());

        this->contentDisposition = UTF8_TO_TCHAR(awsS3ObjectMetadata.GetContentDisposition().c_str());

        this->contentEncoding = UTF8_TO_TCHAR(awsS3ObjectMetadata.GetContentEncoding().c_str());

        this->contentLanguage = UTF8_TO_TCHAR(awsS3ObjectMetadata.GetContentLanguage().c_str());

        this->userMetadata.Empty();
        for (const auto& elem : awsS3ObjectMetadata.GetUserMetadata()) {
            this->userMetadata.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }

        this->contentLength = (int64)awsS3ObjectMetadata.GetContentLength();

        this->contentMD5 = UTF8_TO_TCHAR(awsS3ObjectMetadata.GetContentMD5().c_str());

        this->contentType = UTF8_TO_TCHAR(awsS3ObjectMetadata.GetContentType().c_str());

        this->httpExpiresDate = FDateTime(1970, 1, 1) + FTimespan(awsS3ObjectMetadata.GetHttpExpiresDate().Millis() * ETimespan::TicksPerMillisecond);

        this->requesterCharged = awsS3ObjectMetadata.GetRequesterCharged();

        switch(awsS3ObjectMetadata.GetSSEAlgorithm()) {
            case Aws::S3Control::Model::S3SSEAlgorithm::NOT_SET:
                this->SSEAlgorithm = EAWSS3SSEAlgorithm::NOT_SET;
                break;
            case Aws::S3Control::Model::S3SSEAlgorithm::AES256:
                this->SSEAlgorithm = EAWSS3SSEAlgorithm::AES256;
                break;
            case Aws::S3Control::Model::S3SSEAlgorithm::KMS:
                this->SSEAlgorithm = EAWSS3SSEAlgorithm::KMS;
                break;
            default:
                this->SSEAlgorithm = EAWSS3SSEAlgorithm::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
