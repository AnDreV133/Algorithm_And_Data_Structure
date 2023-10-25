#include <iostream>
#include "mylinerlist/mylinerlist.h"
#include "mylinerlist/solutionlinearlist.h"

int main()
{
    int constants[] = {3, 2, 2};
    int values[] = {2, 2, 2};
    std::cout << getSolvingFormedPolynomial(constants, values);

    return 0;
}
