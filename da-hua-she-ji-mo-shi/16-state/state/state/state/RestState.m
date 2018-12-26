//
//  RestState.m
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "RestState.h"
#import "Work.h"

@implementation RestState

- (void)writeProgram:(Work *)work {
    NSLog(@"当前时间: %f 点, 下班回家了", work.hour);
}
@end
