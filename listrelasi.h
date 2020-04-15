#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED
#include <iostream>
#include "listaktris.h"
#include "listfilm.h"
#define info(P) P->info
#define next(P) P->next
#define first(L) L.first
using namespace std;
typedef struct elmlistrelasi *addressrelasi;
typedef addressaktor infotyperelasi;
struct elmlistrelasi {
    infotyperelasi info;
    addressrelasi next;
};
struct listrelasi {
    addressrelasi first;
};



#endif // LISTRELASI_H_INCLUDED
