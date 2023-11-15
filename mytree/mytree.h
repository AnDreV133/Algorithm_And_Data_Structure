#ifndef PROJECT_MYTREE_H
#define PROJECT_MYTREE_H

enum ExceptionalSituations
{
    TREE_OK,
    TREE_NOT_MEM,
    TREE_UNDER
};
extern int TreeError;

const int SizeMem = 100;

typedef char BaseType;

typedef int PtrEl;

typedef struct element{
    BaseType Data;
    PtrEl LSon;
    PtrEl RSon;
}element;
typedef PtrEl Tree;

extern element MemTree[SizeMem];

void InitTree(Tree *T);

void CreateRoot(Tree *T);

void WriteDataTree(Tree *T, BaseType E);

void ReadDataTree(Tree *T, BaseType *E);

int IsLSon(Tree *T);

int IsRSon(Tree *T);

void MoveToLSon(Tree *T, Tree *TS);

void MoveToRSon(Tree *T, Tree *TS);

int IsEmptyTree(Tree *T);

void DellTree(Tree *T);

void InitMem();

int EmptyMem();

int NewMem();

void DisposeMem(int n);

int WriteCalc(Tree *T);

void WritePostfix(Tree *T);

void BuildTree(Tree *T);

void setExpression(char *expr);

#endif // PROJECT_MYTREE_H
