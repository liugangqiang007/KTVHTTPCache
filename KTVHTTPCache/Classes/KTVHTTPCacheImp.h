//
//  KTVHTTPCacheImp.h
//  KTVHTTPCache
//
//  Created by Single on 2017/8/13.
//  Copyright © 2017年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KTVHCDataReader;
@class KTVHCDataRequest;
@class KTVHCDataCacheItem;


@interface KTVHTTPCache : NSObject


#pragma mark - HTTP Server

+ (void)proxyStart:(NSError **)error;
+ (void)proxyStop;

+ (NSString *)proxyURLStringWithOriginalURLString:(NSString *)urlString;


#pragma mark - Data Storage

- (KTVHCDataReader *)cacheConcurrentReaderWithRequest:(KTVHCDataRequest *)request;

- (KTVHCDataReader *)cacheSerialReaderWithRequest:(KTVHCDataRequest *)request;
- (void)cacheSerialReaderWithRequest:(KTVHCDataRequest *)request
                   completionHandler:(void(^)(KTVHCDataReader *))completionHandler;

- (NSArray <KTVHCDataCacheItem *> *)cacheFetchAllCacheItem;
- (KTVHCDataCacheItem *)cacheFetchCacheItemWithURLString:(NSString *)URLString;

- (void)cacheCleanAllCacheItem;
- (void)cacheCleanCacheItemWithURLString:(NSString *)URLString;


@end