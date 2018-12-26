//
//  NoonState.m
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "NoonState.h"
#import "Work.h"
#import "AfternoonState.h"

@implementation NoonState

- (void)writeProgram:(Work *)work {
    if (work.hour < 13) {
        NSLog(@"当前时间: %f点, 饿了, 午饭; 犯困, 午休", work.hour);
    } else {
        work.state = [AfternoonState new];
        [work writeProgram];
    }
}

@end
