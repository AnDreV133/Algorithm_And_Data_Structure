#include <iostream>
#include "mylinerlist/mylinerlist.h"

int main() {
    List l;
    InitList(&l);
    PutList(&l, 5);
    PutList(&l, 3);
    PutList(&l, 10);

    // DoneList(&l);

//    InitList(&l);
    PutList(&l,5);
    PutList(&l, 3);
    PutList(&l, 10);

    for (int i = 0; i < 6; ++i) {
        int temp;
        GetList(&l, &temp);
        std::cout << temp << ' ';
    }

//    Element* pStart = l.start;
//    for (int i = 0; i < 3; ++i) {
//        std::cout << pStart->data << ' ' <<  pStart->next << ' ';
//        pStart = pStart->next;
//    }

    return 0;
}
