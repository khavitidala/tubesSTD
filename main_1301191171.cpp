#include "header_1301191171.h"

int main()
{
    Graph G;
    createGraph(G);
    cout<<"MEMBUAT NODE PADA GRAF"<<endl;
    addNode(G, 'A');
    addNode(G, 'B');
    addNode(G, 'C');
    addNode(G, 'D');
    printGraph(G);
    cout<<"\nMEMBUAT EDGE PADA GRAF"<<endl;
    connect(G, 'A', 'C');
    connect(G, 'A', 'D');
    connect(G, 'B', 'D');
    connect(G, 'D', 'C');
    printGraph(G);
    cout<<"\nMENAMBAHKAN NODE LAIN PADA GRAF"<<endl;
addNode(G,'A');
addNode(G,'B');
addNode(G,'E');
addNode(G,'C');
addNode(G,'H');
addNode(G,'D');
addNode(G,'F');
printGraph(G);
cout<<"\nMENAMBAHKAN EDGE BARU PADA GRAF"<<endl;
connect(G,'A','E');
connect(G,'E','B');
connect(G,'H','B');
connect(G,'F','D');
connect(G,'C','F');
connect(G,'C','E');
connect(G,'D','H');
connect(G,'E','H');
connect(G,'F','A');
printGraph(G);
cout<<"\nMENAMPILKAN IN DEGREE SETIAP NODE"<<endl;
adrNode P = row(G);
while(next(P)!=NULL) {
    cout<<"In Degree "<<info(P)<<" = "<<inDegree(G, info(P))<<endl;
    P=next(P);
}
    cout<<"In Degree "<<info(P)<<" = "<<inDegree(G, info(P))<<endl;
    return 0;
}
