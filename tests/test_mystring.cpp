//
// Created by dmitr on 14.10.2023.
//

#include "test_mystring.h"

#include "../mystring/mystring.h"

void test_outputStringWithUsageFunction() {
    String str1, str2, str3, result;
    InitStr(&str1, 100);
    InitStr(&str2, 100);
    InitStr(&str3, 100);
    InitStr(&result, 200);
    char s1[] = "i-e-a-i-a-i-o";
    WriteToStr(&str1, s1);
    char s2[] = " World";
    WriteToStr(&str2, s2);
    char s3[] = "Hell";
    WriteToStr(&str3, s3);
    Delete(&str1, 0, 12);
    Insert(&str3, &str1, 0);
    Concat(&str1, &str2, &result);
    OutputStr(&result);
    DoneStr(&str1);
    DoneStr(&str2);
    DoneStr(&result);
}