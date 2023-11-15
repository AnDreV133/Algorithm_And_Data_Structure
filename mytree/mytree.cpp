
#include "mytree.h"

#include <stdio.h>
#include <stdlib.h>

int TreeError;

element MemTree[SizeMem];

void InitTree(Tree *T)
{
    InitMem();
    *T = 0;
    TreeError = TREE_OK;
}

void CreateRoot(Tree *T)
{
    if (!EmptyMem())
    {
        int k = NewMem();
        MemTree[k].LSon = 0;
        MemTree[k].RSon = 0;
        *T = k;
        TreeError = TREE_OK;
    }
    else
        TreeError = TREE_NOT_MEM;
}

void WriteDataTree(Tree *T, BaseType E)
{
    int k = *T;
    MemTree[k].Data = E;
    TreeError = TREE_OK;
}

void ReadDataTree(Tree *T, BaseType *E)
{
    int k = *T;
    *E = MemTree[k].Data;
    TreeError = TREE_OK;
}

int IsLSon(Tree *T)
{
    int k = *T;
    TreeError = TREE_OK;
    return (MemTree[k].LSon != 0);
}

int IsRSon(Tree *T)
{
    int k = *T;
    TreeError = TREE_OK;
    return (MemTree[k].RSon != 0);
}

void MoveToLSon(Tree *T, Tree *TS)
{
    int k = *T;
    if (MemTree[k].LSon)
    {
        *TS = MemTree[k].LSon;
        TreeError = TREE_OK;
    }
    else
        TreeError = TREE_UNDER;
}

void MoveToRSon(Tree *T, Tree *TS)
{
    int k = *T;
    if (IsRSon(T))
    {
        *TS = MemTree[k].RSon;
        TreeError = TREE_OK;
    }
    else
        TreeError = TREE_UNDER;
}

int IsEmptyTree(Tree *T)
{
    return !(IsLSon(T) || IsRSon(T));
}

void DellTree(Tree *T)
{
    Tree TS;
    if (IsRSon(T))
    {
        MoveToRSon(T, &TS);
        DellTree(&TS);
    }
    if (IsLSon(T))
    {
        MoveToLSon(T, &TS);
        DellTree(&TS);
    }
    int k = *T;
    DisposeMem(k);
}

void InitMem()
{
    for (int i = 0; i < SizeMem - 1; i++)
    {
        MemTree[0].Data = NULL;
        MemTree[0].LSon = NULL;
        MemTree[i].RSon = i + 1;
    }
    MemTree[SizeMem - 1].LSon = 0;
}

int EmptyMem()
{
    return (MemTree[SizeMem - 1].Data != NULL);
}

int NewMem()
{
    size_t t = MemTree[0].RSon;
    MemTree[0].RSon = MemTree[t].RSon;
    return t;
}

void DisposeMem(int n)
{
    MemTree[n].Data = NULL;
    MemTree[n].LSon = NULL;
    MemTree[n].RSon = MemTree[0].RSon;
    MemTree[0].RSon = n;
}

int isOperation(char c)
{
    return (c == '/' || c == '+' || c == '-' || c == '*');
}

int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

char *s = "+ * 2 4 * 3 5";
// char s[100];

void setExpression(char *expr)
{
    int i = 0;
    while (*expr != 0)
    {
        s[i] = expr[i];
    }
}

void BuildTree(Tree *T)
{
    Tree TS;
    int k;
    if (*s != '\0')
    {
        if (*s == ' ')
            s++;
        if (isOperation(*s))
        {
            WriteDataTree(T, *s);
            s++;

            CreateRoot(&TS);
            k = *T;
            MemTree[k].LSon = TS;
            MoveToLSon(T, &TS);
            BuildTree(&TS);

            CreateRoot(&TS);
            k = *T;
            MemTree[k].RSon = TS;
            MoveToRSon(T, &TS);
            BuildTree(&TS);
        }
        if (isDigit(*s))
        {
            WriteDataTree(T, *s - '0');
            s++;
        }
    }
}

void WritePostfix(Tree *T)
{
    Tree TS;
    if (IsLSon(T))
    {
        MoveToLSon(T, &TS);
        WritePostfix(&TS);
    }
    if (IsRSon(T))
    {
        MoveToRSon(T, &TS);
        WritePostfix(&TS);
    }
    char c;
    ReadDataTree(T, &c);
    if (isDigit(c + '0'))
        c = c + '0';
    printf("%c ", c);
}

int WriteCalc(Tree *T)
{

    Tree TS;
    int op1, op2, res;
    char c;
    if (IsLSon(T))
    {
        MoveToLSon(T, &TS);
        op1 = WriteCalc(&TS);
    }
    if (IsRSon(T))
    {
        MoveToRSon(T, &TS);
        op2 = WriteCalc(&TS);
        ReadDataTree(T, &c);
        switch (c)
        {
        case '*':
            res = op1 * op2;
            break;
        case '/':
            res = op1 / op2;
            break;
        case '+':
            res = op1 + op2;
            break;
        case '-':
            res = op1 - op2;
            break;
        }
        printf("%i %c %i = %i\n", op1, c, op2, res);
    }
    ReadDataTree(T, &c);
    if (isOperation(c))
        return res;
    else
        return c;
}