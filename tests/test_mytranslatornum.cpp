//
// Created by dmitr on 14.10.2023.
//

#include "test_mytranslatornum.h"
#include "../mytranslatornum/mytranslatornum.h"

void test_outputInBinFormat() {
    long int li = 42;
    printByte(li);

    float f = 42.42;
    printByte(f);

    char cm[][3] = {
            4, 2, 42,
            40, 20, 24,
            0, 1, 10
    };
    printByte((char *) cm);

    long int lia[] = {4, 2};
    printVar(lia, 2);
}