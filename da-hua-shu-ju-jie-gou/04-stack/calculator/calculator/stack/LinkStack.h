//
//  LinkStack.h
//  stack
//
//  Created by 王俊 on 2019/3/11.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>
#include "Stack.h"

typedef struct {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;

#pragma mark - functions

Status InitLinkStack(LinkStack *S);
Status DestoryLinkStack(LinkStack *S);
Status ClearLinkStack(LinkStack *S);
Status LinkStackEmpty(LinkStack S);
Status LinkStackGetTop(LinkStack *S, SElemType *e);
Status LinkStackPush(LinkStack *S, SElemType e);
Status LinkStackPop(LinkStack *S, SElemType *e);
int LinkStackLength(LinkStack S);

#pragma mark - test

/**
 栈的链式存储结构测试
 */
void LinkStackTest(void);


#endif /* LinkStack_h */
