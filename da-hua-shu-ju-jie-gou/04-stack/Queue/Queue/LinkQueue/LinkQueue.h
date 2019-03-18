//
//  LinkQueue.h
//  Queue
//
//  Created by 王俊 on 2019/3/18.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>
#include "../Queue.h"

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;


typedef struct {
    QueuePtr front, rear;
} LinkQueue;

#pragma mark - functions

Status InitLinkQueue(LinkQueue *Q);
Status ClearLinkQueue(LinkQueue *Q);
Status DestoryLinkQueue(LinkQueue *Q);
Status LinkQueueEmpty(LinkQueue *Q);
Status GetLinkQueueHead(LinkQueue *Q, QElemType *e);
int LinkQueueLength(LinkQueue *Q);
Status EnLinkQueue(LinkQueue *Q, QElemType e);
Status DeLinkQueue(LinkQueue *Q, QElemType *e);


#pragma mark - test
void LinkQueueTest(void);


#endif /* LinkQueue_h */
