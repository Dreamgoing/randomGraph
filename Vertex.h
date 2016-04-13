//
// Created by 王若璇 on 16/4/13.
//

#ifndef RANDOMGRAPH_VERTEX_H
#define RANDOMGRAPH_VERTEX_H

#include "header.h"
class Vertex {

private:
    int vertex;



public:
    Vertex(int vertex) : vertex(vertex) { }
public:
    int getVertex() const {
        return vertex;
    }

    void setVertex(int vertex) {
        Vertex::vertex = vertex;
    }
};


#endif //RANDOMGRAPH_VERTEX_H
