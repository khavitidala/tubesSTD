#include "listfilm.h"

void createListFilm(listfilm &L) {
    first(L) = NULL
}
addressfilm createElmListFilm(infotypefilm X, string judul) {
    addressfilm P = new elmlistfilm;
    info(P).judul = judul;
    next(P) = NULL;
    child(P) = NULL;
    return P;
}
void insertfilm(listfilm &L, addressfilm P) {
    if (first(L)!=NULL) {
        next(P) = first(L);
    }
    first(L) = P;
}

