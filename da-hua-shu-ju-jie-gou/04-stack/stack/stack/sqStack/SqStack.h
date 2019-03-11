//
//  SqStack.h
//  stack
//
//  Created by 王俊 on 2019/3/11.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef SqStack_h
#define SqStack_h

#include <stdio.h>
#include "../Stack.h"

typedef struct {
    SElemType data[MAXSIZE];
    int top;    // 用于栈顶指针
} SqStack;

#pragma mark - functions

Status InitSqStack(SqStack *S);
Status DestorySqStack(SqStack *S);
Status ClearSqStack(SqStack *S);
Status SqStackEmpty(SqStack S);
Status SqStackGetTop(SqStack *S, SElemType *e);
Status SqStackPush(SqStack *S, SElemType e);
Status SqStackPop(SqStack *S, SElemType *e);
int SqStackLength(SqStack S);

#pragma mark - test

/**
 栈的顺序存储结构测试
 */
void SqStackTest(void);

#endif /* SqStack_h */
