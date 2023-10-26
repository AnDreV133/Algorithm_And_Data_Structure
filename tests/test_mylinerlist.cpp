#include "test_mylinerlist.h" 

#include <iostream>
#include "../mylinerlist/mylinerlist.h"
#include "../mylinerlist/solutionlinearlist.h"

void test_outputPolinominal()
{
    int constants1[] = {3, 2, 2};
    List list1;
    CreateListFromArray(&list1, constants1, 3);
    outputPolinomial(&list1);
    printf(" - 1\n");

    int constants2[] = {3, 2, 2};
    List list2;
    CreateListFromArray(&list2, constants2, 3);
    outputPolinomial(&list2);
    printf(" - 2\n");

    printf("result: ");
    printf(isPolynomialsEqual(&list1, &list2) ? "true" : "false");
}