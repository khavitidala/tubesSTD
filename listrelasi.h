#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED
#include <iostream>
#include "listaktris.h"
#include "listfilm.h"
#define info(P) P->info
#define next(P) P->next
using namespace std;
typedef struct elmlistrelasi *addressrelasi;
typedef addressaktor infotyperelasi;
struct elmlistrelasi {
    infotyperelasi info;
    addressrelasi next;
};



#endif // LISTRELASI_H_INCLUDED
