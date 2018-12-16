//
//  CashReturn.m
//  strategy
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "CashReturn.h"

@interface CashReturn ()

@property (nonatomic, assign) double condition;
@property (nonatomic, assign) double ret;
@end

@implementation CashReturn

#pragma mark - life cycle
- (instancetype)initWithCondition:(double)condition andReturn:(double)ret {
    self = [super init];
    if (self) {
        _condition = condition;
        _ret = ret;
    }
    return self;
}


#pragma mark - overwrite
- (double)accepetCash:(double)money {
    if (money < self.condition) {
        return money;
    }
    return money - self.ret;
}


@end
