//
//  CashSuper.h
//  strategy
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CashStrategy : NSObject


/**

 根据输入应付金额, 计算实付金额, 该方法由子类实现

 @param money 应付金额
 @return 实付金额
 */
- (double)accepetCash:(double)money;

@end

NS_ASSUME_NONNULL_END
