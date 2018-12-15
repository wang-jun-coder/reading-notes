//
//  OperationFactory.h
//  simple-factory
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Operation.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationFactory : NSObject

/**
 简单工厂方法
 
 @param operation 运算符
 @return 运算对象
 */
+ (Operation *)createOperation:(NSString *)operation;

@end

NS_ASSUME_NONNULL_END
