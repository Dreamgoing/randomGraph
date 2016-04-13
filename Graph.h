//
// Created by 王若璇 on 16/4/13.
//

#ifndef RANDOMGRAPH_GRAPH_H
#define RANDOMGRAPH_GRAPH_H

#define MAX_GRAPH_NUM 100000
#include "Vertex.h"
#include "header.h"
using std::vector;
using std::cout;
using std::endl;
class Graph {

private:
public:
    Graph(vector<vector<Vertex *>> *graph) : graph(graph) { }

private:
    vector<vector<Vertex*> > *graph;
    int **matrix;
   // Let M be an adjacency matrix n×n initialized as the zero matrix.
    int n;
public:
    Graph(int n) : n(n) {
        matrix = new int*[MAX_GRAPH_NUM];
        for(int i = 0;i<=n;i++){
            matrix[i] = new int[MAX_GRAPH_NUM];
        }
        graph = new vector<vector<Vertex* > >(n+1,vector<Vertex*>());
        for(int i = 0;i<=n;i++){
            graph->at(i).clear();
        }
        cout<<"ok"<<endl;


    }
    Graph(int **matrix) : matrix(matrix) { }

    Graph(){}
    Graph(int **matrix,int n) : matrix(matrix),n(n){ }
    void addEdge(Vertex *a,Vertex *b);
    void addEdge(Vertex *a,Vertex *b,int cost);
    void showMatrix();
    bool bfs();
};


#endif //RANDOMGRAPH_GRAPH_H
