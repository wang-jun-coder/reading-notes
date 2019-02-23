//
//  CircularList.h
//  list
//
//  Created by 王俊 on 2019/2/23.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include <stdio.h>
#include "../List.h"

// 将单链表中的终端节点的指针端由空指针改为指向头结点, 就使整个单链表形成一个环, 这种头尾相接的单链表称为单循环链表

// 定义 CircularLinkList
typedef struct Node *CircularLinkList;


#pragma mark - functions

/**
 初始化一个单循环链表
 
 @param L 初始化的链表返回
 @return 操作结果 OK/ERROR
 */
Status InitCircularLinkList(CircularLinkList *L);


/**
 向单循环链表第 i 个位置插入元素
 
 @param L 单循环链表, 必须存在
 @param i 要插入的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status CircularLinkListInsert(CircularLinkList *L, int i, ElemType e);


/**
 移除单循环链表的第 i 个位置的元素
 
 @param L 单循环链表,必须存在
 @param i 要移除元素的位置标号, 1 ≤ i ≤ ListLength(L)
 @param e 要删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status CircularLinkListDelete(CircularLinkList *L, int i, ElemType *e);


/**
 获取单循环链表第i 个位置的元素
 
 @param L 单循环链表, 必须存在
 @param i 要获取元素的位置标号 1 ≤ i ≤ ListLength(L)
 @param e 返回元素
 @return 操作是结果 OK/ERROR
 */
Status GetCircularLinkListElem(CircularLinkList L, int i, ElemType *e);


/**
 获取一个单循环链表的长度
 
 @param L 单循环链表, 必须存在
 @return 单循环链表长度
 */
int CircularLinkListLength(CircularLinkList L);


/**
 判断一个单循环链表是否为空
 
 @param L 单循环链表, 必须存在
 @return 链表是否为空 TRUE/FALSE
 */
Status CircularLinkListIsEmpty(CircularLinkList L);

/**
 查找元素在单循环链表中的编号
 
 @param L 单循环链表, 必须存在
 @param e 要查找的元素
 @return 查找结果, 该元素在单循环链表中的位置编号, 0 表示不存在
 */
int LocateCircularLinkListElem(CircularLinkList L, ElemType e);


/**
 清空单循环链表
 
 @param L 单循环链表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearCircularLinkList(CircularLinkList *L);


/**
 合并两个单循环链表

 @param list 主单循环链表
 @param anotherList 从单循环链表
 @return 操作是否成功
 */
Status UnionCircularLinkList(CircularLinkList *list, CircularLinkList *anotherList);


/**
 随机产生 n 个元素的值, 建立带表头节点的单链线性表 L(头插法)
 
 @param L 创建的线性表 L 返回
 @param n 表元素个数
 @return 操作结果 OK/ERROR
 */
Status CreateCircularLinkListHead(CircularLinkList *L, int n);


/**
 随机产生 n 个元素的值, 建立带表头节点的单链线性表 L(尾插法)
 
 @param L 创建的线性表 L 返回
 @param n 表元素个数
 @return 操作结果 OK/ERROR
 */
Status CreateCircularLinkListTail(CircularLinkList *L, int n);





#pragma mark - test

/**
 单循环链表测试
 */
void circularLinkListTest(void);


#endif /* CircularList_h */
