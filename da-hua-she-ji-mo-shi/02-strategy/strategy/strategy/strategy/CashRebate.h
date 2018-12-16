//
//  CashRebate.h
//  strategy
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "CashStrategy.h"

NS_ASSUME_NONNULL_BEGIN

@interface CashRebate : CashStrategy


/**
 初始化方法

 @param rebate 折扣
 @return 策略实例
 */
- (instancetype)initWithRebate:(double)rebate;

@end

NS_ASSUME_NONNULL_END
