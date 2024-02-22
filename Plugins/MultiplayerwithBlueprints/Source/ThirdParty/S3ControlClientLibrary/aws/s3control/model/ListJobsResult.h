﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3control/S3Control_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/s3control/model/JobListDescriptor.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils
namespace S3Control
{
namespace Model
{
  class ListJobsResult
  {
  public:
    AWS_S3CONTROL_API ListJobsResult();
    AWS_S3CONTROL_API ListJobsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    AWS_S3CONTROL_API ListJobsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);


    /**
     * <p>If the <code>List Jobs</code> request produced more than the maximum number
     * of results, you can pass this value into a subsequent <code>List Jobs</code>
     * request in order to retrieve the next page of results.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>If the <code>List Jobs</code> request produced more than the maximum number
     * of results, you can pass this value into a subsequent <code>List Jobs</code>
     * request in order to retrieve the next page of results.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>If the <code>List Jobs</code> request produced more than the maximum number
     * of results, you can pass this value into a subsequent <code>List Jobs</code>
     * request in order to retrieve the next page of results.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = std::move(value); }

    /**
     * <p>If the <code>List Jobs</code> request produced more than the maximum number
     * of results, you can pass this value into a subsequent <code>List Jobs</code>
     * request in order to retrieve the next page of results.</p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>If the <code>List Jobs</code> request produced more than the maximum number
     * of results, you can pass this value into a subsequent <code>List Jobs</code>
     * request in order to retrieve the next page of results.</p>
     */
    inline ListJobsResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>If the <code>List Jobs</code> request produced more than the maximum number
     * of results, you can pass this value into a subsequent <code>List Jobs</code>
     * request in order to retrieve the next page of results.</p>
     */
    inline ListJobsResult& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>If the <code>List Jobs</code> request produced more than the maximum number
     * of results, you can pass this value into a subsequent <code>List Jobs</code>
     * request in order to retrieve the next page of results.</p>
     */
    inline ListJobsResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p>The list of current jobs and jobs that have ended within the last 30
     * days.</p>
     */
    inline const Aws::Vector<JobListDescriptor>& GetJobs() const{ return m_jobs; }

    /**
     * <p>The list of current jobs and jobs that have ended within the last 30
     * days.</p>
     */
    inline void SetJobs(const Aws::Vector<JobListDescriptor>& value) { m_jobs = value; }

    /**
     * <p>The list of current jobs and jobs that have ended within the last 30
     * days.</p>
     */
    inline void SetJobs(Aws::Vector<JobListDescriptor>&& value) { m_jobs = std::move(value); }

    /**
     * <p>The list of current jobs and jobs that have ended within the last 30
     * days.</p>
     */
    inline ListJobsResult& WithJobs(const Aws::Vector<JobListDescriptor>& value) { SetJobs(value); return *this;}

    /**
     * <p>The list of current jobs and jobs that have ended within the last 30
     * days.</p>
     */
    inline ListJobsResult& WithJobs(Aws::Vector<JobListDescriptor>&& value) { SetJobs(std::move(value)); return *this;}

    /**
     * <p>The list of current jobs and jobs that have ended within the last 30
     * days.</p>
     */
    inline ListJobsResult& AddJobs(const JobListDescriptor& value) { m_jobs.push_back(value); return *this; }

    /**
     * <p>The list of current jobs and jobs that have ended within the last 30
     * days.</p>
     */
    inline ListJobsResult& AddJobs(JobListDescriptor&& value) { m_jobs.push_back(std::move(value)); return *this; }


    
    inline const Aws::String& GetRequestId() const{ return m_requestId; }

    
    inline void SetRequestId(const Aws::String& value) { m_requestId = value; }

    
    inline void SetRequestId(Aws::String&& value) { m_requestId = std::move(value); }

    
    inline void SetRequestId(const char* value) { m_requestId.assign(value); }

    
    inline ListJobsResult& WithRequestId(const Aws::String& value) { SetRequestId(value); return *this;}

    
    inline ListJobsResult& WithRequestId(Aws::String&& value) { SetRequestId(std::move(value)); return *this;}

    
    inline ListJobsResult& WithRequestId(const char* value) { SetRequestId(value); return *this;}

  private:

    Aws::String m_nextToken;

    Aws::Vector<JobListDescriptor> m_jobs;

    Aws::String m_requestId;
  };

} // namespace Model
} // namespace S3Control
} // namespace Aws
