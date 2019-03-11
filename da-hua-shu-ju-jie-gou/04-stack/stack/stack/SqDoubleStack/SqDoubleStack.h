//
//  SqDoubleStack.h
//  stack
//
//  Created by 王俊 on 2019/3/11.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef SqDoubleStack_h
#define SqDoubleStack_h

#include <stdio.h>
#include "../Stack.h"

typedef struct {
    SElemType data[MAXSIZE];
    int top1;    // 栈1的栈顶指针
    int top2;    // 栈2的栈顶指针
} SqDoubleStack;

#pragma mark - functions

Status InitSqDoubleStack(SqDoubleStack *S);
Status DestorySqDoubleStack(SqDoubleStack *S);
Status ClearSqDoubleStack(SqDoubleStack *S);
Status SqDoubleStackEmpty(SqDoubleStack S, int stackNumber);
Status SqDoubleStackGetTop(SqDoubleStack *S, SElemType *e, int stackNumber);
Status SqDoubleStackPush(SqDoubleStack *S, SElemType e, int stackNumber);
Status SqDoubleStackPop(SqDoubleStack *S, SElemType *e, int stackNumber);
int SqDoubleStackLength(SqDoubleStack S, int stackNumber);

#pragma mark - test

/**
 栈的顺序存储结构测试
 */
void SqDoubleStackTest(void);

#endif /* SqDoubleStack_h */
