//
//  Fund.m
//  facade
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Fund.h"

#import "Stock1.h"
#import "Stock2.h"
#import "Stock3.h"
#import "NationalDebt1.h"
#import "Realty1.h"

@interface Fund ()

@property (nonatomic, strong) Stock1 *gu1;
@property (nonatomic, strong) Stock2 *gu2;
@property (nonatomic, strong) Stock3 *gu3;
@property (nonatomic, strong) NationalDebt1 *nt1;
@property (nonatomic, strong) Realty1 *rt1;

@end

@implementation Fund

- (instancetype)init {
    self = [super init];
    if (self) {
        _gu1 = [Stock1 new];
        _gu2 = [Stock2 new];
        _gu3 = [Stock3 new];
        _nt1 = [NationalDebt1 new];
        _rt1 = [Realty1 new];
    }
    return self;
}


- (void)buyFund {
    // 注意: 各子系统方法未必相同, 此处相当于组合
    [self.gu1 buy];
    [self.gu2 buy];
    [self.gu3 buy];
    [self.nt1 buy];
    [self.rt1 buy];
}

- (void)sellFund {
    [self.gu1 sell];
    [self.gu2 sell];
    [self.gu3 sell];
    [self.nt1 sell];
    [self.rt1 sell];
}

@end
