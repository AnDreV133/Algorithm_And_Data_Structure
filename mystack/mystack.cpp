//
// Created by dmitr on 14.10.2023.
//

#include "mystack.h"

void initStackArray(Stack *S)
{
    S->uk = 0;
    StackError = StackOk;
}

void PutStack(Stack *S, BaseType E)
{
    if (isFullStackArray(S))
        return;

    S->buf[S->uk] = E;
    S->uk++;
}

void GetStack(Stack *S, BaseType *E)
{
    if (isEmptyStackArray(S))
        return;
    *E = S->buf[S->uk - 1];
    S->uk--;
}

int isFullStackArray(Stack *S)
{
    if (S->uk >= STACK_SIZE)
    {
        StackError = StackOver;
        return 1;
    }
    return 0;
}

int isEmptyStackArray(Stack *S)
{
    if (S->uk == 0)
    {
        StackError = StackEmpty;
        return 1;
    }
    return 0;
}

void ReadStack(Stack *s, BaseType *E)
{
    if (isEmptyStackArray(s))
    {
        StackError = StackEmpty;
        return;
    }
    BaseType t = s->buf[s->uk - 1];
    *E = t;
}