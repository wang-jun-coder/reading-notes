//
//  Work.m
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Work.h"
#import "ForenoonState.h"


@implementation Work

- (instancetype)init {
    self = [super init];
    if (self) {
        _state = [ForenoonState new];
    }
    return self;
}

- (void)writeProgram {
    [self.state writeProgram:self];
}




@end
