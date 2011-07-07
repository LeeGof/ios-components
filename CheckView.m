/*
 * CheckView.m
 *
 * Copyright 2011 Davide De Rosa
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#import "CheckView.h"

@implementation CheckView

@synthesize enabled;
@synthesize color;

- (id) initWithCoder:(NSCoder *)aDecoder
{
    if ((self = [super initWithCoder:aDecoder])) {
        width = self.frame.size.width / 8.0;

        path = CGPathCreateMutable();
        CGPathMoveToPoint(path, NULL, width, self.frame.size.height / 2);
        CGPathAddLineToPoint(path, NULL, self.frame.size.width * 0.4, self.frame.size.height - width);
        CGPathAddLineToPoint(path, NULL, self.frame.size.width - width, width);
    }
    return self;
}

- (void) dealloc
{
    CGPathRelease(path);
    [color release];

    [super dealloc];
}

- (void) setEnabled:(BOOL)aEnabled
{
    enabled = aEnabled;
    [self setNeedsDisplay];
}

- (void) drawRect:(CGRect)rect
{
    CGContextRef context = UIGraphicsGetCurrentContext();

    // background
    CGContextSetFillColorWithColor(context, self.backgroundColor.CGColor);
    CGContextFillRect(context, rect);

    // check mark
    if (enabled) {
        CGContextSetStrokeColorWithColor(context, color.CGColor);
        CGContextSetShouldAntialias(context, YES);
        CGContextSetLineCap(context, kCGLineCapRound);
        CGContextSetLineWidth(context, width);

        CGContextBeginPath(context);
        CGContextAddPath(context, path);
        CGContextStrokePath(context);
    }
}

@end
