//
//  Calculator.c
//  calculator
//
//  Created by 王俊 on 2019/3/12.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "Calculator.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../stack/LinkStack.h"

Status transferExpressionToRPN(const char *expression, char *rpn);
Status calculatorWithRPN(char *rpn, double *result);
int getPriorityOfOperation(char op);
Status convertExpression(char *expression, char *realExp);
/**
 计算四则运算表达式的值
 
 @param expression 四则运算表达式
 @return 计算结果
 */
Status CalculatorWithExpression(const char *expression, double *result) {
    
    char rpn[MAXSIZE];
    if (transferExpressionToRPN(expression, rpn)) {
        return calculatorWithRPN(rpn, result);
    }
    return ERROR;
}


/**
 转换中缀表达式为后缀表达式

 @param expression 中缀表达式
 @param rpn 得到的后缀表达式
 @return 转换状态, 是否成功
 */
Status transferExpressionToRPN(const char *expression, char *rpn) {
    
    LinkStack stack;
    InitLinkStack(&stack);
    
//    char realExp[MAXSIZE];
//    convertExpression(expression, realExp);
    
    char result[MAXSIZE];
    int cur = 0;
    
    for (int i=0; i<MAXSIZE; i++) {
        char one = expression[i];
        if('\0' == one) break;
        printf("%c\n", one);
        // 如果是数字, 直接输出
        if (isdigit(one)) {
            if (cur != 0) {
                result[cur++] = ' ';
            }
            result[cur++] = one;
            continue;
        }
        
        // 如果是符号
        // 遇到右括号出栈匹配左括号
        if (')' == one) {
            char e;
            Status s = LinkStackGetTop(&stack, &e);
            if (!s) return s;
            
            while ('(' != e && !LinkStackEmpty(stack)) {
                s = LinkStackPop(&stack, &e);
                if ('(' != e) {
                    result[cur++] = ' ';
                    result[cur++] = e;
                }
            }
            continue;
        }
        // 如果是空栈或者 ( 直接入栈
        if (LinkStackEmpty(stack) || '(' == one) {
            LinkStackPush(&stack, one);
            continue;
        }
        
        // 当前符号优先级比栈顶符号优先级高,则入栈, 否则出栈
        int pOne = getPriorityOfOperation(one);
        char e;
        LinkStackGetTop(&stack, &e);
        int pTop = getPriorityOfOperation(e);
        
        // 符号优先级比栈顶符号高,则入栈, 否则出栈
        if (pOne > pTop || '(' == e) {
            LinkStackPush(&stack, one);
            continue;
        }
        
        // 直到栈顶优先级比当前优先级高,或者栈空, 才停止出栈, 然后将当前符号入栈
        while (pTop > pOne || !LinkStackEmpty(stack)) {
            LinkStackPop(&stack, &e);
            pTop = getPriorityOfOperation(e);
            result[cur++] = ' ';
            result[cur++] = e;
        }
        LinkStackPush(&stack, one);
    }
    
    // 循环结束, 将栈中剩余符号取出并输出
    while (!LinkStackEmpty(stack)) {
        char e;
        Status s = LinkStackPop(&stack, &e);
        if (!s) return s;
        result[cur++] = ' ';
        result[cur++] = e;
    }
    result[cur] = '\0';
//    rpn = result;
    strcpy(rpn, result);
    printf("RPN: %s\n", rpn);
    return OK;
}


/**
 计算后缀表达式的值

 @param rpn 后缀表达式
 @param result 计算结果
 @return 计算状态, 是否成功
 */
Status calculatorWithRPN(char *rpn, double *result) {
    *result = 0;
    
    LinkStack stack;
    InitLinkStack(&stack);
    
    unsigned long len = strlen(rpn);
    
    for (int i=0; i<len; i++) {
        char one = rpn[i];
        if ('\0' == one) break;
        if (' ' == one) continue;
        
        // 数字进栈
        if (isdigit(one)) {
            LinkStackPush(&stack, one);
            continue;
        }
        // 运算符处理
        if ('-' == one) {
            // 减数
            char subtractor;
            LinkStackPop(&stack, &subtractor);
            // 被减数
            char minuend;
            LinkStackPop(&stack, &minuend);
            // 结果入栈
            int res = (minuend - '0') - (subtractor - '0');
            LinkStackPush(&stack, res+'0');
            continue;
        }
        
        if ('+' == one) {
            // 加数
            char addend;
            LinkStackPop(&stack, &addend);
            // 被加数
            char augend;
            LinkStackPop(&stack, &augend);
            // 结果入栈
            int res = (augend - '0') + (addend - '0');
            LinkStackPush(&stack, res+'0');
            continue;
        }
        
        if ('*' == one) {
            // 乘数
            char multiplier;
            LinkStackPop(&stack, &multiplier);
            // 被乘数
            char multiplicand;
            LinkStackPop(&stack, &multiplicand);
            // 结果入栈
            int res = (multiplicand - '0') * (multiplier - '0');
            LinkStackPush(&stack, res+'0');
            continue;
        }
        
        if ('/' == one) {
            // 除数
            char divisor;
            LinkStackPop(&stack, &divisor);
            // 被除数
            char dividend;
            LinkStackPop(&stack, &dividend);
            // 结果入栈
            int res = (dividend-'0') / (divisor-'0');
            LinkStackPush(&stack, res+'0');
            continue;
        }
    }
    char res;
    LinkStackPop(&stack, &res);
    *result = res - '0';
    return OK;
}



/**
 获取运算符的优先级

 @param op 运算符, 仅支持 + - * / ( )
 @return 优先级, 不支持的参数返回 - 1
 */
int getPriorityOfOperation(char op) {
    
    if ('+' == op || '-' == op) {
        return 0; // 最低优先级
    }
    if('*' == op || '/' == op) {
        return 1; // 优先级比+- 高
    }
    if ('(' == op || ')' == op) {
        return 2; // 优先级比 */高
    }
    return -1;
}

/**
 转换中缀表达式

 @param expression
 中缀表达式, 形如 9 + ( 3 - 1 ) * 3 + 4 / 2
 @param realExp 转换后的 char 数组 ['9', '+', '(', '3', '-', '1', ')', '*', '3', '+', '4', '/', '2', '\0']
 @return 转换是否成功
 */
Status convertExpression(char *expression, char *realExp) {
    char res[MAXSIZE];
    int cur = 0;

    char delims[] = " ";
    char *result = NULL;
    result = strtok(expression, delims);
//    while( result != NULL ) {
//        printf( "result is \"%s\"\n", result );
//        res[cur++] = result;
//        result = strtok( NULL, delims );
//    }
    *realExp = res;
    return OK;
}
