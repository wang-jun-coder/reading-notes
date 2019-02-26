//
//  DuList.h
//  list
//
//  Created by 王俊 on 2019/2/26.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef DuList_h
#define DuList_h

#include <stdio.h>
#include "../List.h"

typedef struct DulNode {
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
    
} DulNode, *DuLinkList;

#pragma mark - test

void DuLinkListTest(void);


#pragma mark - functions

/**
 初始化一个双向链表
 
 @param L 初始化的链表返回
 @return 操作结果 OK/ERROR
 */
Status InitDulLinkList(DuLinkList *L);


/**
 向双向链表第 i 个位置插入元素
 
 @param L 双向链表, 必须存在
 @param i 要插入的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status DuLinkListInsert(DuLinkList *L, int i, ElemType e);


/**
 移除双向链表的第 i 个位置的元素
 
 @param L 双向链表,必须存在
 @param i 要移除元素的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status DuLinkListDelete(DuLinkList *L, int i, ElemType *e);


/**
 获取双向链表第i 个位置的元素
 
 @param L 双向链表, 必须存在
 @param i 要获取元素的位置标号 1 ≤ i ≤ ListLength(L)
 @param e 返回元素
 @return 操作是结果 OK/ERROR
 */
Status GetDuLinkListElem(DuLinkList L, int i, ElemType *e);


/**
 获取一个双向链表的长度
 
 @param L 双向链表, 必须存在
 @return 双向链表长度
 */
int DuLinkListLength(DuLinkList L);


/**
 判断一个双向链表是否为空
 
 @param L 双向链表, 必须存在
 @return 链表是否为空 TRUE/FALSE
 */
Status DuLinkListIsEmpty(DuLinkList L);

/**
 查找元素在双向链表中的编号
 
 @param L 双向链表, 必须存在
 @param e 要查找的元素
 @return 查找结果, 该元素在双向链表中的位置编号, 0 表示不存在
 */
int LocateDuLinkListElem(DuLinkList L, ElemType e);


/**
 清空双向链表
 
 @param L 双向链表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearDuLinkList(DuLinkList *L);


#endif /* DuList_h */
