//
// Created by 王若璇 on 16/4/15.
//

#include "RandomGeometric.h"
#include "cmath"
double RandomGeometric::getDistance(pair<int, int> p1, pair<int, int> p2) {
    double res = 1.*(p1.first-p2.first)*(p1.first-p2.first)+1.*(p1.second-p2.second)*(p1.second-p2.second);
    res = sqrt(res);
    return res;
}

bool RandomGeometric::isConnect(pair<int, int> p1, pair<int, int> p2) {
    return getDistance(p1, p2) <= RandomGeometric::getLimitRadius()+EPS;
}

Graph *RandomGeometric::getRandomGraph() {
    std::srand(std::time(0));
    pair<int,int> x;
    for (int i = 0; i < this->n; ++i) {
        x.first = rand()%this->getSquareSize();
        x.second = rand()%this->getSquareSize();
        this->vertexes->push_back(x);
    }
    Vertex *a,*b;
    for (int i = 0; i < n; ++i) {
        for(int j = 0;j< i; ++j){
            if (isConnect(vertexes->at(i),vertexes->at(j))){
                if(!graph->isExist(i+1,j+1)){
                    a = new Vertex(i+1);
                    b = new Vertex(j+1);
                    graph->addEdge(a,b);
                }
            }
        }

    }
    return graph;

}
