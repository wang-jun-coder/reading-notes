//
//  LinkList.c
//  list
//
//  Created by 王俊 on 2019/1/16.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>
#include <time.h>


#pragma mark - test

void linkListTest(void) {
    
    printf("======================================\n");
    printf("============ linkListTest ============\n");
    
    LinkList L = NULL;
    InitLinkList(&L);
    
    printf("LinkListIsEmpty: %d\n", LinkListIsEmpty(L));
    for (int i=0; i<5; i++) {
        ElemType e = rand();
        printf("LinkListInsert: i:%d e: %d result: %d\n", i, e, LinkListInsert(&L, i, e));
    }
    printf("LinkListIsEmpty: %d\n", LinkListIsEmpty(L));
    
    int len = LinkListLength(L);
    printf("LinkListLength: %d\n", len);
    
    int index = rand()%len + 1;
    ElemType e = -1;
    printf("LinkListDelete: result: %d index: %d e: %d\n", LinkListDelete(&L, index, &e), index, e);
    
    len = LinkListLength(L);
    printf("LinkListLength: %d\n", len);
    
    printf("LinkListIsEmpty: %d\n", LinkListIsEmpty(L));
    
    printf("ClearLinkList: %d\n", ClearLinkList(&L));
    printf("LinkListIsEmpty: %d\n", LinkListIsEmpty(L));
    
    free(L);
    
    int n = 10;
    printf("CreateLinkListHead: %d n: %d\n", CreateLinkListHead(&L, n), n);
    len = LinkListLength(L);
    printf("LinkListLength: %d\n", len);
    
    printf("ClearLinkList: %d\n", ClearLinkList(&L));
    
    free(L);
    
    printf("CreateLinkListTail: %d n: %d\n", CreateLinkListTail(&L, n), n);
    len = LinkListLength(L);
    printf("LinkListLength: %d\n", len);
    

    
    printf("======================================\n");
    
}


#pragma mark - LinkList functions
/**
 获取单链表第i 个位置的元素
 
 @param L 单链表, 必须存在
 @param i 要获取元素的位置标号 1 ≤ i ≤ ListLength(L)
 @param e 返回元素
 @return 操作是结果 OK/ERROR
 */
Status GetLinkListElem(LinkList L, int i, ElemType *e) {
    
    LinkList p = L->next;
    int j = 1;
    
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

/**
 向单链表第 i 个位置插入元素
 
 @param L 单链表, 必须存在
 @param i 要插入的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status LinkListInsert(LinkList *L, int i, ElemType e) {
    
    LinkList p = *L;
    int j = 1;
    
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    // 第 i 个元素不存在
    if (!p || j >i) return ERROR;
    
    // 生成一个新节点
    LinkList s = (LinkList)malloc(sizeof(Node));
    
    
    // 插入元素
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 移除单链表的第 i 个位置的元素
 
 @param L 单链表,必须存在
 @param i 要移除元素的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status LinkListDelete(LinkList *L, int i, ElemType *e) {
    
    LinkList p = *L;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    // 第 i 个节点不存在
    if (!p->next || j > i) return ERROR;
    
    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    
    return OK;
}

/**
 初始化一个单链表
 
 @param L 初始化的链表返回
 @return 操作结果 OK/ERROR
 */
Status InitLinkList(LinkList *L) {
    
    LinkList link = (LinkList)malloc(sizeof(Node));
    link->next = NULL;
    link->data = 0;
    *L = link;
    
    return OK;
}

/**
 判断一个单链表是否为空
 
 @param L 单链表, 必须存在
 @return 链表是否为空 TRUE/FALSE
 */
Status LinkListIsEmpty(LinkList L) {
    // 若链表没有元素, 则为空表
    return L->next ? FALSE : TRUE;
}

/**
 获取一个单链表的长度
 
 @param L 单链表, 必须存在
 @return 单链表长度
 */
int LinkListLength(LinkList L) {
    LinkList p = L->next;
    int len = 0;
    
    while (p) {
        p = p->next;
        len++;
    }
    
    return len;
}

/**
 清空单链表
 
 @param L 单链表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearLinkList(LinkList *L) {
    
    LinkList p = (*L)->next;
    while (p) {
        LinkList q = p->next;
        
        free(p);
        p=q;
    }
    (*L)->next = NULL;
    return OK;
}


/**
 随机产生 n 个元素的值, 建立带表头节点的单链线性表 L(头插法)
 
 @param L 创建的线性表 L 返回
 @param n 表元素个数
 @return 操作结果 OK/ERROR
 */
Status CreateLinkListHead(LinkList *L, int n) {
    
    srand((unsigned int)time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L) -> next = NULL;
    for (int i=0; i<n; i++) {
        LinkList p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return OK;
}

/**
 随机产生 n 个元素的值, 建立带表头节点的单链线性表 L(尾插法)
 
 @param L 创建的线性表 L 返回
 @param n 表元素个数
 @return 操作结果 OK/ERROR
 */
Status CreateLinkListTail(LinkList *L, int n) {
    
    srand((unsigned int)time(0));
    (*L) = (LinkList)malloc(sizeof(Node));
    LinkList r = *L;
    
    for (int i=0; i<n; i++) {
        LinkList p = (Node *)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return OK;
}
