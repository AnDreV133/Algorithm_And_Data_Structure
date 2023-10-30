//
// Created by dmitr on 14.10.2023.
//

#ifndef PROJECT_MYSTACK_H
#define PROJECT_MYSTACK_H

const int STACK_SIZE = 1000;

int StackError;

enum ExceptionalSituations
{
    StackOk,
    StackNotMem,
    StackEnd,
    StackOver,
    StackUnder
};

typedef int BaseType; // Определить тип элемента стека

typedef struct Stack
{
    BaseType buf[STACK_SIZE];
    unsigned uk; /* Указывает на элемент, являющийся вершиной
    стека */
} Stack;

void initStackArray(Stack *S);

void PutStack(Stack *S, BaseType E);

void GetStack(Stack *S, BaseType *E);

int isFullStackArray(Stack *S);

int isEmptyStackArray(Stack *S);

void ReadStack(Stack *s, BaseType *E);

#endif // PROJECT_MYSTACK_H
