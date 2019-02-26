//
//  DuList.c
//  list
//
//  Created by 王俊 on 2019/2/26.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "DuList.h"
#include <stdlib.h>
#include <time.h>


#pragma mark - test

void DuLinkListTest(void) {
    printf("======================================\n");
    printf("=========== DuLinkListTest ===========\n");
    
    DuLinkList L = NULL;
    
    InitDulLinkList(&L);
    
    int len = DuLinkListLength(L);
    printf("DuLinkListLength: %i\n", len);
    
    Status s = DuLinkListInsert(&L, 1, 13);
    printf("DuLinkListInsert: %i\n", s);
    
    s = DuLinkListInsert(&L, 2, 15);
    printf("DuLinkListInsert: %i\n", s);
    
    len = DuLinkListLength(L);
    printf("DuLinkListLength: %i\n", len);
    
    ElemType e = 0;
    s = GetDuLinkListElem(L, 2, &e);
    printf("GetDuLinkListElem: status: %i elem: %i\n", s, e);
    
    e=0;
    s = DuLinkListDelete(&L, 1, &e);
    printf("DuLinkListDelete: status: %i elem: %i\n", s, e);
    
    int index = LocateDuLinkListElem(L, 15);
    printf("LocateDuLinkListElem: %i \n", index);
    
    s = DuLinkListIsEmpty(L);
    printf("DuLinkListIsEmpty: %i \n", s);
    
    s = ClearDuLinkList(&L);
    printf("ClearDuLinkList: %i \n", s);
    
    s = DuLinkListIsEmpty(L);
    printf("DuLinkListIsEmpty: %i \n", s);
}


#pragma mark - functions

/**
 初始化一个双向链表
 
 @param L 初始化的链表返回
 @return 操作结果 OK/ERROR
 */
Status InitDulLinkList(DuLinkList *L) {
    DuLinkList link = (DuLinkList)malloc(sizeof(DulNode));
    link->next = NULL;
    link->prior = NULL;
    link->data = 0;
    *L = link;
    
    return OK;
    return OK;
}


/**
 向双向链表第 i 个位置插入元素
 
 @param L 双向链表, 必须存在
 @param i 要插入的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status DuLinkListInsert(DuLinkList *L, int i, ElemType e) {
    DuLinkList p = *L;
    int j = 1;
    
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    // 第 i 个元素不存在
    if (!p || j >i) return ERROR;
    
    // 生成一个新节点
    DuLinkList s = (DuLinkList)malloc(sizeof(DulNode));

    // 插入元素
    s->data = e;
    s->prior = p;
    s->next = p->next;
    if(p->next != NULL) p->next->prior = s;
    p->next = s;
    
    return OK;
}


/**
 移除双向链表的第 i 个位置的元素
 
 @param L 双向链表,必须存在
 @param i 要移除元素的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status DuLinkListDelete(DuLinkList *L, int i, ElemType *e) {
    DuLinkList p = (*L)->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    // 第 i 个节点不存在
    if (!p || j > i) return ERROR;
    
    *e = p->data;
    if(p->prior) p->prior->next = p->next;
    if(p->next) p->next->prior = p->prior;

    free(p);
    
    return OK;
}


/**
 获取双向链表第i 个位置的元素
 
 @param L 双向链表, 必须存在
 @param i 要获取元素的位置标号 1 ≤ i ≤ ListLength(L)
 @param e 返回元素
 @return 操作是结果 OK/ERROR
 */
Status GetDuLinkListElem(DuLinkList L, int i, ElemType *e) {
    DuLinkList p = L->next;
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
 获取一个双向链表的长度
 
 @param L 双向链表, 必须存在
 @return 双向链表长度
 */
int DuLinkListLength(DuLinkList L) {
    DuLinkList p = L->next;
    int len = 0;
    
    while (p) {
        p = p->next;
        len++;
    }
    
    return len;
}


/**
 判断一个双向链表是否为空
 
 @param L 双向链表, 必须存在
 @return 链表是否为空 TRUE/FALSE
 */
Status DuLinkListIsEmpty(DuLinkList L) {
    return DuLinkListLength(L) == 0 ? TRUE : FALSE;
}

/**
 查找元素在双向链表中的编号
 
 @param L 双向链表, 必须存在
 @param e 要查找的元素
 @return 查找结果, 该元素在双向链表中的位置编号, 0 表示不存在
 */
int LocateDuLinkListElem(DuLinkList L, ElemType e) {
    int index = 0;
    DuLinkList p = L->next;
    
    while (p) {
        index ++;
        if (p->data == e) {
            break;
        }
        p = p->next;
    }
    
    return index;
}


/**
 清空双向链表
 
 @param L 双向链表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearDuLinkList(DuLinkList *L) {
    DuLinkList p = (*L)->next;
    while (p) {
        DuLinkList q = p->next;
        free(p);
        p=q;
    }
    (*L)->next = NULL;
    return OK;
}
