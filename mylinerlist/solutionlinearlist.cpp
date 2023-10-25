#include "solutionlinearlist.h"

void PutListFromArray(List *list, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        PutList(list, array[i]);
    }
}

void CreateListFromArray(List *list, int array[], int size)
{
    InitList(list);

    PutListFromArray(list, array, size);
}

int isPolynomialsEqual(List *list1, List *list2)
{
    BeginPtr(list1);
    BeginPtr(list2);
    int i = 0;
    int constVal1 = 0, constVal2 = 0;
    while (constVal1 == constVal2 && !EndList(list1) && !EndList(list2))
    {
        ReadList(list1, &constVal1);
        ReadList(list2, &constVal2);
        if (constVal1 != constVal2)
            return 0;

        MovePtr(list1);
        MovePtr(list2);
    }

    if (EndList(list1) != EndList(list2))
        return 0;

    return 1;
}

void outputPolinomial(List *list)
{
    BeginPtr(list);
    int exponent = list->n;
    while (!EndList(list))
    {
        int constVal;
        ReadList(list, &constVal);
        MovePtr(list);

        exponent--;

        if (constVal == 0)
            continue;

        if (exponent > 1)
            printf("%dx^%d%c", constVal, exponent, constVal > 0 ? '+' : '-');
        else if (exponent > 0)
            printf("%dx%c", constVal, constVal > 0 ? '+' : '-');
        else
            printf("%d", constVal);
    }
}

// long long getSolvingFormedPolynomialByArray(int constants[], int values[], int size)
// {
//     List constantsList;
//     CreateListFromArray(&constantsList, constants, size);
//     List valuesList;
//     CreateListFromArray(&valuesList, values, size);

//     return getSolvingFormedPolynomialByList(constantsList, valuesList, size);
// }

// long long getSolvingFormedPolynomialByList(List constants, List values, int size)
// {
//     return 0;
// }
