//
//  Man.m
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Man.h"
#import "Action.h"

@implementation Man

- (void)accept:(id<Action>)visitor {
    [visitor getManConclusion:self];
}

@end
