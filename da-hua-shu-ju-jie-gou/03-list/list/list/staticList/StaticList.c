//
//  StaticList.c
//  list
//
//  Created by 王俊 on 2019/2/18.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "StaticList.h"

#pragma mark - test

/**
 静态链表测试
 */
void StaticLinkListTest(void) {
    printf("======================================\n");
    printf("========= StaticLinkListTest =========\n");
    
    StaticLinkList staticLinkList;
    InitStaticLinkList(staticLinkList);
    
    int len = StaticLinkListLength(staticLinkList);
    printf("StaticLinkListLength(staticLinkList): %i\n", len);
    
    Status s = StaticLinkListInsert(staticLinkList, 1, 200);
    printf("StaticLinkListInsert(staticLinkList, 1, 200): %i\n", s);
    
    s = StaticLinkListInsert(staticLinkList, 1, 125);
    printf("StaticLinkListInsert(staticLinkList, 1, 125): %i\n", s);
    
    int index = LocateStaticLinkListElem(staticLinkList, 125);
    printf("LocateStaticLinkListElem(staticLinkList, 125): %i\n", index);
    
    ElemType e = GetStaticLinkListElem(staticLinkList, index);
    printf("GetStaticLinkListElem(staticLinkList, index): %i\n", e);
    
    s = StaticLinkListDelete(staticLinkList, index);
    printf("StaticLinkListDelete(staticLinkList, index): %i\n", s);
    
    s = StaticLinkListInsert(staticLinkList, 1, 125);
    printf("StaticLinkListInsert(staticLinkList, 1, 125): %i\n", s);
    
    s = ClearStaticLinkList(staticLinkList);
    printf("ClearStaticLinkList(staticLinkList): %i\n", s);
    
    
    s = StaticLinkListIsEmpty(staticLinkList);
    printf("StaticLinkListIsEmpty(staticLinkList): %i\n", s);
    
    printf("======================================\n");
}


#pragma mark - StaticLinkList functions
/**
 初始化一个静态链表
 
 @param space 静态链表
 @return 初始化结果
 */
Status InitStaticLinkList(StaticLinkList space) {
    int i;
    for (i=0; i<MAXSIZE_FOR_STATICLINKLIST-1; i++) {
        space[i].cur = i+1;
        space[i].data = 0;
    }
    space[MAXSIZE_FOR_STATICLINKLIST-1].cur=0;
    return OK;
}

/**
 静态链表的插入实现
 
 @param space 静态链表
 @param i 要插入的位置
 @param e 要插入的内容
 @return 插入结果
 */
Status StaticLinkListInsert(StaticLinkList space, int i, ElemType e) {
    int j, k, l;
    k = MAXSIZE_FOR_STATICLINKLIST-1;
    if (i<1 || i>StaticLinkListLength(space)+1) return ERROR;
    j = Malloc_SLL(space);
    if (!j) return ERROR;

    space[j].data = e;
    for (l=1; l<i; l++) {
        k = space[k].cur;
    }
    space[j].cur = space[k].cur;
    space[k].cur = j;

    return OK;
}

/**
 静态链表的删除实现
 
 @param space 静态链表
 @param i 要删除的元素编号
 @return 删除结果
 */
Status StaticLinkListDelete(StaticLinkList space, int i) {
    int j, k;
    
    if (i<1 || i> StaticLinkListLength(space)) return ERROR;
    k = MAXSIZE_FOR_STATICLINKLIST-1;
    for (j=1; j<i; j++) {
        k = space[k].cur;
    }
    
    j = space[k].cur; // space[k] 为要删除元素的前一个
    space[k].cur = space[j].cur;
    Free_SLL(space, j);
    
    return OK;
}

/**
 获取链表长度
 
 @param space 静态链表
 @return 链表长度
 */
int StaticLinkListLength(StaticLinkList space) {
    int j=0;
    int i = space[MAXSIZE_FOR_STATICLINKLIST-1].cur;
    
    while (i) {
        i = space[i].cur;
        j++;
    }
    
    return j;
}


/**
 判断静态链表是否为空
 
 @param space 静态链表
 @return 是否为空
 */
Status StaticLinkListIsEmpty(StaticLinkList space) {
    return StaticLinkListLength(space) == 0 ? TRUE : FALSE;
}

/**
 置空静态链表
 
 @param space 静态链表
 @return 操作是否成功
 */
Status ClearStaticLinkList(StaticLinkList space) {
    int k = MAXSIZE_FOR_STATICLINKLIST-1;
    int len = StaticLinkListLength(space);
    for (int i=0; i<len; i++) {
        space[k].cur=0;
        space[k].data=0;
        
        k = space[k].cur;
    }
    InitStaticLinkList(space);
    return OK;
}


/**
 获取静态链表的元素
 
 @param space 静态链表
 @param i 要获取的元素编号
 @return 链表对应元素
 */
ElemType GetStaticLinkListElem(StaticLinkList space, int i) {
    ElemType e = 0;
    int j, k;
    
    k = MAXSIZE_FOR_STATICLINKLIST-1;
    if (i<1 || i> StaticLinkListLength(space)) return ERROR;
    for (j=1; j<=i; j++) {
        k = space[k].cur;
    }
    e = space[k].data;;
    return e;
}

/**
 获取某元素在静态链表内的位置
 
 @param space 静态链表
 @param e 元素
 @return 编号
 */
int LocateStaticLinkListElem(StaticLinkList space, ElemType e) {
    int index=0,
    i=0,
    len=StaticLinkListLength(space),
    k=MAXSIZE_FOR_STATICLINKLIST-1;
    
    for (i=1; i<len; i++) {
        k=space[k].cur;
        if (space[k].data == e) {
            index = i;
            break;
        }
    }
    
    return index;
}

/**
 模拟动态链表存储空间的分配
 
 @param space 静态链表
 @return 若备用空间链表非空, 则返回分配的节点下标, 否则返回0
 */
int Malloc_SLL(StaticLinkList space) {
    // 数组第0位,始终记录静态链表下一个可用位置
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

/**
 模拟动态l链表存储空间的释放
 
 @param space 静态链表
 @param k 要释放的位置
 */
void Free_SLL(StaticLinkList space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}
