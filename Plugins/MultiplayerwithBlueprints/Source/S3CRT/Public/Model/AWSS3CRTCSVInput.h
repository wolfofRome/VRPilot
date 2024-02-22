/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CSVInput.h"

#endif

#include "Model/AWSS3CRTFileHeaderInfo.h"

#include "AWSS3CRTCSVInput.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCSVInput {
GENERATED_BODY()

    /**
    *  <p>Describes the first line of input. Valid values are:</p> <ul> <li> <p> <code>NONE</code>: First line is not a header.</p> </li> <li> <p> <code>IGNORE</code>: First line is a header, but you can't use the header values to indicate the column in an expression. You can use column position (such as _1, _2, …) to indicate the column (<code>SELECT s._1 FROM OBJECT s</code>).</p> </li> <li> <p> <code>Use</code>: First line is a header, and you can use the header value to identify a column in an expression (<code>SELECT "name" FROM OBJECT</code>). </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTFileHeaderInfo fileHeaderInfo = EAWSS3CRTFileHeaderInfo::NOT_SET;

    /**
    *  <p>A single character used to indicate that a row should be ignored when the character is present at the start of that row. You can specify any character to indicate a comment line.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString comments;

    /**
    *  <p>A single character used for escaping the quotation mark character inside an already escaped value. For example, the value """ a , b """ is parsed as " a , b ".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString quoteEscapeCharacter;

    /**
    *  <p>A single character used to separate individual records in the input. Instead of the default value, you can specify an arbitrary delimiter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString recordDelimiter;

    /**
    *  <p>A single character used to separate individual fields in a record. You can specify an arbitrary delimiter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString fieldDelimiter;

    /**
    *  <p>A single character used for escaping when the field delimiter is part of the value. For example, if the value is <code>a, b</code>, Amazon S3 wraps this field value in quotation marks, as follows: <code>" a , b "</code>.</p> <p>Type: String</p> <p>Default: <code>"</code> </p> <p>Ancestors: <code>CSV</code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString quoteCharacter;

    /**
    *  <p>Specifies that CSV field values may contain quoted record delimiters and such records should be allowed. Default value is FALSE. Setting this value to TRUE may lower performance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool allowQuotedRecordDelimiter = false;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::CSVInput toAWS() const {
        Aws::S3Crt::Model::CSVInput awsCSVInput;

        switch(this->fileHeaderInfo) {
            case EAWSS3CRTFileHeaderInfo::USE:
                awsCSVInput.SetFileHeaderInfo(Aws::S3Crt::Model::FileHeaderInfo::USE);
                break;
            case EAWSS3CRTFileHeaderInfo::IGNORE:
                awsCSVInput.SetFileHeaderInfo(Aws::S3Crt::Model::FileHeaderInfo::IGNORE);
                break;
            case EAWSS3CRTFileHeaderInfo::NONE:
                awsCSVInput.SetFileHeaderInfo(Aws::S3Crt::Model::FileHeaderInfo::NONE);
                break;
            default:
                break;
        }

        if (!(this->comments.IsEmpty())) {
            awsCSVInput.SetComments(TCHAR_TO_UTF8(*this->comments));
        }

        if (!(this->quoteEscapeCharacter.IsEmpty())) {
            awsCSVInput.SetQuoteEscapeCharacter(TCHAR_TO_UTF8(*this->quoteEscapeCharacter));
        }

        if (!(this->recordDelimiter.IsEmpty())) {
            awsCSVInput.SetRecordDelimiter(TCHAR_TO_UTF8(*this->recordDelimiter));
        }

        if (!(this->fieldDelimiter.IsEmpty())) {
            awsCSVInput.SetFieldDelimiter(TCHAR_TO_UTF8(*this->fieldDelimiter));
        }

        if (!(this->quoteCharacter.IsEmpty())) {
            awsCSVInput.SetQuoteCharacter(TCHAR_TO_UTF8(*this->quoteCharacter));
        }

        if (!(false)) {
            awsCSVInput.SetAllowQuotedRecordDelimiter(this->allowQuotedRecordDelimiter);
        }

        return awsCSVInput;
    }

    bool IsEmpty() const {
        return this->fileHeaderInfo == EAWSS3CRTFileHeaderInfo::NOT_SET && this->comments.IsEmpty() && this->quoteEscapeCharacter.IsEmpty() && this->recordDelimiter.IsEmpty() && this->fieldDelimiter.IsEmpty() && this->quoteCharacter.IsEmpty() && false && true;
    }
#endif
};
