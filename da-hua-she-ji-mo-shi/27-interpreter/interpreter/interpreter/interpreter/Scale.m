//
//  Scale.m
//  interpreter
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Scale.h"
#import "PlayContext.h"

@implementation Scale
- (void)interpreter:(PlayContext *)context {
    if (!context.playText || context.playText.length == 0) {
        return;
    }
    NSString *playKey = [context.playText substringWithRange:NSMakeRange(0, 1)];
    context.playText = [context.playText substringFromIndex:2];
    CGFloat playValue = [[context.playText substringWithRange:
                          NSMakeRange(0,
                                      [context.playText rangeOfString:@" "].location)]
                         floatValue];
    context.playText = [context.playText substringFromIndex:[context.playText rangeOfString:@" "].location + 1];
    [self excuteWithKey:playKey andValue:playValue];
}

- (void)excuteWithKey:(NSString *)key andValue:(CGFloat)value {
    NSDictionary *scaleDic = @{@"1":@"低音", @"2":@"中音", @"3":@"高音"};
    NSString *scale = [scaleDic objectForKey:[NSString stringWithFormat:@"%li", (long)value]];
    NSLog(@"%@", scale);
}


@end
