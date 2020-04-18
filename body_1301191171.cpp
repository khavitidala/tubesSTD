#include "header_1301191171.h"

void createNode(string X, adrNode &P) {
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
void addNode(Graph &G, string X, string Y) {
    adrNode P;
    adrNode Q;
    createNode(Y, Q);
    createNode(X, P);
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
adrNode findNode(adrNode first, string X) {
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
void connect(Graph &G, string X, string Y) {
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
            cout<<"Judul Film :"<<info(P);
            if(edge(P)!=NULL) {
                //cout<<info(infor(edge(P)));
                Q = edge(P);
                    if(edge(P)!=NULL) {
                        cout<<"\nPemeran :"<<info(infor(Q));
                        cout<<endl;
                        while(nextr(Q)!=NULL) {
                            Q = nextr(Q);
                            adrNode R = infor(Q);
                            cout<<info(R);
                            cout<<", ";
                        }
                    }
            }
            cout<<endl;
            if(next(P)!=NULL) {
                while(next(P)!=NULL) {
                    P = next(P);
                    cout<<"Judul Film :"<<info(P);
                    Q = edge(P);
                    if(edge(P)!=NULL) {
                        cout<<"\nPemeran :"<<info(infor(Q));
                        cout<<endl;
                        while(nextr(Q)!=NULL) {
                            Q = nextr(Q);
                            adrNode R = infor(Q);
                            cout<<info(R);
                            cout<<", ";
                        }
                    }
                    cout<<endl;
                }
            }
        }
}
