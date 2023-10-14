//
// Created by dmitr on 14.10.2023.
//

#ifndef PROJECT_MYSTRING_H
#define PROJECT_MYSTRING_H

enum ExceptionalSituations {
    NO_ERROR = 0,
    MEMORY_ALLOCATION_ERROR = 1,
    STRING_TOO_LONG_ERROR = 2,
    INDEX_OUT_OF_BOUNDS_ERROR = 3,
    INVALID_STRING_ERROR = 4
};
extern int StrError; // Переменная ошибок
typedef struct String {
    char *s; // Признак конца строки - символ '\0'
    unsigned max; // Макс кол-во символов в строке, определяется при инициализации
} String;

void InitStr(String *st, unsigned n);

void WriteToStr(String *st, char *s);

void WriteFromStr(char *s, String *st);

void InputStr(String *st);

void OutputStr(String *st);

int Comp(String *s1, String *s2);

void Delete(String *s, unsigned Index, unsigned Count);

void Insert(String *Subs, String *s, unsigned Index);

void Concat(String *s1, String *s2, String *srez);

void Copy(String *s, unsigned Index, unsigned Count, String *Subs);

unsigned Length(String *s);

unsigned Pos(String *SubS, String *s);

void DoneStr(String *s);

#endif //PROJECT_MYSTRING_H
