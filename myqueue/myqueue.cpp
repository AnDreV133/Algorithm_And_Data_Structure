//
// Created by dmitr on 14.10.2023.
//

#include "myqueue.h"

void InitQueueArray(Queue *Q)
{
    Q->ukBegin = 0;
    Q->ukEnd = 0;
    Q->len = 0;
    ErrorQueue = QueueOk;
}

void PutQueueArray(Queue *Q, BaseType E)
{
    if (FullQueueArray(Q))
        return;
    Q->buf[Q->ukEnd] = E;
    Q->ukEnd = (Q->ukEnd + 1) % QUEUE_SIZE;
    Q->len++;
}

void GetQueueArray(Queue *Q, BaseType *E)
{
    if (EmptyQueueArray(Q))
        return;
    *E = Q->buf[Q->ukBegin];
    Q->ukBegin = (Q->ukBegin + 1) % QUEUE_SIZE;
    Q->len--;
}

int FullQueueArray(Queue *Q)
{
    if (Q->len == QUEUE_SIZE)
    {
        ErrorQueue = QueueOver;
        return 1;
    }
    return 0;
}

int EmptyQueueArray(Queue *Q) 
{
    if (Q->len == 0)
    {
        ErrorQueue = QueueEmpty;
        return 1;
    }
    return 0;
}

void ReadQueue(Queue *Q, BaseType *E)
{
    if (Q->len == 0)
    {
        ErrorQueue = QueueEmpty;
        return;
    }
    *E = Q->buf[Q->ukBegin];
}