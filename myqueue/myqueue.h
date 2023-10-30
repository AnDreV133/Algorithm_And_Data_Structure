//
// Created by dmitr on 14.10.2023.
//

#ifndef PROJECT_MYQUEUE_H
#define PROJECT_MYQUEUE_H

const int QUEUE_SIZE = 1000;

typedef int BaseType;

int ErrorQueue;

enum ExceptionalSituations
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



#endif // PROJECT_MYQUEUE_H
