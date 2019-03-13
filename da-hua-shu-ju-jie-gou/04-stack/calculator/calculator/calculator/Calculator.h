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

 注意: 我对 C 语言不熟悉, 此方法只能支持 个位数的四则运算, 如: 9+(3-1)*3+4/2, 一旦出现两位数的运算符,将产生不可预知的后果
 
 @param expression 表达式
 @param result 计算结果
 @return 计算是否出错
 */
Status CalculatorWithExpression(const char *expression, double *result);

#endif /* Calculator_h */
