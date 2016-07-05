//
// Copyright 2016 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

@protocol GREYAnalyticsDelegate;

/**
 *  Provides methods for tracking EarlGrey usage using Google Analytics.
 *
 *  @remark To opt out of Analytics use GREYConfiguration and set config value for
 *          @c kGREYConfigKeyAnalyticsEnabled to @c NO before the instance tear down method
 *          (XCTest::tearDown) method returns. Sample code to opt out of analytics:
 *          @code
 *          [[GREYConfiguration sharedInstance] setValue:@(NO)
 *                                          forConfigKey:kGREYConfigKeyAnalyticsEnabled];
 *          @endcode
 */
@interface GREYAnalytics : NSObject

/**
 *  @return The current delegate class.
 */
+ (Class<GREYAnalyticsDelegate>)delegate;

/**
 *  Sets a delegate for custom handling of analytics payload data. To reset GREYAnalytics to its
 *  default behavior pass @c nil.
 */
+ (void)setDelegate:(Class<GREYAnalyticsDelegate>)delegate;

/**
 *  Usage data is sent via Google Analytics indicating completion of a test case, if a delegate is
 *  specified it is invoked to handle the analytics instead.
 */
+ (void)trackTestCaseCompletion;

@end
