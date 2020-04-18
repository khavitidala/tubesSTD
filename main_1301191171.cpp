#include "header_1301191171.h"

int main()
{
    Graph G;
    createGraph(G);
    cout<<"MEMBUAT NODE PADA GRAF"<<endl;
    //X film
    //Y artis
    //addNode(G, film, artis)
    addNode(G, "Harry potter", "Dumbledore");
    printGraph(G);
    cout<<"\nMEMBUAT EDGE PADA GRAF"<<endl;
    connect(G, "Harry potter", "Dumbledore");
    printGraph(G);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    addNode(G, a, b);
    connect(G, a, b);
    printGraph(G);
    return 0;
}
