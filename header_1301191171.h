#ifndef HEADER_1301191171_H_INCLUDED
#define HEADER_1301191171_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define info(P) P->info
#define next(P) P->next
#define edge(P) P->edge
#define counts(P) P->counts
#define column(G) G.column
#define row(G) G.row
#define infor(R) R->infor //info relasi
#define nextr(R) R->nextr //next relasi
using namespace std;
typedef string infotypeNode;
typedef struct node *adrNode;
typedef struct Edge *adrEdge;
typedef adrNode infotypeEdge;
struct node {
   infotypeNode info;
   adrNode next;
   adrEdge edge;
   int counts;
};
struct Edge {
    infotypeEdge infor;
    adrEdge nextr;
};
struct Graph {
    adrNode column;
    adrNode row;
};
/*struct akt {
    string nama1;
    string nama2;
};
struct elm {
        string duaJudul;
        int id;
        int hitung;
        vector<akt> art;
};

vector<elm> mainElm;*/

void createNode(string X, adrNode &P);
void createGraph(Graph &G);
void insertLast(adrNode &first, adrNode P);
void addNode(Graph &G, string X, string Y);
adrNode findNode(adrNode first, string X);
adrEdge findEdge(adrEdge first, string X);
adrEdge alokasi(adrNode Q);
void connect(Graph &G, string X, string Y);
void printGraph(Graph G);
void seringMain(Graph G);
void filmSama(Graph G);
void printGraphKW(Graph G, int syarat);
void deleteFilm(Graph &G, string X);
void deleteAktorCol(Graph &G, string X);
void deleteAktor(Graph &G, string X);
void filmYangArtisnyaBanyak(Graph G);
void showParticularMovie(Graph G, string X);
void menuUtama(Graph &G);
void pilihan(Graph &G, int menu);
void keluar();

#endif // HEADER_1301191171_H_INCLUDED
