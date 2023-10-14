//
// Created by dmitr on 14.10.2023.
//

#include <cmath>
#include <cstdio>
#include "mytranslatornum.h"

long long getIntFromBinInSimplePresentation(const char *begin, const char *end) {
    int sign = (*begin == '-') ? -1 : 1;
    if (sign < 0) begin++;
    long long term = 1;
    long long val = 0;
    while (begin < end) {
        end--;
        if (*end == '1')
            val += term;
        term <<= 1;
    }
    return sign * val;
}
double getFloatFromBinInSimplePresentation(const char *begin, const char *end) {
    int sign = (*begin == '-') ? -1 : 1;
    if (sign < 0) begin++;
    const char *splitPoint = begin;
    while (splitPoint < end && *splitPoint != '.')
        splitPoint++;
    long long intPart = getIntFromBinInSimplePresentation(begin, splitPoint);
    double term = 0.5;
    double val = 0;
    while (splitPoint < end) {
        splitPoint++;
        if (*splitPoint == '1')
            val += term;
        term /= 2;
    }
    return ((double) intPart + val) * sign;
}
double getFloatFromBin(const char *begin, const char *end) {
    int sign = (*begin == '1') ? -1 : 1;

    long long shift = getIntFromBinInSimplePresentation(begin + 1, begin + 9) - 127;
    double term = pow(2, shift);
    double val = term;
    begin += 9;
    while (begin < end) {
        term /= 2;
        if (*begin == '1')
            val += term;
        begin++;
    }
    return ((double) val) * sign;
}
long long getIntFromBin(const char *begin, const char *end) {
    long long term = 1;
    long long val = 0;
    if (*begin == '0') {
        while (begin < end) {
            end--;
            if (*end == '1')
                val += term;
            term <<= 1;
        }
        return val;
    } else {
        while (begin < end) {
            end--;
            if (*end == '0')
                val += term;
            term <<= 1;
        }
        return -val - 1;
    }
}

bool getBit(long long a, long long i) {
    return a & (1 << i);
}
void printByte(long int a) {
    for (long long i = sizeof(long int) * 8 - 1; i >= 0; --i)
        printf("%d", getBit(a, i));
    printf("\n");
}
void printByte(float a) {
    auto copyA = reinterpret_cast<long *>(&a);
    for (long long i = sizeof(float) * 8 - 1; i >= 0; --i)
        printf("%d", getBit(*copyA, i));
    printf("\n");
}
void printByte(char *a) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (long long k = sizeof(char) * 8 - 1; k >= 0; --k)
                printf("%d", getBit((long long) a[3*i + j], k));
            printf(" ");
        }
        printf("\n");
    }
}
void printVar(long int *a, unsigned size) {
    for (int i = 0; i < size; ++i)
        printByte(a[i]);
}
void printVar(float *a, unsigned size) {
    for (int i = 0; i < size; ++i)
        printByte(a[i]);
}
void printVar(char **a, unsigned size) {
    for (int i = 0; i < size; ++i)
        printByte(a[i]);
}