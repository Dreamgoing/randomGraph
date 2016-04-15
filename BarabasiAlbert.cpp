//
// Created by 王若璇 on 16/4/13.
//

//Generates a random Albert-Barabasi graph. The core of the network is
//a random Erdos-Renyi graph, and new vertices are attached using
//linear preferential attachment. The number of links per new vertex
//        can be tuned.
//Generated graph is sent to stdout as a set of links (one per line).
#include "BarabasiAlbert.h"
#include "ErdosRenyi.h"
#include "cmath"
Graph* BarabasiAlbert::initRandomGraph(int n,double p) {
    // For a given n number of vertices,
    // the G(n, p) method generates a graph where each element of the 'n'
    // possible edges is present with independent probability p.
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
                degree->push_back(i);
                degree->push_back(j);
                graph->addEdge(a,b);
            }

        }
    }

    return graph;


}
//-c: size of the core graph (non negative integer, 10 by default)
//-n: number of vertices of the random graph (non negative integer)
//-m: number of links for each new vertex (non negative real)
//-p: connection probability of the core graph (non negative real, .1 by default)"
Graph *BarabasiAlbert::getRandomGraph(int n, int c,double m,double p) {
    std::srand(std::time(0));
    this->graph = initRandomGraph(c,p);
    for(int i = c+1;i<=n;i++){
        double var = m-floor(m);
        int tmp_m = (int)m;
        double plusone;
        plusone= (rand()*1.)/(RAND_MAX*1.);
        int toplimit = (plusone<var)?1:0;
        for(int j = 1;j<tmp_m+toplimit;j++){
            if(degree->size()==0){
                break;
            }
            unsigned long tmp_pos = rand()%(degree->size());

            int dest = degree->at(tmp_pos);
            if(!graph->isExist(i,dest)){
                Vertex *a = new Vertex(i);
                Vertex *b = new Vertex(dest);
                graph->addEdge(a,b);

            }
            degree->push_back(dest);
            degree->push_back(i);
        }

    }



    return graph;
}
