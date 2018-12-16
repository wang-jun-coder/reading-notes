//
//  CashRebate.m
//  strategy
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "CashRebate.h"

@interface CashRebate ()

@property (nonatomic, assign) double rebate;

@end

@implementation CashRebate

#pragma mark - life cycle
- (instancetype)initWithRebate:(double)rebate {
    self = [super init];
    if (self) {
        _rebate = rebate;
    }
    return self;
}


#pragma mark - overwrite
- (double)accepetCash:(double)money {
    return money*self.rebate;
}

@end
