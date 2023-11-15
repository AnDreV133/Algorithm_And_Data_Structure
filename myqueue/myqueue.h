#ifndef PROJECT_MYQUEUE_H
#define PROJECT_MYQUEUE_H

#include "solution.h"

const int QUEUE_SIZE = 1000;

typedef Inquiry BaseType;

extern int QueueError;

enum ExceptionalSituationsQueue
{
    QueueOk,
    QueueEmpty,
    QueueOver,
};

typedef struct Queue
{
    BaseType buf[QUEUE_SIZE];
    unsigned ukEnd;
    unsigned ukBegin;
    unsigned len;
} Queue;

void InitQueue(Queue *Q);

void PutQueue(Queue *Q, BaseType E);

void GetQueue(Queue *Q, BaseType *E);

int FullQueue(Queue *Q);

int EmptyQueue(Queue *Q);

void ReadQueue(Queue *Q, BaseType *E);

#endif // PROJECT_MYQUEUE_H
