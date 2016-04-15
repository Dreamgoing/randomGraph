#include <iostream>
#include "header.h"
#include "Vertex.h"
#include "ErdosRenyi.h"
#include "Graph.h"
#include "BarabasiAlbert.h"

#define ERDOS_RENYI
#define BARABASI_ALBERT

using namespace std;

Graph* ErdosRenyi(int n,double p) {
    // For a given n number of vertices,
    // the G(n, p) method generates a graph where each element of the 'n'
    // possible edges is present with independent probability p.
    Graph *graph = new Graph(n);
    std::srand(std::time(0));
    int upBound = (int)100000*p;
    Vertex *a;
    Vertex *b;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<i;j++){
            int randomVal = std::rand()%100000;
            if(randomVal<upBound){
                a = new Vertex(i);
                b = new Vertex(j);
                graph->addEdge(a,b);
            }

        }
    }

    return graph;


}
int main() {
    int n;
    double p;
    while (cin>>n>>p){
#ifdef ERDOS_RENYI
        Graph *graph = ErdosRenyi(n,p);
        if(graph->bfs()){
            cout<<"connected"<<endl;
        } else{
            cout<<"disconnected"<<endl;
        }
        graph->showMatrix();
#endif
#ifdef BARABASI_ALBERT
        BarabasiAlbert *baModel = new BarabasiAlbert(n);
        int c = n/2;
        int m = n/2;
        baModel->getRandomGraph(n,c,m,p);
        if(baModel->getGraph()->bfs()){
            cout<<"connected"<<endl;
        } else{
            cout<<"disconnected"<<endl;
        }
        baModel->getGraph()->showMatrix();
#endif


    }
    return 0;
}