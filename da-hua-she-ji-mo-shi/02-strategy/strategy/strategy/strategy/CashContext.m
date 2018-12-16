//
//  CashContext.m
//  strategy
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "CashContext.h"

#import "CashStrategy.h"
#import "CashNormal.h"
#import "CashRebate.h"
#import "CashReturn.h"

@interface CashContext ()

@property (nonatomic, strong) CashStrategy *cs;

@end

@implementation CashContext

- (instancetype)initWithType:(NSString *)type {
    self = [super init];
    
    if ([type isEqualToString:@"正常收费"]) {
        _cs = [[CashNormal alloc] init];
    }
    if ([type isEqualToString:@"满300返100"]) {
        _cs = [[CashReturn alloc] initWithCondition:300 andReturn:100];
    }
    if ([type isEqualToString:@"打8折"]) {
        _cs = [[CashRebate alloc] initWithRebate:0.8];
    }
    
    return self;
}


- (double)getResultWithCash:(double)cash {
    return [self.cs accepetCash:cash];
}

@end
