#ifndef ALGORITHM_AND_DATA_STRUCTURE_SOLUTION_H
#define ALGORITHM_AND_DATA_STRUCTURE_SOLUTION_H

const int NAME_SIZE = 10;

typedef struct Inquiry
{
    char Name[NAME_SIZE]; // Имя запроса
    unsigned Time; // Время обслуживания
    int P;        /* Приоритет задачи: 0 — высший,
                             1 — средний, 2 — низший */
} Inquiry;

void setExpression(Inquiry *source, Inquiry E);


void startModelOfProcessingSystem(int n);

#endif
