//
//  LinkQueue.c
//  Queue
//
//  Created by 王俊 on 2019/3/18.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "LinkQueue.h"
#include <stdlib.h>

#pragma mark - test
void LinkQueueTest(void) {
    printf("=========== SqQueueTest ==========\n");
    
}

#pragma mark - functions

Status InitLinkQueue(LinkQueue *Q) {
    Q->rear = (QueuePtr)malloc(sizeof(QNode));
    Q->front = NULL;
    return OK;
}

int LinkQueueLength(LinkQueue Q) {
    return 0;
}

Status EnLinkQueue(LinkQueue *Q, QElemType e) {
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s) return ERROR;
    
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    return OK;
}
Status DeLinkQueue(LinkQueue *Q, QElemType *e) {
    QueuePtr p;
    if (Q->front == Q->rear) {
        return ERROR;
    }
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
    
}



