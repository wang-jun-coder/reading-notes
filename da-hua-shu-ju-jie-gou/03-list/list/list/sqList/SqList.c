//
//  SqList.c
//  list
//
//  Created by 王俊 on 2019/1/15.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "SqList.h"
#include <string.h>
#include <stdlib.h>

#pragma mark - test
/**
 SqList 相关的测试函数入口
 */
void SqListTest(void) {
    
    printf("======================================\n");
    printf("============= SqListTest =============\n");
    
    SqList L;
    InitSqList(&L);
    
    printf("InitList: %p -- %d\n", L.data, L.length);
    printf("ListIsEmpty: %d\n", SqListIsEmpty(L));
    
    for (int i=0; i<=5; i++) {
        ElemType e = rand();
        printf("ListInsert: i: %d elem: %d result: %d\n", i, e, SqListInsert(&L, i, e));
    }
    printf("ListIsEmpty: %d\n", SqListIsEmpty(L));
    
    ElemType e = -1;
    printf("LocateElem %d: %d\n", e, LocateSqListElem(L, e));
    
    int checkIndex = 1+(rand()%SqListLength(L));
    GetSqListElem(L, checkIndex, &e);
    printf("GetElem %d: %d\n", checkIndex, e);
    
    printf("LocateElem %d: %d\n",e, LocateSqListElem(L, e));
    printf("ListLength: %d\n", SqListLength(L));
    
    printf("ClearList: %d\n", ClearSqList(&L));
    printf("ListIsEmpty: %d\n", SqListIsEmpty(L));
    
    printf("======================================\n");
}

#pragma mark - SqList functions
/**
 获取线性表中第 i 个元素
 
 @param L 线性表 L, 必须已存在
 @param i 要获取的编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 对应元素返回
 @return 操作结果 OK/ERROR
 */
Status GetSqListElem(SqList L, int i, ElemType *e) {
    if (L.length==0 || i<1 || i>L.length) return ERROR;
    *e = L.data[i-1];
    return OK;
}

/**
 向线性表的第 i 个位置插入元素
 
 @param L 线性表, 必须存在
 @param i 位置编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 要插入的元素
 @return 操作结果 OK/ERROR
 */
Status SqListInsert(SqList *L, int i, ElemType e) {
    
    // 顺序线性表已满
    if (L->length == MAXSIZE) return ERROR;
    // i 不在线性表范围内
    if (i<1 || i>L->length+1) return ERROR;
    // 插入数据位置不在表尾部
    if (i<=L->length) {
        // 将要插入位置后的元素统一后移一位
        for (int k=L->length-1; k>=i-1; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length ++;

    return OK;
}


/**
 删除线性表第 i 个位置的元素
 
 @param L 线性表, 必须存在
 @param i 要删除的位置编号, 需满足 i ≤ i ≤ ListLength(L)
 @param e 被删除的元素返回
 @return 操作结果 OK/ERROR
 */
Status SqListDelete(SqList *L, int i, ElemType *e) {
    
    // 空表
    if (L->length==0) return ERROR;
    // 要删除的位置不正确
    if (i<1 || i>L->length) return ERROR;
    *e = L->data[i-1];
    // 若删除的不是表尾, 将删除位置后继元素前移
    if (i<L->length) {
        for (int k=i; k<L->length; k++) {
            L->data[k-1] = L->data[k];
        }
    }
    L->length --;
    
    return OK;
}

/**
 初始化一个线性表
 
 @param L 初始化线性表的返回
 @return 操作结果 OK/ERROR
 */
Status InitSqList(SqList *L) {
    SqList list;
    memset(list.data, 0, MAXSIZE*sizeof(ElemType));
    list.length = 0;
    *L = list;
    return OK;
}

/**
 判断线性表是否为空
 
 @param L 要判断的线性表,必须存在
 @return TRUE/FALSE
 */
Status SqListIsEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

/**
 查找元素在线性表中的编号
 
 @param L 线性表, 必须存在
 @param e 要查找的元素
 @return 查找结果, 该元素在线性表中的位置编号, 0 表示不存在
 */
int LocateSqListElem(SqList L, ElemType e) {
    
    // 空表
    if (L.length==0) return ERROR;
    
    int index = 0;
    for (int i=0; i<L.length; i++) {
        if (e == L.data[i]) {
            index = i+1;
            break;
        }
    }
    
    return index;
}

/**
 获取线性表的长度
 
 @param L 线性表, 必须存在
 @return 线性表长度
 */
int SqListLength(SqList L) {
    return L.length;
}

/**
 清空线性表
 
 @param L 要清空的线性表, 必须存在
 @return 操作结果 OK/ERROR
 */
Status ClearSqList(SqList *L) {
    memset(L->data, 0, MAXSIZE*sizeof(ElemType));
    L->length = 0;
    return OK;
}
