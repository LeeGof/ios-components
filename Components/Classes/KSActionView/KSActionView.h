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

#import <UIKit/UIKit.h>
#import "ARCHelper.h"

@protocol KSActionViewDelegate;

@interface KSActionView : NSObject

@property (nonatomic, assign) UIWindow *window;
@property (nonatomic, strong) UIView *inputView;
@property (nonatomic, readonly) BOOL hidden;
@property (nonatomic, assign) id<KSActionViewDelegate> delegate;

@property (nonatomic, copy) NSString *itemCancelString;
@property (nonatomic, copy) NSString *itemDoneString;

+ (KSActionView *)sharedInstance;

- (void)show;
- (void)dismiss;

@end

@protocol KSActionViewDelegate <NSObject>

- (void)actionViewWillShow:(KSActionView *)actionView;
- (void)actionViewDidShow:(KSActionView *)actionView;
- (void)actionView:(KSActionView *)actionView didClickDone:(BOOL)done;
- (void)actionViewWillDismiss:(KSActionView *)actionView;
- (void)actionViewDidDismiss:(KSActionView *)actionView;

@end
