#ifndef HEADER_1301191171_H_INCLUDED
#define HEADER_1301191171_H_INCLUDED
#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define edge(P) P->edge
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
};
struct Edge {
    infotypeEdge infor;
    adrEdge nextr;
};
struct Graph {
    adrNode column;
    adrNode row;
};

void createNode(string X, adrNode &P);
void createGraph(Graph &G);
void insertLast(adrNode &first, adrNode P);
void addNode(Graph &G, string X, string Y);
adrNode findNode(adrNode first, string X);
adrEdge alokasi(adrNode Q);
void connect(Graph &G, string X, string Y);
void printGraph(Graph G);

#endif // HEADER_1301191171_H_INCLUDED
