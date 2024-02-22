﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3control/S3Control_EXPORTS.h>
#include <aws/s3control/S3ControlRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace S3Control
{
namespace Model
{

  /**
   */
  class DeleteBucketTaggingRequest : public S3ControlRequest
  {
  public:
    AWS_S3CONTROL_API DeleteBucketTaggingRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DeleteBucketTagging"; }

    AWS_S3CONTROL_API Aws::String SerializePayload() const override;

    AWS_S3CONTROL_API Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;

    /**
     * Helper function to collect parameters (configurable and static hardcoded) required for endpoint computation.
     */
    AWS_S3CONTROL_API EndpointParameters GetEndpointContextParams() const override;

    /**
     * <p>The Amazon Web Services account ID of the Outposts bucket tag set to be
     * removed.</p>
     */
    inline const Aws::String& GetAccountId() const{ return m_accountId; }

    /**
     * <p>The Amazon Web Services account ID of the Outposts bucket tag set to be
     * removed.</p>
     */
    inline bool AccountIdHasBeenSet() const { return m_accountIdHasBeenSet; }

    /**
     * <p>The Amazon Web Services account ID of the Outposts bucket tag set to be
     * removed.</p>
     */
    inline void SetAccountId(const Aws::String& value) { m_accountIdHasBeenSet = true; m_accountId = value; }

    /**
     * <p>The Amazon Web Services account ID of the Outposts bucket tag set to be
     * removed.</p>
     */
    inline void SetAccountId(Aws::String&& value) { m_accountIdHasBeenSet = true; m_accountId = std::move(value); }

    /**
     * <p>The Amazon Web Services account ID of the Outposts bucket tag set to be
     * removed.</p>
     */
    inline void SetAccountId(const char* value) { m_accountIdHasBeenSet = true; m_accountId.assign(value); }

    /**
     * <p>The Amazon Web Services account ID of the Outposts bucket tag set to be
     * removed.</p>
     */
    inline DeleteBucketTaggingRequest& WithAccountId(const Aws::String& value) { SetAccountId(value); return *this;}

    /**
     * <p>The Amazon Web Services account ID of the Outposts bucket tag set to be
     * removed.</p>
     */
    inline DeleteBucketTaggingRequest& WithAccountId(Aws::String&& value) { SetAccountId(std::move(value)); return *this;}

    /**
     * <p>The Amazon Web Services account ID of the Outposts bucket tag set to be
     * removed.</p>
     */
    inline DeleteBucketTaggingRequest& WithAccountId(const char* value) { SetAccountId(value); return *this;}


    /**
     * <p>The bucket ARN that has the tag set to be removed.</p> <p>For using this
     * parameter with Amazon S3 on Outposts with the REST API, you must specify the
     * name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3
     * on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN
     * of the bucket accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>.
     * For example, to access the bucket <code>reports</code> through Outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>.
     * The value must be URL encoded. </p>
     */
    inline const Aws::String& GetBucket() const{ return m_bucket; }

    /**
     * <p>The bucket ARN that has the tag set to be removed.</p> <p>For using this
     * parameter with Amazon S3 on Outposts with the REST API, you must specify the
     * name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3
     * on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN
     * of the bucket accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>.
     * For example, to access the bucket <code>reports</code> through Outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>.
     * The value must be URL encoded. </p>
     */
    inline bool BucketHasBeenSet() const { return m_bucketHasBeenSet; }

    /**
     * <p>The bucket ARN that has the tag set to be removed.</p> <p>For using this
     * parameter with Amazon S3 on Outposts with the REST API, you must specify the
     * name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3
     * on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN
     * of the bucket accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>.
     * For example, to access the bucket <code>reports</code> through Outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>.
     * The value must be URL encoded. </p>
     */
    inline void SetBucket(const Aws::String& value) { m_bucketHasBeenSet = true; m_bucket = value; }

    /**
     * <p>The bucket ARN that has the tag set to be removed.</p> <p>For using this
     * parameter with Amazon S3 on Outposts with the REST API, you must specify the
     * name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3
     * on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN
     * of the bucket accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>.
     * For example, to access the bucket <code>reports</code> through Outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>.
     * The value must be URL encoded. </p>
     */
    inline void SetBucket(Aws::String&& value) { m_bucketHasBeenSet = true; m_bucket = std::move(value); }

    /**
     * <p>The bucket ARN that has the tag set to be removed.</p> <p>For using this
     * parameter with Amazon S3 on Outposts with the REST API, you must specify the
     * name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3
     * on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN
     * of the bucket accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>.
     * For example, to access the bucket <code>reports</code> through Outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>.
     * The value must be URL encoded. </p>
     */
    inline void SetBucket(const char* value) { m_bucketHasBeenSet = true; m_bucket.assign(value); }

    /**
     * <p>The bucket ARN that has the tag set to be removed.</p> <p>For using this
     * parameter with Amazon S3 on Outposts with the REST API, you must specify the
     * name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3
     * on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN
     * of the bucket accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>.
     * For example, to access the bucket <code>reports</code> through Outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>.
     * The value must be URL encoded. </p>
     */
    inline DeleteBucketTaggingRequest& WithBucket(const Aws::String& value) { SetBucket(value); return *this;}

    /**
     * <p>The bucket ARN that has the tag set to be removed.</p> <p>For using this
     * parameter with Amazon S3 on Outposts with the REST API, you must specify the
     * name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3
     * on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN
     * of the bucket accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>.
     * For example, to access the bucket <code>reports</code> through Outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>.
     * The value must be URL encoded. </p>
     */
    inline DeleteBucketTaggingRequest& WithBucket(Aws::String&& value) { SetBucket(std::move(value)); return *this;}

    /**
     * <p>The bucket ARN that has the tag set to be removed.</p> <p>For using this
     * parameter with Amazon S3 on Outposts with the REST API, you must specify the
     * name and the x-amz-outpost-id as well.</p> <p>For using this parameter with S3
     * on Outposts with the Amazon Web Services SDK and CLI, you must specify the ARN
     * of the bucket accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/bucket/&lt;my-bucket-name&gt;</code>.
     * For example, to access the bucket <code>reports</code> through Outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/bucket/reports</code>.
     * The value must be URL encoded. </p>
     */
    inline DeleteBucketTaggingRequest& WithBucket(const char* value) { SetBucket(value); return *this;}

  private:

    Aws::String m_accountId;
    bool m_accountIdHasBeenSet = false;

    Aws::String m_bucket;
    bool m_bucketHasBeenSet = false;
  };

} // namespace Model
} // namespace S3Control
} // namespace Aws
