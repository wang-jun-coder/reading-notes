//
//  SqDoubleStack.c
//  stack
//
//  Created by 王俊 on 2019/3/11.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "SqDoubleStack.h"
#include <string.h>
#include <stdlib.h>
/**
 栈的顺序存储结构测试
 */
void SqDoubleStackTest(void) {
    printf("========== SqDoubleStackTest ==========\n");
    printf("=======================================\n");
    
    SqDoubleStack stack;
    Status s;
    SElemType e;
    int len;
    
    s = InitSqDoubleStack(&stack);
    printf("InitSqDoubleStack: %d\n", s);
    
    s = SqDoubleStackEmpty(stack, 1);
    printf("SqDoubleStackEmpty 1: %d\n", s);
    s = SqDoubleStackEmpty(stack, 2);
    printf("SqDoubleStackEmpty 2: %d\n", s);
    
    
    s = SqDoubleStackPush(&stack, 9, 1);
    printf("SqDoubleStackPush 1: %d\n", s);
    s = SqDoubleStackPush(&stack, 17, 1);
    printf("SqDoubleStackPush 1: %d\n", s);
    len = SqDoubleStackLength(stack, 1);
    printf("SqDoubleStackLength 1: %d\n", len);
    s = SqDoubleStackGetTop(&stack, &e, 1);
    printf("SqDoubleStackGetTop 1 => status: %d elem: %d\n", s, e);
    
    
    s = SqDoubleStackPush(&stack, 33, 2);
    printf("SqDoubleStackPush 2: %d\n", s);
    s = SqDoubleStackPush(&stack, 98, 2);
    printf("SqDoubleStackPush 2: %d\n", s);
    len = SqDoubleStackLength(stack, 2);
    printf("SqDoubleStackLength 2: %d\n", len);
    s = SqDoubleStackGetTop(&stack, &e, 2);
    printf("SqDoubleStackGetTop 2 => status: %d elem: %d\n", s, e);
    
    s = SqDoubleStackPop(&stack, &e, 1);
    printf("SqDoubleStackPop 1 => status: %d e: %d\n", s, e);
    len = SqDoubleStackLength(stack, 1);
    printf("SqDoubleStackLength 1: %d\n", len);
    s = SqDoubleStackGetTop(&stack, &e, 1);
    printf("SqDoubleStackGetTop 1 => status: %d elem: %d\n", s, e);
    
    
    s = SqDoubleStackPop(&stack, &e, 2);
    printf("SqDoubleStackPop 2 => status: %d e: %d\n", s, e);
    s = SqDoubleStackGetTop(&stack, &e, 2);
    printf("SqDoubleStackGetTop 2 => status: %d elem: %d\n", s, e);
    s = SqDoubleStackPop(&stack, &e, 2);
    printf("SqDoubleStackPop 2 => status: %d e: %d\n", s, e);
    len = SqDoubleStackLength(stack, 2);
    printf("SqDoubleStackLength 2: %d\n", len);
    s = SqDoubleStackEmpty(stack, 2);
    printf("SqDoubleStackEmpty 2: %d\n", s);
    
    s = ClearSqDoubleStack(&stack);
    printf("ClearSqDoubleStack: %d\n", s);
    
}
#pragma mark - functions

Status InitSqDoubleStack(SqDoubleStack *S) {
    SqDoubleStack s;
    memset(s.data, 0, MAXSIZE*sizeof(SElemType));
    s.top1 = 0;
    s.top2 = MAXSIZE-s.top1;
    *S = s;
    return OK;
    return OK;
}
Status DestorySqDoubleStack(SqDoubleStack *S) {
    S=NULL;
    return OK;
}
Status ClearSqDoubleStack(SqDoubleStack *S) {
    memset(S->data, 0, MAXSIZE*sizeof(SElemType));
    S->top1 = 0;
    S->top2 = MAXSIZE-S->top1;
    return OK;
}
Status SqDoubleStackEmpty(SqDoubleStack S, int stackNumber) {
    if (stackNumber != 1 && stackNumber != 2) return ERROR;
    return SqDoubleStackLength(S, stackNumber) == 0 ? TRUE : FALSE;
}
Status SqDoubleStackGetTop(SqDoubleStack *S, SElemType *e, int stackNumber) {
    if (stackNumber != 1 && stackNumber != 2) return ERROR;
    if (stackNumber==1) {
        *e = S->data[S->top1];
    }
    if (stackNumber==2) {
        *e = S->data[S->top2];
    }
    return OK;
}
Status SqDoubleStackPush(SqDoubleStack *S, SElemType e, int stackNumber) {
    // 栈满
    if (S->top1+1==S->top2) {
        return ERROR;
    }
    if(stackNumber==1){
        S->data[++S->top1] = e;
    }
    if (stackNumber==2) {
        S->data[--S->top2] = e;
    }
    return OK;
}
Status SqDoubleStackPop(SqDoubleStack *S, SElemType *e, int stackNumber) {
    if(stackNumber==1) {
        if (S->top1 <= -1) {
            return ERROR;
        }
        *e = S->data[S->top1--];
    }
    if (stackNumber==2) {
        if (S->top2 >= MAXSIZE) {
            return ERROR;
        }
        *e = S->data[S->top2++];
    }
    return OK;
}
int SqDoubleStackLength(SqDoubleStack S, int stackNumber) {
    if (stackNumber==1) {
        return S.top1;
    }
    if (stackNumber==2) {
        return MAXSIZE-S.top2;
    }
    return ERROR;
}

#pragma mark - test

