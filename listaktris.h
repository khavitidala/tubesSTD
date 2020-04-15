#ifndef LISTAKTRIS_H_INCLUDED
#define LISTAKTRIS_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
using namespace std;
typedef struct elmlistaktor *addressaktor;
typedef aktor infotypeaktor;
struct aktor {
    string nama;
};
struct elmlistaktor {
    infotypeaktor info;
    addressaktor next;
};
struct listaktor {
    addressaktor first;
};
.
#endif // LISTAKTRIS_H_INCLUDED
