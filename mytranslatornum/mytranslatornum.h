//
// Created by dmitr on 14.10.2023.
//

#ifndef PROJECT_MYTRANSLATORNUM_H
#define PROJECT_MYTRANSLATORNUM_H

void printByte(long int a);

void printByte(float a);

void printByte(char *a);

void printVar(long int *a, unsigned size);

void printVar(float *a, unsigned size);

void printVar(char **a, unsigned size);

long long getIntFromBin(const char *begin, const char *end);

double getFloatFromBin(const char *begin, const char *end);

double getFloatFromBinInSimplePresentation(const char *begin, const char *end);

long long getIntFromBinInSimplePresentation(const char *begin, const char *end;

#endif //PROJECT_MYTRANSLATORNUM_H
