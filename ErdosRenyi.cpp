//
// Created by 王若璇 on 16/4/13.
//

#include "Graph.h"
#include "ctime"
#include "ErdosRenyi.h"


Graph* ErdosRenyi::getRandomGraph(int n,double p) {
    // For a given n number of vertices,
    // the G(n, p) method generates a graph where each element of the 'n'
    // possible edges is present with independent probability p.
    Graph *graph = new Graph(n);
    std::srand(std::time(0));
    int upBound = (int)p*100000;
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
