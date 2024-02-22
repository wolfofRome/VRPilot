/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CSVOutput.h"

#endif

#include "Model/AWSS3CRTQuoteFields.h"

#include "AWSS3CRTCSVOutput.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCSVOutput {
GENERATED_BODY()

    /**
    *  <p>Indicates whether to use quotation marks around output fields. </p> <ul> <li> <p> <code>ALWAYS</code>: Always use quotation marks for output fields.</p> </li> <li> <p> <code>ASNEEDED</code>: Use quotation marks for output fields when needed.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTQuoteFields quoteFields = EAWSS3CRTQuoteFields::NOT_SET;

    /**
    *  <p>The single character used for escaping the quote character inside an already escaped value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString quoteEscapeCharacter;

    /**
    *  <p>A single character used to separate individual records in the output. Instead of the default value, you can specify an arbitrary delimiter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString recordDelimiter;

    /**
    *  <p>The value used to separate individual fields in a record. You can specify an arbitrary delimiter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString fieldDelimiter;

    /**
    *  <p>A single character used for escaping when the field delimiter is part of the value. For example, if the value is <code>a, b</code>, Amazon S3 wraps this field value in quotation marks, as follows: <code>" a , b "</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString quoteCharacter;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::CSVOutput toAWS() const {
        Aws::S3Crt::Model::CSVOutput awsCSVOutput;

        switch(this->quoteFields) {
            case EAWSS3CRTQuoteFields::ALWAYS:
                awsCSVOutput.SetQuoteFields(Aws::S3Crt::Model::QuoteFields::ALWAYS);
                break;
            case EAWSS3CRTQuoteFields::ASNEEDED:
                awsCSVOutput.SetQuoteFields(Aws::S3Crt::Model::QuoteFields::ASNEEDED);
                break;
            default:
                break;
        }

        if (!(this->quoteEscapeCharacter.IsEmpty())) {
            awsCSVOutput.SetQuoteEscapeCharacter(TCHAR_TO_UTF8(*this->quoteEscapeCharacter));
        }

        if (!(this->recordDelimiter.IsEmpty())) {
            awsCSVOutput.SetRecordDelimiter(TCHAR_TO_UTF8(*this->recordDelimiter));
        }

        if (!(this->fieldDelimiter.IsEmpty())) {
            awsCSVOutput.SetFieldDelimiter(TCHAR_TO_UTF8(*this->fieldDelimiter));
        }

        if (!(this->quoteCharacter.IsEmpty())) {
            awsCSVOutput.SetQuoteCharacter(TCHAR_TO_UTF8(*this->quoteCharacter));
        }

        return awsCSVOutput;
    }

    bool IsEmpty() const {
        return this->quoteFields == EAWSS3CRTQuoteFields::NOT_SET && this->quoteEscapeCharacter.IsEmpty() && this->recordDelimiter.IsEmpty() && this->fieldDelimiter.IsEmpty() && this->quoteCharacter.IsEmpty();
    }
#endif
};
