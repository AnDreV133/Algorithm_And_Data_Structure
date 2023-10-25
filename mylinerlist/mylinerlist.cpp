//
// Created by dmitr on 21.10.2023.
//

#include "mylinerlist.h"

#include <stdlib.h>

int ListError;

void InitList(List *L)
{
    ptrel zeroElem = (ptrel)malloc(sizeof(Element));
    if (zeroElem != NULL)
    {
        zeroElem->next = NULL;
        zeroElem->data = NULL;
        L->n = 0;
        L->start = zeroElem;
        L->ptr = zeroElem;
        ListError = ListOk;
    }
    else
        ListError = ListNotMem;
}

void PutList(List *L, BaseType E)
{
    ptrel buf = (ptrel)malloc(sizeof(Element));
    if (buf != NULL)
    {
        buf->data = E;
        buf->next =
            L->ptr->next;
        L->ptr->next = buf;
        ListError = ListOk;
        L->n++;
    }
    else
    {
        ListError = ListNotMem;
    }
}

void GetList(List *L, BaseType *E)
{
    ptrel pntr = NULL;
    if (!EndList(L))
    {
        pntr = L->ptr->next;
        L->ptr->next = pntr->next;
        *E = pntr->data;
        L->n--;
    }
    else
        ListError = ListEnd;

    free(pntr);
}

void ReadList(List *L, BaseType *E)
{
    if (EndList(L))
    {
        ListError = ListEnd;
    }
    else
        *E = L->ptr->next->data;
}

int EndList(List *L)
{
    if (!L->ptr->next)
    {
        ListError = ListEnd;
        return 1;
    }
    else
        return 0;
}

unsigned int Count(List *L)
{
    return L->n;
}

void BeginPtr(List *L)
{
    L->ptr = L->start;
}

void EndPtr(List *L)
{
    while (!EndList(L))
        L->ptr = L->ptr->next;
}

void MovePtr(List *L)
{
    if (!EndList(L))
        L->ptr = L->ptr->next;
    else
        ListError = ListEnd;
}

void MoveTo(List *L, unsigned n)
{
    BeginPtr(L);

    int i = 0;
    while (i < n && !EndList(L))
    {
        L->ptr = L->ptr->next;
        i++;
    }

    if (i < n)
        ListError = ListEnd;
}

void DoneList(List *L)
{
    BeginPtr(L);
    while (L->n != 0)
    {
        BaseType E;
        GetList(L, &E);
        L->n--;
    }

    free(L->start);
    L->ptr = NULL;
}

void CopyList(List *L1, List *L2)
{
    BaseType E;
    L2->n = L1->n;
    BeginPtr(L1);
    BeginPtr(L2);
    while (!EndList(L1))
    {
        ReadList(L1, &E);
        PutList(L2, E);
        MovePtr(L1);
        MovePtr(L2);
    }
}