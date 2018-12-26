//
//  AfternoonState.m
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "AfternoonState.h"
#import "Work.h"
#import "EveningState.h"

@implementation AfternoonState

- (void)writeProgram:(Work *)work {
    if (work.hour < 17) {
        NSLog(@"当前时间: %f 点, 下午状态还不错, 继续努力", work.hour);
    } else {
        work.state = [EveningState new];
        [work writeProgram];
    }
}
@end
