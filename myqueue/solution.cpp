#include "solution.h"

#include <locale.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "myqueue.h"
#include "../mystack/mystack.h"
#include <cstdio>
#include <iostream>

short processing = 0; // 0 - нет обрабатываемых задач, 1 - есть

void setExpression(Inquiry *source, Inquiry E)
{
    for (size_t i = 0; i < NAME_SIZE; i++)
    {
        source->Name[i] = E.Name[i];
    }

    source->Time = E.Time;

    source->P = E.P;
}

void WriteRequest(Inquiry *inquiry)
{
    printf("(Name:%s Time:%u Prior:%d)",
           inquiry->Name,
           inquiry->Time,
           inquiry->P);
}

void WriteManyRequests(Inquiry **inquiries, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        WriteRequest(inquiries[i]);
    }
}

void WriteTable(Stack *s, Queue *f1, Queue *f2, Queue *f3, int n)
{
    printf("\nF0:");
    for (size_t i = 0; i < f1->len; i++)
    {
        WriteRequest(&f1->buf[i]);
    }
    printf("\nF1:");
    for (size_t i = 0; i < f2->len; i++)
    {
        WriteRequest(&f2->buf[i]);
    }
    printf("\nF2:");
    for (size_t i = 0; i < f3->len; i++)
    {
        WriteRequest(&f3->buf[i]);
    }
    printf("\n\n");
}

void GenMassRequest(Inquiry **inquiries, int n)
{
    srand(time(NULL));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < NAME_SIZE - 1; j++)
        {
            inquiries[i]->Name[j] = (rand() % 26) + 65;
        }
        inquiries[i]->Name[NAME_SIZE - 1] = '\0';

        inquiries[i]->Time = rand() % 10000;

        inquiries[i]->P = rand() % 3;
        // printf(">");
        // WriteRequest(inquiries[i]);
        // printf("< ");
    }
}

void defineRequest(Inquiry *inquiry, Queue *F0, Queue *F1, Queue *F2)
{
    if (inquiry->P == 0)
    {
        PutQueue(F0, *inquiry);
    }
    else if (inquiry->P == 1)
    {
        PutQueue(F1, *inquiry);
    }
    else if (inquiry->P == 2)
    {
        PutQueue(F2, *inquiry);
    }
}

void RequestDistribution(Inquiry **inquiries, Queue *F0, Queue *F1, Queue *F2, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        defineRequest(inquiries[i], F0, F1, F2);
    }
}

void startModelOfProcessingSystem(int n)
{
    srand(time(NULL));
    Inquiry **inquaries = (Inquiry **)malloc(n * sizeof(Inquiry *)); // выделение памяти на массив
    for (size_t i = 0; i < n; i++)
    {
        inquaries[i] = (Inquiry *)calloc(1, sizeof(Inquiry));
    }

    GenMassRequest(inquaries, n); // генерация массива запросов
    WriteManyRequests(inquaries, n);

    Queue F0, F1, F2; // Объявление и инициализация очередей
    InitQueue(&F0);
    InitQueue(&F1);
    InitQueue(&F2);
    Stack S; // Объявление и инициализация стека
    InitStack(&S);

    RequestDistribution(inquaries, &F0, &F1, &F2, n); // распределили запросы по очередям
    WriteTable(&S, &F0, &F1, &F2, n);
    std::cout << std::endl; // удалить
    Inquiry inquaryForCalculate[] = {
        {"qq1231230",
         42, 0},
        {"qq1231231",
         4242, 1}};

    Inquiry processedInquiry;

    while (!EmptyStack(&S) || !EmptyQueue(&F0) ||
           !EmptyQueue(&F1) || !EmptyQueue(&F2))
    {
        if (!processing)
        {
            if (!EmptyQueue(&F0))
            {
                GetQueue(&F0, &processedInquiry);
                processing = 1;
            }
            else if (!EmptyQueue(&F1))
            {
                GetQueue(&F1, &processedInquiry);
                processing = 1;
            }
            else if (!EmptyQueue(&F2))
            {
                GetQueue(&F2, &processedInquiry);
                processing = 1;
            }
        }

        // включ новых запросов
        if (rand() % 100 >= 50)
        {
            defineRequest(&(inquaryForCalculate[rand() % 100 >= 50]), &F0, &F1, &F2);
        }

        if (processing)
        {
            if (!EmptyQueue(&F0) && processedInquiry.P > 0)
            {
                PutStack(&S, processedInquiry);
                GetQueue(&F0, &processedInquiry);
            }
            else if (!EmptyQueue(&F1) && processedInquiry.P > 1)
            {
                PutStack(&S, processedInquiry);
                GetQueue(&F1, &processedInquiry);
            }
            else if (!EmptyStack(&S))
            {
                GetStack(&S, &processedInquiry);
            }

            WriteRequest(&processedInquiry);
            printf(" > ");
            processing = 0;
        }
    }
}