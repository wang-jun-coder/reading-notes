//
//  SleepingState.m
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "SleepingState.h"
#import "Work.h"

@implementation SleepingState

- (void)writeProgram:(Work *)work {
    NSLog(@"当前时间: %f 点, 不行了, 睡着了", work.hour);
}
@end
