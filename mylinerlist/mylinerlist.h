//
// Created by dmitr on 21.10.2023.
//

#ifndef ALGORITHM_AND_DATA_STRUCTURE_MYLINERLIST_H
#define ALGORITHM_AND_DATA_STRUCTURE_MYLINERLIST_H

enum ExceptionalSituations {
    ListOk,
    ListNotMem,
    ListEnd,
};

extern int ListError; // Переменная ошибок

typedef int BaseType;
typedef struct Element *ptrel;

typedef struct Element {
    ptrel next; // указатель на след элемент
    BaseType data; // данные
} Element;

typedef struct List {
    ptrel start; // указатель на начало
    ptrel ptr; // рабочий указатель
    unsigned n; // длинна списка
} List;



void InitList(List *L);

void PutList(List *L, BaseType E);

void GetList(List *L, BaseType *E);

void ReadList(List *L, BaseType *E);

int EndList(List *L);

unsigned int Count(List *l);

void BeginPtr(List *L);

void EndPtr(List *L);

void MovePtr(List *L);

void MoveTo(List *L, unsigned n);

void DoneList(List *L);

void CopyList(List *L1, List *L2);



#endif //ALGORITHM_AND_DATA_STRUCTURE_MYLINERLIST_H
