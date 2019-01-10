//
//  Woman.m
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Woman.h"
#import "Action.h"

@implementation Woman

- (void)accept:(id<Action>)visitor {
    [visitor getWomanConclusion:self];
}

@end
