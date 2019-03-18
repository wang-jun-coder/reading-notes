//
//  Queue.h
//  Queue
//
//  Created by 王俊 on 2019/3/14.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

/**
 ADT 队列(Queue)
 Data
    同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系
 Operation
     InitQueue(*Q); 初始化操作，建立一个空队列 Q。
     DestroyQueue(*Q); 若队列 Q 存在，则销毁它。
     ClearQueue(*Q); 将队列 Q 清空。
     QueueEmpty(*Q); 若队列为空，返回 true，否则返回 false。
     GetHead(Q, *e); 若队列 Q 存在且非空，用 e 返回队列 Q 的队头元素。
     EnQueue(*Q, e); 若队列 Q 存在，插入新元素 e 到队列的队尾元素。
     DeQueue(*Q, e); 删除队列的队头元素，并用 e 返回其值。
     QueueLength(Q); 返回队列 Q 的元素个数
 endADT
 */

// 相关操作状态定义
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int  Status;            // Status 是函数的类型,其值是函数结果状态码,如 OK 等

// 栈存储的数据结构定义
typedef int QElemType;          // ElemType类型根据实际情况而定, 这里假设为 int
#define MAXSIZE 100

#endif /* Queue_h */
