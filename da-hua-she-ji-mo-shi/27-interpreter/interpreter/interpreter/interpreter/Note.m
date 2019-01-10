//
//  Note.m
//  interpreter
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Note.h"
#import "PlayContext.h"

@implementation Note

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
    NSDictionary *noteDic = @{@"C":@"1", @"D":@"2", @"E":@"3", @"F":@"4", @"G":@"5", @"A":@"6", @"B":@"7"};
    NSString *note = [noteDic objectForKey:key];
    NSLog(@"%@", note);
}

@end
