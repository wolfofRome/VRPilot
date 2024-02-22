/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CSVInput.h"

#endif

#include "Model/FileHeaderInfo.h"

#include "CSVInput.generated.h"

USTRUCT(BlueprintType)
struct FCSVInput {
GENERATED_BODY()

    /**
    *  <p>Describes the first line of input. Valid values are:</p> <ul> <li> <p> <code>NONE</code>: First line is not a header.</p> </li> <li> <p> <code>IGNORE</code>: First line is a header, but you can't use the header values to indicate the column in an expression. You can use column position (such as _1, _2, …) to indicate the column (<code>SELECT s._1 FROM OBJECT s</code>).</p> </li> <li> <p> <code>Use</code>: First line is a header, and you can use the header value to identify a column in an expression (<code>SELECT "name" FROM OBJECT</code>). </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSFileHeaderInfo fileHeaderInfo = EAWSFileHeaderInfo::NOT_SET;

    /**
    *  <p>A single character used to indicate that a row should be ignored when the character is present at the start of that row. You can specify any character to indicate a comment line.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString comments;

    /**
    *  <p>A single character used for escaping the quotation mark character inside an already escaped value. For example, the value """ a , b """ is parsed as " a , b ".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString quoteEscapeCharacter;

    /**
    *  <p>A single character used to separate individual records in the input. Instead of the default value, you can specify an arbitrary delimiter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString recordDelimiter;

    /**
    *  <p>A single character used to separate individual fields in a record. You can specify an arbitrary delimiter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString fieldDelimiter;

    /**
    *  <p>A single character used for escaping when the field delimiter is part of the value. For example, if the value is <code>a, b</code>, Amazon S3 wraps this field value in quotation marks, as follows: <code>" a , b "</code>.</p> <p>Type: String</p> <p>Default: <code>"</code> </p> <p>Ancestors: <code>CSV</code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString quoteCharacter;

    /**
    *  <p>Specifies that CSV field values may contain quoted record delimiters and such records should be allowed. Default value is FALSE. Setting this value to TRUE may lower performance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool allowQuotedRecordDelimiter = false;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::CSVInput toAWS() const {
        Aws::S3::Model::CSVInput awsCSVInput;

        switch(this->fileHeaderInfo) {
            case EAWSFileHeaderInfo::USE:
                awsCSVInput.SetFileHeaderInfo(Aws::S3::Model::FileHeaderInfo::USE);
                break;
            case EAWSFileHeaderInfo::IGNORE:
                awsCSVInput.SetFileHeaderInfo(Aws::S3::Model::FileHeaderInfo::IGNORE);
                break;
            case EAWSFileHeaderInfo::NONE:
                awsCSVInput.SetFileHeaderInfo(Aws::S3::Model::FileHeaderInfo::NONE);
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
        return this->fileHeaderInfo == EAWSFileHeaderInfo::NOT_SET && this->comments.IsEmpty() && this->quoteEscapeCharacter.IsEmpty() && this->recordDelimiter.IsEmpty() && this->fieldDelimiter.IsEmpty() && this->quoteCharacter.IsEmpty() && false;
    }
#endif
};
