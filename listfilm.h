#ifndef LISTFILM_H_INCLUDED
#define LISTFILM_H_INCLUDED
#include <iostream>
#include "listrelasi.h"
#define info(P) P->info
#define next(P) P->next
#define child(P) P->child
#define first(L) L.first
using namespace std;
typedef film infotypefilm;
typedef struct elmlistfilm *addressfilm;
struct film {
    string judul;
    string rating;
    string sutradara;
};
struct elmlistfilm {
    infotypefilm info;
    addressfilm next;
    addressrelasi child;
};
struct listfilm {
    addressfilm first;
};
void createListFilm(listfilm &L);
addressfilm createElmListFilm(infotypefilm X);
void insertfilm(listfilm &L, addressfilm P);

#endif // LISTFILM_H_INCLUDED
