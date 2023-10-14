//
// Created by dmitr on 14.10.2023.
//

#include <iostream>
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

void test_outputInDigitFromBinFormat() {
    char s1[] = "-101010";
    std::cout << getIntFromBinInSimplePresentation(s1, s1 + 7) << '\n';
    char s2[] = "101010.011010111000010101";
    std::cout << getFloatFromBinInSimplePresentation(s2, s2 + 25) << '\n';
    char s3[] = "00000000000000000000000000101010";
    std::cout << getIntFromBin(s3, s3 + 32) << '\n';
    char s3_[] = "11111111111111111111111111010110";
    std::cout << getIntFromBin(s3_, s3_ + 32) << '\n';
    char s4[] = "01000010001010011010111000010101";
    std::cout << getFloatFromBin(s4, s4 + 32) << '\n';
}