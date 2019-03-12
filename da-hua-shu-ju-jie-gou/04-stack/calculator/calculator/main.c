//
//  main.c
//  calculator
//
//  Created by 王俊 on 2019/3/12.
//  Copyright © 2019 王俊. All rights reserved.
//

#include <stdio.h>
#include "./calculator/Calculator.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    
    printf("请输入四则运算表达式, 如: 9+(3-1)*3+4/2, 回车键确认\n");
    char input[MAXSIZE];
    scanf("%s", input);
    
    double res = 0;
    if (CalculatorWithExpression(input, &res)) {
        printf("计算结果: %s = %f\n", input, res);
    } else {
        printf("您的表达式有误: %s\n", input);
    }
    return 0;
}
