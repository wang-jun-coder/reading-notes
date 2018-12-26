//
//  ForenoonState.m
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "ForenoonState.h"
#import "Work.h"
#import "NoonState.h"

@implementation ForenoonState

- (void)writeProgram:(Work *)work {
    if (work.hour < 12) {
        NSLog(@"当前时间: %f点, 上午工作, 精神百倍", work.hour);
    } else {
        work.state = [NoonState new];
        [work writeProgram];
    }
}

@end
