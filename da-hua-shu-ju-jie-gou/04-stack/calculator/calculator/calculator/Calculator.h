//
//  Calculator.h
//  calculator
//
//  Created by 王俊 on 2019/3/12.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h

#include <stdio.h>
#include "../stack/Stack.h"


/**
 计算四则运算表达式的值

 @param expression 表达式
 @param result 计算结果
 @return 计算是否出错
 */
Status CalculatorWithExpression(const char *expression, double *result);

#endif /* Calculator_h */
