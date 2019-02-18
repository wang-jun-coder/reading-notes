//
//  StaticList.h
//  list
//
//  Created by 王俊 on 2019/2/18.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef StaticList_h
#define StaticList_h


#include <stdio.h>
#include "../List.h"

#define MAXSIZE_FOR_STATICLINKLIST 1000
typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE_FOR_STATICLINKLIST];


#pragma mark - StaticLinkList functions

/**
 初始化一个静态链表

 @param space 静态链表
 @return 初始化结果
 */
Status InitStaticLinkList(StaticLinkList space);


/**
 静态链表的插入实现

 @param space 静态链表
 @param i 要插入的位置
 @param e 要插入的内容
 @return 插入结果
 */
Status StaticLinkListInsert(StaticLinkList space, int i, ElemType e);


/**
 静态链表的删除实现

 @param space 静态链表
 @param i 要删除的元素编号
 @return 删除结果
 */
Status StaticLinkListDelete(StaticLinkList space, int i);

/**
 获取链表长度

 @param space 静态链表
 @return 链表长度
 */
int StaticLinkListLength(StaticLinkList space);


/**
 判断静态链表是否为空

 @param space 静态链表
 @return 是否为空
 */
Status StaticLinkListIsEmpty(StaticLinkList space);


/**
 置空静态链表

 @param space 静态链表
 @return 操作是否成功
 */
Status ClearStaticLinkList(StaticLinkList space);


/**
 获取静态链表的元素

 @param space 静态链表
 @param i 要获取的元素编号
 @return 链表对应元素
 */
ElemType GetStaticLinkListElem(StaticLinkList space, int i);


/**
 获取某元素在静态链表内的位置

 @param space 静态链表
 @param e 元素
 @return 编号
 */
int LocateStaticLinkListElem(StaticLinkList space, ElemType e);

/**
 模拟动态链表存储空间的分配

 @param space 静态链表
 @return 若备用空间链表非空, 则返回分配的节点下标, 否则返回0
 */
int Malloc_SLL(StaticLinkList space);


/**
 模拟动态l链表存储空间的释放

 @param space 静态链表
 @param k 要释放的位置
 */
void Free_SLL(StaticLinkList space, int k);

#pragma mark - test

/**
 静态链表测试
 */
void StaticLinkListTest(void);

#endif /* StaticList_h */
