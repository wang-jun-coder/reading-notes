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

/**
 ADT 线性表(List)
 Data
     线性表的数据对象集合为{a1,a2,...,an}, 每个元素的类型均为 DataType。
     其中除第一个元素a1外，每一个元素有且仅有一个直接前驱元素，
     除了最后一个元素an外，每一个元素有且仅有一个直接后继元素。
     数据元素之间的关系是一对一的关系
 Operation
     InitList(*L):          初始化操作，建立一个空的线性表 L。
     ListIsEmpty(L):        若线性表为空，返回 true, 否则返回false。
     ClearList(*L);         将线性表置空
     GetElem(L,i,*e):       将线性表 L 的第 i 个元素返回给 e。
     LocateElem(L, e):      在线性表 L 中查找与给定值 e 相等的元素，若查找成功，返回该元素在表中序号表示成功，否则返回0表示失败
     ListInsert(*L,i,e):    在线性表 L 中第 i 个位置插入新元素 e。
     ListDelete(*L,i,*e):   删除线性表中第 i 个位置的元素，并用 e 返回其值。
     ListLength(L):         返回线性表 L 的元素个数
 endADT
 */

// 线性表数据结构定义
#define MAXSIZE 20              // 存储空间初始分配量
typedef int ElemType;           // ElemType类型根据实际情况而定, 这里假设为 int
typedef struct {
    ElemType data[MAXSIZE];     // 数组存储元素, 最大值为 MAXSIZE
    int length;                 // 线性表当前元素
} SqList;

// 相关操作状态定义
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int  Status;            // Status 是函数的类型,其值是函数结果状态码,如 OK 等

#pragma mark - SqList functions
/**
 获取线性表中第 i 个元素

 @param L 线性表 L, 必须已存在
 @param i 要获取元素的位置编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 对应元素返回
 @return 操作结果 OK/ERROR
 */
Status GetElem(SqList L, int i, ElemType *e);


/**
 向线性表的第 i 个位置插入元素

 @param L 线性表, 必须存在
 @param i 位置编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status ListInsert(SqList *L, int i, ElemType e);


/**
 删除线性表第 i 个位置的元素

 @param L 线性表, 必须存在
 @param i 要删除的位置编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 被删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status ListDelete(SqList *L, int i, ElemType *e);


/**
 初始化一个线性表

 @param L 初始化线性表的返回
 @return 操作结果 OK/ERROR
 */
Status InitList(SqList *L);


/**
 判断线性表是否为空

 @param L 要判断的线性表,必须存在
 @return TRUE/FALSE
 */
Status ListIsEmpty(SqList L);


/**
 查找元素在线性表中的编号

 @param L 线性表, 必须存在
 @param e 要查找的元素
 @return 查找结果, 该元素在线性表中的位置编号, 0 表示不存在
 */
 int LocateElem(SqList L, ElemType e);


/**
 获取线性表的长度

 @param L 线性表, 必须存在
 @return 线性表长度
 */
int ListLength(SqList L);


/**
 清空线性表

 @param L 要清空的线性表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearList(SqList *L);


#pragma mark - test

/**
 SqList 相关的测试函数入口
 */
void SqListTest(void);


#endif /* SqList_h */
