//
//  CashContext.h
//  strategy
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CashContext : NSObject


/**
 初始化方法

 @param type 策略类型, 实际开发中建议使用枚举
 @return 策略上下文
 */
- (instancetype)initWithType:(NSString *)type;



/**
 计算实付款

 @param cash 应付金额
 @return 实付金额
 */
- (double)getResultWithCash:(double)cash;

@end

NS_ASSUME_NONNULL_END
