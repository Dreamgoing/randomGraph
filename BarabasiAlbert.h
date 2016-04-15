//
// Created by 王若璇 on 16/4/13.
//

#ifndef RANDOMGRAPH_BARABASIALBERT_H
#define RANDOMGRAPH_BARABASIALBERT_H


#include "Graph.h"
#include <vector>
#include <algorithm>
using namespace std;

class BarabasiAlbert {
private:
    vector<int> *degree;
    Graph *graph;
    int n;
public:
    BarabasiAlbert(Graph *graph) : graph(graph) { }
    BarabasiAlbert(vector<int> *degree) : degree(degree) { }

    BarabasiAlbert(int n) : n(n) {
        graph = new Graph(n);
        degree = new vector<int>();
        degree->clear();
    }

    BarabasiAlbert(){degree = new vector<int>();}


public:
//initial args n is the num vertex of the graph
//c is the initial graph size
// p is the probability
    Graph* getRandomGraph(int n,int c,double m,double p);
    Graph* initRandomGraph(int n,double p);

    int getN() const {
        return n;
    }

    void setN(int n) {
        BarabasiAlbert::n = n;
    }

    Graph *getGraph() const {
        return graph;
    }

    void setGraph(Graph *graph) {
        BarabasiAlbert::graph = graph;
    }

    vector<int> *getDegree() const {
        return degree;
    }

    void setDegree(vector<int> *degree) {
        BarabasiAlbert::degree = degree;
    }
};


#endif //RANDOMGRAPH_BARABASIALBERT_H
