//
//  SqStack.c
//  stack
//
//  Created by 王俊 on 2019/3/11.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "SqStack.h"
#include <string.h>
#include <stdlib.h>

#pragma mark - test

/**
 栈的顺序存储结构测试
 */
void SqStackTest(void) {
    printf("========== SqStackTest ==========\n");
    printf("=================================\n");
    
    SqStack stack;
    Status s = InitSqStack(&stack);
    printf("InitSqStack: %d\n", s);
    
    int len = SqStackLength(stack);
    printf("SqStackLength: %d\n", len);
    
    s = SqStackEmpty(stack);
    printf("SqStackEmpty: %d\n", s);
    
    s = SqStackPush(&stack, 18);
    printf("SqStackPush: %d\n", s);
    len = SqStackLength(stack);
    printf("SqStackLength: %d\n", len);
    
    s = SqStackPush(&stack, 22);
    printf("SqStackPush: %d\n", s);
    len = SqStackLength(stack);
    printf("SqStackLength: %d\n", len);
    
    SElemType e;
    s = SqStackGetTop(&stack, &e);
    printf("SqStackGetTop => status:%d elem:%d\n", s, e);
    
    s = SqStackPop(&stack, &e);
    printf("SqStackPop => status:%d elem:%d\n", s, e);
    len = SqStackLength(stack);
    printf("SqStackLength: %d\n", len);
    
    s = ClearSqStack(&stack);
    printf("ClearSqStack: %d\n", s);
    len = SqStackLength(stack);
    printf("SqStackLength: %d\n", len);
    
    s = DestorySqStack(&stack);
    printf("ClearSqStack:%d\n", s);
    
}

#pragma mark - functions

Status InitSqStack(SqStack *S) {
    SqStack s;
    memset(s.data, 0, MAXSIZE*sizeof(SElemType));
    s.top = 0;
    *S = s;
    return OK;
}
Status DestorySqStack(SqStack *S) {
    S = NULL;
    return OK;
}
Status ClearSqStack(SqStack *S) {
    memset(S->data, 0, MAXSIZE*sizeof(SElemType));
    S->top = 0;
    return OK;
}
Status SqStackEmpty(SqStack S) {
    return SqStackLength(S) == 0 ? TRUE : FALSE;
}
Status SqStackGetTop(SqStack *S, SElemType *e) {
    if (S->top<=-1 || S->top>=MAXSIZE) {
        return ERROR;
    }
    *e = S->data[S->top];
    return OK;
}
Status SqStackPush(SqStack *S, SElemType e) {
    if (S->top == MAXSIZE-1) {
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}
Status SqStackPop(SqStack *S, SElemType *e) {
    if (S->top <= -1) {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}
int SqStackLength(SqStack S) {
    return S.top;
}

