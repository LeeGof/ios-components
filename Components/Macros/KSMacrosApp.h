//
// Copyright (c) 2011, Davide De Rosa
// All rights reserved.
//
// This code is distributed under the terms and conditions of the BSD license.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation and/or
// other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
// ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <Foundation/Foundation.h>

extern NSString *const KSAppLinkProtocol;
extern NSString *const KSAppLinkProtocolWeb;

extern NSString *const KSAppLinkFormat;
extern NSString *const KSAppDeveloperLinkFormat;

extern NSString *const KSAppGCLogin;

static inline NSString *KSAppVersion()
{
    return [[NSBundle mainBundle] infoDictionary][@"CFBundleShortVersionString"];
}

static inline NSString *KSAppBundleVersion()
{
    return [[NSBundle mainBundle] infoDictionary][(NSString *)kCFBundleVersionKey];
}

static inline NSString *KSAppFullVersion()
{
    return [NSString stringWithFormat:@"%@ (%@)", KSAppVersion(), KSAppBundleVersion()];
}

static inline NSString *KSAppVersionDescription()
{
    NSDictionary *info = [[NSBundle mainBundle] infoDictionary];
    NSString *appName = info[(NSString *)kCFBundleNameKey];
    NSString *appVersion = info[@"CFBundleShortVersionString"];
    NSString *appBuild = info[(NSString *)kCFBundleVersionKey];
    
    return [NSString stringWithFormat:@"%@ %@ (%@)", appName, appVersion, appBuild];
}

static inline void KSAppPrintVersion()
{
    NSLog(@"%@", KSAppVersionDescription());
}

static inline NSString *KSAppURL(const unsigned long appID)
{
    return [NSString stringWithFormat:KSAppLinkFormat, KSAppLinkProtocol, appID];
}

static inline NSString *KSAppDeveloperURL(const unsigned long developerID)
{
    return [NSString stringWithFormat:KSAppDeveloperLinkFormat, KSAppLinkProtocol, developerID];
}

static inline NSString *KSAppWebURL(const unsigned long appID)
{
    return [NSString stringWithFormat:KSAppLinkFormat, KSAppLinkProtocolWeb, appID];
}

static inline NSString *KSAppWebDeveloperURL(const unsigned long developerID)
{
    return [NSString stringWithFormat:KSAppDeveloperLinkFormat, KSAppLinkProtocolWeb, developerID];
}
