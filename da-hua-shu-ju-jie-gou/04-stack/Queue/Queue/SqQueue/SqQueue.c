//
//  SqQueue.c
//  Queue
//
//  Created by 王俊 on 2019/3/14.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "SqQueue.h"
#pragma mark - test
void SqQueueTest(void) {
    printf("\n=========== SqQueueTest ==========\n");
    Status s;
    int len;
    QElemType e;
    
    SqQueue queue;
    s = InitSqQueue(&queue);
    printf("InitQueue: %d\n", s);
    
    len = SqQueueLength(queue);
    printf("SqQueueLength: %d\n", len);
    
    e = 998;
    s = EnSqQueue(&queue, e);
    printf("EnSqQueue: %d status: %d\n", e, s);
    
    len = SqQueueLength(queue);
    printf("SqQueueLength: %d\n", len);
    
    
    e = 98;
    s = EnSqQueue(&queue, e);
    printf("EnSqQueue: %d status: %d\n", e, s);
    
    len = SqQueueLength(queue);
    printf("SqQueueLength: %d\n", len);
    
    e = 77;
    s = EnSqQueue(&queue, e);
    printf("EnSqQueue: %d status: %d\n", e, s);
    
    s = GetSqQueueHead(&queue, &e);
    printf("GetSqQueueHead: %d status: %d\n", e, s);
    
    s = DeSqQueue(&queue, &e);
    printf("DeSqQueue: %d status: %d\n", e, s);
    
    s = GetSqQueueHead(&queue, &e);
    printf("GetSqQueueHead: %d status: %d\n", e, s);
    
    s = ClearSqQueue(&queue);
    printf("ClearSqQueue: %d\n", s);
    
    len = SqQueueLength(queue);
    printf("SqQueueLength: %d\n", len);
}

#pragma mark - functions

Status InitSqQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
Status ClearSqQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
Status DestorySqQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
Status SqQueueEmpty(SqQueue Q) {
    return SqQueueLength(Q) == 0 ? TRUE : FALSE;
}
Status GetSqQueueHead(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) {
        return ERROR;
    }

    *e = Q->data[Q->front];
    return OK;
}

int SqQueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status EnSqQueue(SqQueue *Q, QElemType e) {
    // 队列已满
    if ((Q->rear+1) % MAXSIZE == Q->front) {
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return OK;
}
Status DeSqQueue(SqQueue *Q, QElemType *e) {
    // 队列空
    if (Q->front == Q->rear) {
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return OK;
}

