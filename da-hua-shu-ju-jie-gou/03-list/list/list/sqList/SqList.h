//
//  SqList.h
//  list
//
//  Created by 王俊 on 2019/1/15.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef SqList_h
#define SqList_h

#include <stdio.h>
#include "../List.h"

#pragma mark - defines

// 线性表的顺序存储结构
#define MAXSIZE 20              // 存储空间初始分配量
typedef struct {
    ElemType data[MAXSIZE];     // 数组存储元素, 最大值为 MAXSIZE
    int length;                 // 线性表当前元素
} SqList;


#pragma mark - SqList functions
/**
 获取线性表中第 i 个元素

 @param L 线性表 L, 必须已存在
 @param i 要获取元素的位置编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 对应元素返回
 @return 操作结果 OK/ERROR
 */
Status GetSqListElem(SqList L, int i, ElemType *e);


/**
 向线性表的第 i 个位置插入元素

 @param L 线性表, 必须存在
 @param i 位置编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status SqListInsert(SqList *L, int i, ElemType e);


/**
 删除线性表第 i 个位置的元素

 @param L 线性表, 必须存在
 @param i 要删除的位置编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 被删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status SqListDelete(SqList *L, int i, ElemType *e);


/**
 初始化一个线性表

 @param L 初始化线性表的返回
 @return 操作结果 OK/ERROR
 */
Status InitSqList(SqList *L);


/**
 判断线性表是否为空

 @param L 要判断的线性表,必须存在
 @return TRUE/FALSE
 */
Status SqListIsEmpty(SqList L);


/**
 查找元素在线性表中的编号

 @param L 线性表, 必须存在
 @param e 要查找的元素
 @return 查找结果, 该元素在线性表中的位置编号, 0 表示不存在
 */
 int LocateSqListElem(SqList L, ElemType e);


/**
 获取线性表的长度

 @param L 线性表, 必须存在
 @return 线性表长度
 */
int SqListLength(SqList L);


/**
 清空线性表

 @param L 要清空的线性表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearSqList(SqList *L);


#pragma mark - test

/**
 SqList 相关的测试函数入口
 */
void SqListTest(void);


#endif /* SqList_h */
