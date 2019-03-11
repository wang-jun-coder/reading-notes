//
//  Stack.h
//  stack
//
//  Created by 王俊 on 2019/3/11.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

/**
 ADT 栈（stack）
 Data
 同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系。
 Operation
 InitStact(*S)    : 初始化操作，建立一个线性表 S。
 DestroyStack(*S): 若栈存在，则销毁它。
 ClearStack(*S): 将栈清空。
 StackEmpty(S): 若栈为空，返回 true，否则返回 false。
 GetTop(*S, *e): 若栈存在且非空，用 e 返回 S 的栈顶元素。
 Push(*S, e): 若栈 S 存在，插入新元素 e 到栈 S 中并成为栈顶元素。
 Pop(*S, *e): 删除栈 S 中栈顶元素，并用 e 返回其值。
 StackLength(S): 返回栈 S 的元素个数
 endADT
 */

// 相关操作状态定义
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int  Status;            // Status 是函数的类型,其值是函数结果状态码,如 OK 等


// 栈存储的数据结构定义
typedef int SElemType;          // ElemType类型根据实际情况而定, 这里假设为 int
#define MAXSIZE 100



#endif /* Stack_h */
