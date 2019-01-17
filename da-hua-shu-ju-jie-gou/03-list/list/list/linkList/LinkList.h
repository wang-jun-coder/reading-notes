//
//  LinkList.h
//  list
//
//  Created by 王俊 on 2019/1/16.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include "../List.h"

#pragma mark - defines

/**
 线性表的单链表的存储结构
 
 结点由存放数据元素的数据域和存放后继结点地址的指针域组成
 */
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

// 定义 LinkList
typedef struct Node *LinkList;


#pragma mark - LinkList functions


/**
 获取单链表第i 个位置的元素

 @param L 单链表, 必须存在
 @param i 要获取元素的位置标号 1 ≤ i ≤ ListLength(L)
 @param e 返回元素
 @return 操作是结果 OK/ERROR
 */
Status GetLinkListElem(LinkList L, int i, ElemType *e);


/**
 向单链表第 i 个位置插入元素

 @param L 单链表, 必须存在
 @param i 要插入的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status LinkListInsert(LinkList *L, int i, ElemType e);


/**
 移除单链表的第 i 个位置的元素

 @param L 单链表,必须存在
 @param i 要移除元素的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status LinkListDelete(LinkList *L, int i, ElemType *e);


/**
 初始化一个单链表

 @param L 初始化的链表返回
 @return 操作结果 OK/ERROR
 */
Status InitLinkList(LinkList *L);



/**
 判断一个单链表是否为空

 @param L 单链表, 必须存在
 @return 链表是否为空 TRUE/FALSE
 */
Status LinkListIsEmpty(LinkList L);



/**
 获取一个单链表的长度

 @param L 单链表, 必须存在
 @return 单链表长度
 */
int LinkListLength(LinkList L);


/**
 清空单链表

 @param L 单链表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearLinkList(LinkList *L);


/**
 随机产生 n 个元素的值, 建立带表头节点的单链线性表 L(头插法)

 @param L 创建的线性表 L 返回
 @param n 表元素个数
 @return 操作结果 OK/ERROR
 */
Status CreateLinkListHead(LinkList *L, int n);


/**
 随机产生 n 个元素的值, 建立带表头节点的单链线性表 L(尾插法)

 @param L 创建的线性表 L 返回
 @param n 表元素个数
 @return 操作结果 OK/ERROR
 */
Status CreateLinkListTail(LinkList *L, int n);


#pragma mark - test

void linkListTest(void);

#endif /* LinkList_h */
