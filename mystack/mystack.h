#ifndef PROJECT_MYSTACK_H
#define PROJECT_MYSTACK_H

#include "../myqueue/solution.h"

const int STACK_SIZE = 1000;

extern int StackError;

typedef Inquiry BaseType; // Определить тип элемента стека

enum ExceptionalSituationsStack
{
    StackOk,
    StackOver,
    StackEmpty
};

typedef struct Stack
{
    BaseType buf[STACK_SIZE];
    unsigned uk; /* Указывает на элемент, являющийся вершиной
    стека */
} Stack;

void InitStack(Stack *S);

void PutStack(Stack *S, BaseType E);

void GetStack(Stack *S, BaseType *E);

int FullStack(Stack *S);

int EmptyStack(Stack *S);

void ReadStack(Stack *s, BaseType *E);

#endif // PROJECT_MYSTACK_H
