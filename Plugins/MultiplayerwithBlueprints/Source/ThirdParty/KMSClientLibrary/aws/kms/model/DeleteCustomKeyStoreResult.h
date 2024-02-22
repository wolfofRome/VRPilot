﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/kms/KMS_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace KMS
{
namespace Model
{
  class DeleteCustomKeyStoreResult
  {
  public:
    AWS_KMS_API DeleteCustomKeyStoreResult();
    AWS_KMS_API DeleteCustomKeyStoreResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_KMS_API DeleteCustomKeyStoreResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    
    inline const Aws::String& GetRequestId() const{ return m_requestId; }

    
    inline void SetRequestId(const Aws::String& value) { m_requestId = value; }

    
    inline void SetRequestId(Aws::String&& value) { m_requestId = std::move(value); }

    
    inline void SetRequestId(const char* value) { m_requestId.assign(value); }

    
    inline DeleteCustomKeyStoreResult& WithRequestId(const Aws::String& value) { SetRequestId(value); return *this;}

    
    inline DeleteCustomKeyStoreResult& WithRequestId(Aws::String&& value) { SetRequestId(std::move(value)); return *this;}

    
    inline DeleteCustomKeyStoreResult& WithRequestId(const char* value) { SetRequestId(value); return *this;}

  private:

    Aws::String m_requestId;
  };

} // namespace Model
} // namespace KMS
} // namespace Aws
