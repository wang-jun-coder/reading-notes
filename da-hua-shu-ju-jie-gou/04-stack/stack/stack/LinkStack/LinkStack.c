//
//  LinkStack.c
//  stack
//
//  Created by 王俊 on 2019/3/11.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "LinkStack.h"
#include <stdlib.h>

#pragma mark - test

/**
 栈的链式存储结构测试
 */
void LinkStackTest(void) {
    printf("========== SqStackTest ==========\n");
    printf("=================================\n");
    
    LinkStack stack;
    Status s;
    int len;
    SElemType e;
    
    s = InitLinkStack(&stack);
    printf("InitLinkStack: %d\n", s);
    
    s = LinkStackPush(&stack, 16);
    printf("LinkStackPush: %d\n", s);
    
    len = LinkStackLength(stack);
    printf("LinkStackLength: %d\n", len);
    
    s = LinkStackGetTop(&stack, &e);
    printf("LinkStackGetTo => status: %d e: %d\n", s, e);
    
    s = LinkStackPush(&stack, 88);
    printf("LinkStackPush: %d\n", s);
    
    len = LinkStackLength(stack);
    printf("LinkStackLength: %d\n", len);
    
    s = LinkStackGetTop(&stack, &e);
    printf("LinkStackGetTo => status: %d e: %d\n", s, e);
    
    s = LinkStackPop(&stack, &e);
    printf("LinkStackPop => status: %d e: %d\n", s, e);
    
    len = LinkStackLength(stack);
    printf("LinkStackLength: %d\n", len);
    
    s = ClearLinkStack(&stack);
    printf("ClearLinkStack: %d\n", s);
    
    len = LinkStackLength(stack);
    printf("LinkStackLength: %d\n", len);
    
}
#pragma mark - functions

Status InitLinkStack(LinkStack *S) {
    S->top = NULL;
    S->count = 0;

    return OK;
}
Status DestoryLinkStack(LinkStack *S) {
    ClearLinkStack(S);
    S = NULL;
    return OK;
}
Status ClearLinkStack(LinkStack *S) {
    LinkStackPtr p;
    while (S->top) {
        p = S->top;
        S->top = (StackNode*)S->top->next;
        free(p);
        S->count--;
    }
    return OK;
}
Status LinkStackEmpty(LinkStack S) {
    return LinkStackLength(S) == 0 ? TRUE : FALSE;
}
Status LinkStackGetTop(LinkStack *S, SElemType *e) {
    if (!S->top) {
        return ERROR;
    }
    *e = S->top->data;
    return OK;
}
Status LinkStackPush(LinkStack *S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count ++;
    return OK;
}
Status LinkStackPop(LinkStack *S, SElemType *e) {
    LinkStackPtr p;
    if (LinkStackEmpty(*S)) {
        return ERROR;
    }
    *e = S->top->data;
    p = S->top;
    S->top = (StackNode *)S->top->next;
    free(p);
    S->count--;
    
    return OK;
}
int LinkStackLength(LinkStack S) {
    return S.count;
}


