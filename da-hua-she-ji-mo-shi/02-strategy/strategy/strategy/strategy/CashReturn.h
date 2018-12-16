//
//  CashReturn.h
//  strategy
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "CashStrategy.h"

NS_ASSUME_NONNULL_BEGIN

@interface CashReturn : CashStrategy


/**
 初始化方法

 @param condition 满减条件, 如: 满300 返100,条件为 300
 @param ret 返现值
 @return 策略对象
 */
- (instancetype)initWithCondition:(double)condition andReturn:(double)ret;

@end

NS_ASSUME_NONNULL_END
