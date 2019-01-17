//
//  List.h
//  list
//
//  Created by 王俊 on 2019/1/16.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef List_h
#define List_h


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


// 相关操作状态定义
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int  Status;            // Status 是函数的类型,其值是函数结果状态码,如 OK 等


// 线性表存储的数据结构定义
typedef int ElemType;           // ElemType类型根据实际情况而定, 这里假设为 int


#endif /* List_h */
