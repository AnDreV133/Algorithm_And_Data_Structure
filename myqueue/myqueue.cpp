//
// Created by dmitr on 14.10.2023.
//

#include "myqueue.h"

int QueueError;

void InitQueue(Queue *Q)
{
    Q->ukBegin = 0;
    Q->ukEnd = 0;
    Q->len = 0;
    QueueError = QueueOk;
}

void PutQueue(Queue *Q, BaseType E)
{
    if (FullQueue(Q))
        return;
    Q->buf[Q->ukEnd] = E;
    Q->ukEnd = (Q->ukEnd + 1) % QUEUE_SIZE;
    Q->len++;
}

void GetQueue(Queue *Q, BaseType *E)
{
    if (EmptyQueue(Q))
        return;
    *E = Q->buf[Q->ukBegin];
    Q->ukBegin = (Q->ukBegin + 1) % QUEUE_SIZE;
    Q->len--;
}

int FullQueue(Queue *Q)
{
    if (Q->len == QUEUE_SIZE)
    {
        QueueError = QueueOver;
        return 1;
    }
    return 0;
}

int EmptyQueue(Queue *Q) 
{
    if (Q->len == 0)
    {
        QueueError = QueueEmpty;
        return 1;
    }
    return 0;
}

void ReadQueue(Queue *Q, BaseType *E)
{
    if (Q->len == 0)
    {
        QueueError = QueueEmpty;
        return;
    }
    *E = Q->buf[Q->ukBegin];
}