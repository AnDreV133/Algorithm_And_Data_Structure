#include "mytree/mytree.h"
#include <stdio.h>
#include "malloc.h"

int main()
{
    Tree T;
    InitTree(&T);
    CreateRoot(&T);
    // char s[100] = "+ * 2 4 * 3 5";
    // setExpression(s);
    // printf("%s\n\n",s); 
    BuildTree(&T);
    WritePostfix(&T);
    puts("\n");
    WriteCalc(&T);

    return 0;
}