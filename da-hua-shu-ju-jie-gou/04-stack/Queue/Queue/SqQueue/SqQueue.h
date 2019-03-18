//
//  SqQueue.h
//  Queue
//
//  Created by 王俊 on 2019/3/14.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef SqQueue_h
#define SqQueue_h

#include <stdio.h>
#include "../Queue.h"

typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

#pragma mark - functions

Status InitSqQueue(SqQueue *Q);
Status ClearSqQueue(SqQueue *Q);
Status DestorySqQueue(SqQueue *Q);
Status SqQueueEmpty(SqQueue Q);
Status GetSqQueueHead(SqQueue *Q, QElemType *e);
int SqQueueLength(SqQueue Q);
Status EnSqQueue(SqQueue *Q, QElemType e);
Status DeSqQueue(SqQueue *Q, QElemType *e);

#pragma mark - test
void SqQueueTest(void);

#endif /* SqQueue_h */
