//
//  Operation.h
//  simple-factory
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Operation : NSObject


/**
 运算相关所需要的输入值
 */
@property (nonatomic, assign) double numA;
@property (nonatomic, assign) double numB;


/**
 获取运算结果, 由子类重写

 @return 计算结果, 默认为0
 */
- (double)getResult;

@end

NS_ASSUME_NONNULL_END
