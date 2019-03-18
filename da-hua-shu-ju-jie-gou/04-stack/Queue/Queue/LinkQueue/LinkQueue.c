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
    printf("\n=========== SqQueueTest ==========\n");
    LinkQueue queue;
    
    Status s;
    QElemType e;
    int len=0;
    
    s = InitLinkQueue(&queue);
    printf("InitLinkQueue: %d\n", s);
    
    len = LinkQueueLength(&queue);
    printf("LinkQueueLength: %d\n", len);
    
    e = 998;
    s = EnLinkQueue(&queue, e);
    printf("EnLinkQueue: %d status: %d\n", e, s);
    
    len = LinkQueueLength(&queue);
    printf("LinkQueueLength: %d\n", len);
    
    e = 88;
    s = EnLinkQueue(&queue, e);
    printf("EnLinkQueue: %d status: %d\n", e, s);
    
    s = GetLinkQueueHead(&queue, &e);
    printf("GetLinkQueueHead: %d status: %d\n", e, s);
    
    len = LinkQueueLength(&queue);
    printf("LinkQueueLength: %d\n", len);
    
    s = DeLinkQueue(&queue, &e);
    printf("DeLinkQueue: %d status: %d\n", e, s);
    
    e = 77;
    s = EnLinkQueue(&queue, e);
    printf("EnLinkQueue: %d status: %d\n", e, s);
    
    s = GetLinkQueueHead(&queue, &e);
    printf("GetLinkQueueHead: %d status: %d\n", e, s);
    
    len = LinkQueueLength(&queue);
    printf("LinkQueueLength: %d\n", len);
    
    s = ClearLinkQueue(&queue);
    printf("ClearLinkQueue: %d\n", s);
    
    len = LinkQueueLength(&queue);
    printf("LinkQueueLength: %d\n", len);
    
    s = ClearLinkQueue(&queue);
    printf("ClearLinkQueue: %d\n", s);
}

#pragma mark - functions

Status InitLinkQueue(LinkQueue *Q) {
    Q->rear = (QueuePtr)malloc(sizeof(QNode));
    Q->rear->next = NULL;
    Q->front = Q->rear;
    return OK;
}
Status ClearLinkQueue(LinkQueue *Q) {
    QueuePtr p = Q->front->next;
    while (p) {
        Q->front->next = p->next;
        free(p);
        p = Q->front->next;
    }
    return OK;
}
Status DestoryLinkQueue(LinkQueue *Q) {
    ClearLinkQueue(Q);
    free(Q->front);
    Q->front = NULL;
    Q->rear = NULL;
    Q = NULL;
    return OK;
}
Status LinkQueueEmpty(LinkQueue *Q) {
    return LinkQueueLength(Q) == 0 ? TRUE : FALSE;
}
Status GetLinkQueueHead(LinkQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) {
        return ERROR;
    }
    *e = Q->front->next->data;
    return OK;
}

int LinkQueueLength(LinkQueue *Q) {
    int len = 0;
    QueuePtr p = Q->front->next;
    while (p) {
        p = p->next;
        len++;
    }
    return len;
}

Status EnLinkQueue(LinkQueue *Q, QElemType e) {
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s) return ERROR;
    
    s->data = e;
    s->next = NULL;
    // 插入队尾, 并更新队尾指针
    Q->rear->next = s;
    Q->rear = s;
    
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



