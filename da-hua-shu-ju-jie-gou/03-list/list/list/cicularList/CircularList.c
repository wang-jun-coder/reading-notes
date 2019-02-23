//
//  CircularList.c
//  list
//
//  Created by 王俊 on 2019/2/23.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "CircularList.h"
#include <stdlib.h>
#include <time.h>

#pragma mark - test

/**
 单循环链表测试
 */
void circularLinkListTest(void) {
    printf("==============================================\n");
    printf("============ circularLinkListTest ============\n");
    
    CircularLinkList list = NULL, headList = NULL, tailList = NULL;;
    
    Status s = InitCircularLinkList(&list);
    printf("InitCircularLinkList: %d\n", s);
    printf("CircularLinkListIsEmpty: %d\n", CircularLinkListIsEmpty(list));
    
    s = CreateCircularLinkListHead(&headList, 10);
    printf("CreateCircularLinkListHead: %d\n", s);
    s = CreateCircularLinkListTail(&tailList, 10);
    printf("CreateCircularLinkListTail: %d\n", s);
    
    int len = CircularLinkListLength(headList);
    printf("CircularLinkListLength: %d\n", len);
    
    ElemType e = 0;
    s = GetCircularLinkListElem(headList, 5, &e);
    printf("GetCircularLinkListElem: %d elem: %d\n", s, e);
    
    int index = LocateCircularLinkListElem(headList, e);
    printf("LocateCircularLinkListElem: %d index: %d\n", e, index);
    
    s = CircularLinkListDelete(&headList, 5, &e);
    printf("CircularLinkListDelete: %d elem: %d\n", s, e);
    
    s = CircularLinkListInsert(&headList, 5, e);
    printf("CircularLinkListInsert: %d elem: %d\n", s, e);
    
    s = GetCircularLinkListElem(headList, 5, &e);
    printf("GetCircularLinkListElem: %d elem: %d\n", s, e);
    
    s = ClearCircularLinkList(&headList);
    printf("ClearCircularLinkList: %d\n", s);
    
    len = CircularLinkListLength(headList);
    printf("CircularLinkListLength: %d\n", len);
    
    len = CircularLinkListLength(tailList);
    printf("CircularLinkListLength: %d\n", len);
    
    s = UnionCircularLinkList(&headList, &tailList);
    printf("UnionCircularLinkList: %d\n", s);
    
    len = CircularLinkListLength(headList);
    printf("CircularLinkListLength: %d\n", len);
}

#pragma mark - functions


/**
 初始化一个单循环链表
 
 @param L 初始化的链表返回
 @return 操作结果 OK/ERROR
 */
Status InitCircularLinkList(CircularLinkList *L) {
    
    CircularLinkList link = (CircularLinkList)malloc(sizeof(Node));
    link->next = link;
    link->data = 0;
    *L = link;
    
    return OK;
}


/**
 向单循环链表第 i 个位置插入元素
 
 @param L 单循环链表, 必须存在
 @param i 要插入的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status CircularLinkListInsert(CircularLinkList *L, int i, ElemType e) {
    
    CircularLinkList p = *L;
    int j = 1;
    while (p->next != *L && j<i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) return ERROR;
    
    CircularLinkList s = (CircularLinkList)malloc(sizeof(Node));
    s->next = p->next;
    s->data = e;
    p->next = s;
    
    return OK;
}


/**
 移除单循环链表的第 i 个位置的元素
 
 @param L 单循环链表,必须存在
 @param i 要移除元素的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status CircularLinkListDelete(CircularLinkList *L, int i, ElemType *e) {
    
    CircularLinkList p = *L;
    int j =1;
    
    while (p->next != *L && j <i) {
        p = p->next;
        j++;
    }
    if (p->next == *L || j >i) return ERROR;
    
    CircularLinkList del = p->next;
    p->next = del->next;
    *e = del->data;
    free(del);
    
    return OK;
}


/**
 获取单循环链表第i 个位置的元素
 
 @param L 单循环链表, 必须存在
 @param i 要获取元素的位置标号 1 ≤ i ≤ ListLength(L)
 @param e 返回元素
 @return 操作是结果 OK/ERROR
 */
Status GetCircularLinkListElem(CircularLinkList L, int i, ElemType *e) {
    
    CircularLinkList p = L->next;
    int j=1;
    
    while (p != L && j <i) {
        p = p->next;
        j++;
    }
    if (p==L || j>i) return ERROR;
    
    *e = p->data;

    return OK;
}


/**
 获取一个单循环链表的长度
 
 @param L 单循环链表, 必须存在
 @return 单循环链表长度
 */
int CircularLinkListLength(CircularLinkList L) {
    CircularLinkList p = L->next;
    int len=0;
    while (p!=L) {
        p = p->next;
        len++;
    }
    return len;
}


/**
 判断一个单循环链表是否为空
 
 @param L 单循环链表, 必须存在
 @return 链表是否为空 TRUE/FALSE
 */
Status CircularLinkListIsEmpty(CircularLinkList L) {
    return CircularLinkListLength(L) == 0 ? TRUE : FALSE;
}


/**
 清空单循环链表
 
 @param L 单循环链表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearCircularLinkList(CircularLinkList *L) {
    CircularLinkList p = *L;
    
    while (p->next != *L) {
        CircularLinkList next = p->next;
        free(p);
        p=next;
    }
    
    (*L)->next = (*L);
    
    return OK;
}

/**
 合并两个单循环链表
 
 @param list 主单循环链表
 @param anotherList 从单循环链表
 @return 操作是否成功
 */
Status UnionCircularLinkList(CircularLinkList *list, CircularLinkList *anotherList) {
    
    CircularLinkList rearA = (*list);
    CircularLinkList rearB = (*anotherList);
    
    while (rearA->next != *list) {
        rearA = rearA->next;
    }
    while (rearB->next != *anotherList) {
        rearB = rearB->next;
    }
    
    rearA->next = (*anotherList)->next;
    rearB->next = (*list);

    free((*anotherList));
    *anotherList = NULL;

    return OK;
}

/**
 查找元素在单循环链表中的编号
 
 @param L 单循环链表, 必须存在
 @param e 要查找的元素
 @return 查找结果, 该元素在单循环链表中的位置编号, 0 表示不存在
 */
int LocateCircularLinkListElem(CircularLinkList L, ElemType e) {
    int index = 0;
    CircularLinkList p = L->next;
    
    while (p != L) {
        index ++;
        if (p->data == e) {
            break;
        }
        p = p->next;
    }
    
    return index;
}

/**
 随机产生 n 个元素的值, 建立带表头节点的单链线性表 L(头插法)
 
 @param L 创建的线性表 L 返回
 @param n 表元素个数
 @return 操作结果 OK/ERROR
 */
Status CreateCircularLinkListHead(CircularLinkList *L, int n) {
    
    srand((unsigned int)time(0));
    (*L) = (CircularLinkList)malloc(sizeof(Node));
    (*L)->next = (*L);
    for (int i=0; i<n; i++) {
        CircularLinkList p = (CircularLinkList)malloc(sizeof(Node));
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
Status CreateCircularLinkListTail(CircularLinkList *L, int n) {
    srand((unsigned int)time(0));
    (*L) = (CircularLinkList)malloc(sizeof(Node));
    (*L)->next = (*L);
    CircularLinkList last = *L;
    for (int i=0; i<n; i++) {
        CircularLinkList p = (CircularLinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = last->next;
        last->next = p;
        last = p;
    }
    return OK;
}

