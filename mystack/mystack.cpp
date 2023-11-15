#include "mystack.h"

 int StackError;

void InitStack(Stack *S)
{
    S->uk = 0;
    StackError = StackOk;
}

void PutStack(Stack *S, BaseType E)
{
    if (FullStack(S))
        return;

    S->buf[S->uk] = E;
    S->uk++;
}

void GetStack(Stack *S, BaseType *E)
{
    if (EmptyStack(S))
        return;
    *E = S->buf[S->uk - 1];
    S->uk--;
}

int FullStack(Stack *S)
{
    if (S->uk >= STACK_SIZE)
    {
        StackError = StackOver;
        return 1;
    }
    return 0;
}

int EmptyStack(Stack *S)
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
    if (EmptyStack(s))
    {
        StackError = StackEmpty;
        return;
    }
    BaseType t = s->buf[s->uk - 1];
    *E = t;
}