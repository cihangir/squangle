/*
 *  Copyright (c) Facebook, Inc. and its affiliates..
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree.
 *
 */

/*
 * toFuture is our interface for database operation using folly::Future.
 * It's completely compatible with the `Operation` interface, so to use
 * futures all you need is to pass the `Operation`.
 *
 */

#ifndef COMMON_ASYNC_MYSQL_FUTURE_ADAPTER_H
#define COMMON_ASYNC_MYSQL_FUTURE_ADAPTER_H

#include "squangle/mysql_client/DbResult.h"
#include "squangle/mysql_client/Operation.h"

#include <folly/futures/Future.h>

namespace facebook {
namespace common {
namespace mysql_client {

typedef std::shared_ptr<ConnectOperation> ConnectOperation_ptr;
typedef std::shared_ptr<QueryOperation> QueryOperation_ptr;
typedef std::shared_ptr<MultiQueryOperation> MultiQueryOperation_ptr;

// SemiFuture for ConnectOperation
folly::SemiFuture<ConnectResult> toSemiFuture(ConnectOperation* conn_op);
folly::SemiFuture<ConnectResult> toSemiFuture(ConnectOperation_ptr conn_op);

// SemiFuture for QueryOperation
folly::SemiFuture<DbQueryResult> toSemiFuture(QueryOperation* query_op);
folly::SemiFuture<DbQueryResult> toSemiFuture(QueryOperation_ptr& query_op);

// SemiFuture for MultiQueryOperation
folly::SemiFuture<DbMultiQueryResult> toSemiFuture(
    MultiQueryOperation* mquery_op);
folly::SemiFuture<DbMultiQueryResult> toSemiFuture(
    MultiQueryOperation_ptr& mquery_op);

// Future for ConnectOperation
folly::Future<ConnectResult> toFuture(ConnectOperation* conn_op);
folly::Future<ConnectResult> toFuture(ConnectOperation_ptr conn_op);

// Future for QueryOperation
folly::Future<DbQueryResult> toFuture(QueryOperation* query_op);
folly::Future<DbQueryResult> toFuture(QueryOperation_ptr& query_op);

// Future for MultiQueryOperation
folly::Future<DbMultiQueryResult> toFuture(MultiQueryOperation* mquery_op);
folly::Future<DbMultiQueryResult> toFuture(MultiQueryOperation_ptr& mquery_op);

// Trivial conversions are defined so that all Future uses are handled
// by this interface
folly::Future<ConnectResult> toFuture(folly::SemiFuture<ConnectResult>&& fut);
folly::Future<DbQueryResult> toFuture(folly::SemiFuture<DbQueryResult>&& fut);
folly::Future<DbMultiQueryResult> toFuture(
    folly::SemiFuture<DbMultiQueryResult>&& fut);
} // namespace mysql_client
} // namespace common
} // namespace facebook

#endif // COMMON_ASYNC_MYSQL_FUTURE_ADAPTER_H
