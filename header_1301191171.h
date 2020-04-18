#ifndef HEADER_1301191171_H_INCLUDED
#define HEADER_1301191171_H_INCLUDED
#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define edge(P) P->edge
#define column(G) G.column
#define row(G) G.row
#define infor(R) R->infor
#define nextr(R) R->nextr
using namespace std;
typedef char infotypeNode;
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

void createNode(char X, adrNode &P);
void createGraph(Graph &G);
void insertLast(adrNode &first, adrNode P);
void addNode(Graph &G, char X);
adrNode findNode(adrNode first, char X);
adrEdge alokasi(adrNode Q);
void connect(Graph &G, char X, char Y);
void printGraph(Graph G);
int inDegree(Graph G, char V);

#endif // HEADER_1301191171_H_INCLUDED
