#include "header_1301191171.h"

void createNode(char X, adrNode &P) {
    P = new node;
    info(P) = X;
    next(P) = NULL;
    edge(P) = NULL;
}
void createGraph(Graph &G) {
    row(G) = NULL;
    column(G) = NULL;
}
void insertLast(adrNode &first, adrNode P) {
    if(first == NULL) {
        first = P;
    } else {
        adrNode Q = first;
        while(next(Q)!=NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void addNode(Graph &G, char X) {
    adrNode P;
    createNode(X, P);
    adrNode Q;
    createNode(X, Q);
    //cout<<"cek1";
    if(row(G)!=NULL&&column(G)!=NULL) {
        //cout<<"cek2";
        adrNode ada = findNode(row(G), X);
        adrNode ada2 = findNode(column(G), X);
        if(ada == NULL&&ada2==NULL) {
            //cout<<"cek3";
            insertLast(row(G), P);
            insertLast(column(G), Q);
        }
    } else {
        //cout<<"else";
        insertLast(row(G), P);
        insertLast(column(G), Q);
    }
}
adrNode findNode(adrNode first, char X) {
    adrNode P = first;
    if(first!=NULL) {
        while(X!=info(P)&&next(P)!=NULL) {
            P = next(P);
        }
    }
    if(info(P)==X) {
        return P;
    } else {
        return NULL;
    }
}
adrEdge alokasi(adrNode Q) {
    adrEdge R = new Edge;
    infor(R) = Q;
    nextr(R) = NULL;
    return R;
}
void connect(Graph &G, char X, char Y) {
    if(row(G)!=NULL&&column(G)!=NULL) {
        adrNode P = findNode(row(G), X);
        adrNode Q = findNode(column(G), Y);
        adrEdge R = alokasi(Q);
        nextr(R) = edge(P);
        edge(P) = R;
    }
}
void printGraph(Graph G) {
        adrNode P = row(G);
        adrEdge Q;
        if(P!=NULL) {
            cout<<info(P)<<" - ";
            if(edge(P)!=NULL) {
                //cout<<info(infor(edge(P)));
                Q = edge(P);
                    if(edge(P)!=NULL) {
                        cout<<info(infor(Q));
                        cout<<" - ";
                        while(nextr(Q)!=NULL) {
                            Q = nextr(Q);
                            adrNode R = infor(Q);
                            cout<<info(R);
                            cout<<" - ";
                        }
                    }
            }
            cout<<endl;
            if(next(P)!=NULL) {
                while(next(P)!=NULL) {
                    P = next(P);
                    cout<<info(P)<<" - ";
                    Q = edge(P);
                    if(edge(P)!=NULL) {
                        cout<<info(infor(Q));
                        cout<<" - ";
                        while(nextr(Q)!=NULL) {
                            Q = nextr(Q);
                            adrNode R = infor(Q);
                            cout<<info(R);
                            cout<<" - ";
                        }
                    }
                    cout<<endl;
                }
            }
        }
}
int inDegree(Graph G, char V) {
    adrNode P = row(G);
    int hitung = 0;
    while(next(P)!=NULL) {
        adrEdge R = edge(P);
        while(nextr(R)!=NULL) {
            if(info(infor(R))==V) {
                hitung++;
            }
            R=nextr(R);
        }
        P=next(P);
    }

    adrEdge R = edge(P);
        while(nextr(R)!=NULL) {
            if(info(infor(R))==V) {
                hitung++;
            }
            R=nextr(R);
        }
    return hitung;
}
