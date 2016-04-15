//
// Created by 王若璇 on 16/4/15.
//

#ifndef RANDOMGRAPH_RANDOMGEOMETRIC_H
#define RANDOMGRAPH_RANDOMGEOMETRIC_H

#include "Graph.h"
#include <vector>
#include <algorithm>
#include "Vertex.h"
#include <map>
#define MAX_SQUARE_SIZE 10000
#define EPS 1e-6
using namespace std;
// A random geometric graph G(n, r)
// is a graph resulting from placing n points
// uniformly at random on the unit square (or on the unit disk)
// and connecting two points iff their
// Euclidean distance is at most the radius r(n).

class RandomGeometric {
private:
    Graph *graph;
    int n;
    int **square;
    int squareSize;
private:
    double limitRadius;
    vector<pair<int,int> > *vertexes;
private:
    double getDistance(pair<int,int> p1,pair<int,int> p2);

public:
    bool isConnect(pair<int,int> p1,pair<int,int> p2);
    Graph* getRandomGraph();
public:
    RandomGeometric(Graph *graph) : graph(graph) { }

    RandomGeometric(int n,int squareSize,int limitRadius) : n(n), squareSize(squareSize),limitRadius(limitRadius) {
        square = new int*[MAX_SQUARE_SIZE];
        for(int i = 0;i<=n;i++){
            square[i] = new int[MAX_SQUARE_SIZE];
        }
        graph = new Graph(n);
        vertexes = new vector<pair<int,int> >();
        vertexes->clear();
    }

    RandomGeometric(int **square) : square(square) { }

    Graph *getGraph() const {
        return graph;
    }

    void setGraph(Graph *graph) {
        RandomGeometric::graph = graph;
    }

    double getLimitRadius() const {
        return limitRadius;
    }

    void setLimitRadius(double limitRadius) {
        RandomGeometric::limitRadius = limitRadius;
    }

    int **getSquare() const {
        return square;
    }

    void setSquare(int **square) {
        RandomGeometric::square = square;
    }

    int getN() const {
        return n;
    }

    void setN(int n) {
        RandomGeometric::n = n;
    }

    int getSquareSize() const {
        return squareSize;
    }

    void setSquareSize(int squareSize) {
        RandomGeometric::squareSize = squareSize;
    }

    vector<pair<int, int>> *getVertexes() const {
        return vertexes;
    }

    void setVertexes(vector<pair<int, int>> *vertexes) {
        RandomGeometric::vertexes = vertexes;
    }
};


#endif //RANDOMGRAPH_RANDOMGEOMETRIC_H
