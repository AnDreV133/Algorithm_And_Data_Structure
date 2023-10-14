//
// Created by dmitr on 14.10.2023.
//

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "test_mysorts.h"
#include "../mysorts/mysorts.h"

#define AMOUNT_TEST(testCode, counter) { counter = testCode; }
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

struct SortWithInjectionFuncTag {
    long long (*sort)(int*, int);
    char name[255];
};

struct GeneratingFuncTag {
    void (*generate)(int *, size_t);
    char name[255];
};

void generateRandomArray(int *a, unsigned long long n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 10000;
}

void generateOrderedArray(int *a, unsigned long long n) {
    for (int i = 0; i < n; ++i)
        a[i] = i;
}

void generateOrderedBackwards(int *a, unsigned long long n) {
    for (int i = 0; i < n; ++i)
        a[i] = (int) n - i - 1;
}

void checkAmountCompares(long long (*sortFunc)(int *, int),
                         void (*generateFunc)(int *, size_t),
                         size_t size, char *experimentName) {
    static size_t runCounter = 1;
    static int innerBuffer[110000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);
    unsigned long long countOperations;
    AMOUNT_TEST(sortFunc(innerBuffer, size), countOperations)
    printf("Status: ");
    printf("OK! Amount of compares: %llu\n", countOperations);
// запись в файл
    char filename[256];
    sprintf(filename, "../data1/%s.csv", experimentName);
    FILE *f = fopen(filename, "a");
    if (f == NULL) {
        printf("FileOpenError %s", filename);
        exit(1);
    }
    fprintf(f, "%d; %llu\n", size, countOperations);
    fclose(f);
}

void amountComparesExperiment() {
    SortWithInjectionFuncTag sorts[] = {
            {bubbleSort,    "bubbleSort"},
            {bubbleSort1,   "bubbleSort1"},
            {bubbleSort2,   "bubbleSort2"},
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
            {shellSort,     "shellSort"},
            {quickSort,     "quickSort"},
            {heapSort,      "heapSort"}
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);
    GeneratingFuncTag GeneratingFuncTags[] = {
// генерируется случайный массив
            {generateRandomArray,      "random"},
// генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     "ordered"},
// генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(GeneratingFuncTags);
    for (size_t size = 5; size <= 45; size += 5) {
        printf("------------------------------\n");
        printf("Size: %zu\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
// генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_compares",
                        sorts[i].name, GeneratingFuncTags[j].name);
                checkAmountCompares(
                        sorts[i].sort,
                        GeneratingFuncTags[j].generate,
                        size,
                        filename

                );
            }
        }
        printf("\n");
    }
}