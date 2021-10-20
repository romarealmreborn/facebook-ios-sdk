// Copyright (c) 2014-present, Facebook, Inc. All rights reserved.
//
// You are hereby granted a non-exclusive, worldwide, royalty-free license to use,
// copy, modify, and distribute this software in source code or binary form for use
// in connection with the web services and APIs provided by Facebook.
//
// As with any software that integrates with the Facebook platform, your use of
// this software is subject to the Facebook Developer Principles and Policies
// [http://developers.facebook.com/policy/]. This copyright notice shall be
// included in all copies or substantial portions of the software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import "FBSDKProfile.h"

NS_ASSUME_NONNULL_BEGIN

@interface FBSDKProfile (Testing)

@property (class, nullable, nonatomic) id<FBSDKDataPersisting> store;
@property (class, nullable, nonatomic) Class<FBSDKAccessTokenProviding> accessTokenProvider;
@property (class, nullable, nonatomic) id<FBSDKSettings> settings;
@property (class, nullable, nonatomic) id<FBSDKNotificationPosting, FBSDKNotificationObserving> notificationCenter;
@property (class, nullable, nonatomic) id<FBSDKURLHosting> urlHoster;

+ (void)setCurrentProfile:(nullable FBSDKProfile *)profile
   shouldPostNotification:(BOOL)shouldPostNotification;

+ (void)reset;

+ (void)resetCurrentProfileCache;

+ (NSString *)graphPathForToken:(FBSDKAccessToken *)token;

+ (void)loadProfileWithToken:(nullable FBSDKAccessToken *)token
                graphRequest:(id<FBSDKGraphRequest>)request
                  completion:(nullable FBSDKProfileBlock)completion
NS_SWIFT_NAME(load(token:request:completion:));

@end

NS_ASSUME_NONNULL_END
