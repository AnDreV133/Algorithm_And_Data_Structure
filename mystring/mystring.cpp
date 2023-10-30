//
// Created by dmitr on 14.10.2023.
//

#include <cstdlib>
#include <cstdio>
#include "mystring.h"


int StrError; // Переменная ошибок
unsigned Length(String *s) {
    if (s == NULL || s->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return 0;
    }
    unsigned len = 0;
    while (len < s->max + 1 && s->s[len] != '\0')
        len++;
    if (len == s->max + 1) {
        StrError = STRING_TOO_LONG_ERROR;
        return 0;
    }
    return len;
}
void InitStr(String *st, unsigned n) {
    st->s = (char *) malloc((n + 1) * sizeof(char));
    if (st->s == NULL) {
        StrError = MEMORY_ALLOCATION_ERROR;
        return;
    }

    st->max = n;
    st->s[0] = '\0';
    StrError = NO_ERROR;
}
void WriteToStr(String *st, char *s) {
    if (st == NULL || st->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return;
    }

    unsigned i = 0;
    while (i < st->max && s[i] != '\0') {
        st->s[i] = s[i];
        i++;
    }
    st->s[i] = '\0';
}
void WriteFromStr(char *s, String *st) {
    if (st == NULL || st->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return;
    }
    unsigned len = Length(st);
    for (unsigned i = 0; i <= len; i++)
        s[i] = st->s[i];
}
void InputStr(String *st) {
    if (st == NULL || st->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return;
    }
    char buffer[256];
    printf("Enter a string: ");
    scanf("%s", buffer);
    WriteToStr(st, buffer);
}
void OutputStr(String *st) {
    if (st == NULL || st->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return;
    }
    printf("String: %s\n", st->s);
}

int Comp(String *s1, String *s2) {
    if (s1 == NULL || s1->s == NULL || s2 == NULL || s2->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return 0;
    }
    unsigned i = 0;
    while (s1->s[i] != '\0' && s2->s[i] != '\0' && s1->s[i] == s2->s[i]) {
        i++;
    }
    return s1->s[i] - s2->s[i];
}
void Delete(String *s, unsigned Index, unsigned Count) {
    if (s == NULL || s->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return;
    }
    unsigned len = Length(s);
    if (Index >= len) {
        StrError = INDEX_OUT_OF_BOUNDS_ERROR;
        return;
    }
    if (Index + Count > len)
        Count = len - Index;
    for (unsigned i = Index; i < len - Count; i++)
        s->s[i] = s->s[i + Count];
    s->s[len - Count] = '\0';
}
void Insert(String *Subs, String *s, unsigned Index) {
    if (s == NULL || s->s == NULL || Subs == NULL || Subs->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return;
    }
    unsigned len = Length(s);

    unsigned sublen = Length(Subs);
    if (Index > len) {
        StrError = INDEX_OUT_OF_BOUNDS_ERROR;
        return;
    }
    if (len + sublen >= s->max) {
        StrError = STRING_TOO_LONG_ERROR;
        return;
    }
    for (unsigned i = len + sublen; i >= Index + sublen; i--)
        s->s[i] = s->s[i - sublen];
    for (unsigned i = Index, j = 0; j < sublen; i++, j++)
        s->s[i] = Subs->s[j];
}
void Concat(String *s1, String *s2, String *srez) {
    if (s1 == NULL || s1->s == NULL || s2 == NULL
        || s2->s == NULL || srez == NULL || srez->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return;
    }
    unsigned len1 = Length(s1);
    unsigned len2 = Length(s2);
    if (len1 + len2 >= srez->max) {
        StrError = STRING_TOO_LONG_ERROR;
        return;
    }
    unsigned i;
    for (i = 0; i < len1; i++)
        srez->s[i] = s1->s[i];
    for (unsigned j = 0; j <= len2; j++)
        srez->s[i + j] = s2->s[j];
}
void Copy(String *s, unsigned Index, unsigned Count, String *Subs) {
    if (s == NULL || s->s == NULL || Subs == NULL || Subs->s == NULL) {
        StrError = INVALID_STRING_ERROR;

        return;
    }
    unsigned len = Length(s);
    if (Index >= len) {
        StrError = INDEX_OUT_OF_BOUNDS_ERROR;
        return;
    }
    if (Index + Count > len)
        Count = len - Index;
    for (unsigned i = Index, j = 0; j < Count; i++, j++)
        Subs->s[j] = s->s[i];
    Subs->s[Count] = '\0';
}
unsigned Pos(String *SubS, String *s) {
    if (SubS == NULL || SubS->s == NULL || s == NULL || s->s == NULL) {
        StrError = INVALID_STRING_ERROR;
        return 0;
    }
    unsigned len1 = Length(SubS);
    unsigned len2 = Length(s);
    if (len1 > len2)
        return 0; // Подстрока не найдена
    for (unsigned i = 0; i <= len2 - len1; i++) {
        unsigned j;
        for (j = 0; j < len1; j++)
            if (SubS->s[j] != s->s[i + j])
                break;
        if (j == len1) {
            return i + 1; // Подстрока найдена в позиции i + 1
        }
    }
    return 0; // Подстрока не найдена
}

void DoneStr(String *s) {
    if (s != NULL && s->s != NULL) {
        StrError = INVALID_STRING_ERROR;
        return;
    }
    free(s->s);
    s->s = NULL;
    s->max = 0;
}