//
// Created by 王若璇 on 16/4/13.
//

#include <queue>
#include "Graph.h"

void Graph::showMatrix() {
    for(int i = 1;i<=Graph::n;i++){
        for(int j = 1;j<=Graph::n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<'\n';
    }

}

void Graph::addEdge(Vertex *a, Vertex *b) {
    int tmp_a = a->getVertex();
    cout<<tmp_a<<endl;
    int tmp_b = b->getVertex();
    this->graph->at(tmp_a).push_back(b);
    this->graph->at(tmp_b).push_back(a);
    this->matrix[tmp_a][tmp_b] = 1;
    this->matrix[tmp_b][tmp_a] = 1;
}

void Graph::addEdge(Vertex *a, Vertex *b, int cost) {
    this->addEdge(a,b);
    this->matrix[a->getVertex()][b->getVertex()] = cost;
    this->matrix[a->getVertex()][b->getVertex()] = cost;
}

bool Graph::bfs() {
    using std::queue;
    bool vis[MAX_GRAPH_NUM];
    memset(vis,0, sizeof(vis));
    int cnt = 0;
    queue<Vertex*> qu;
    Vertex* now;
    Vertex* next;
    now = new Vertex(1);
    qu.push(now);
    while (!qu.empty()){
        now = qu.front();
        qu.pop();
        int tmp_now = now->getVertex();
        if(vis[tmp_now]){
            continue;
        }
        vis[tmp_now] = true;
        cnt++;
        if(cnt==n){
            return true;
        }
        for(int i = 0;i<Graph::graph->at(tmp_now).size();i++){
            next = Graph::graph->at(tmp_now)[i];
            int next_tmp = next->getVertex();
            if(!vis[next_tmp]){
                qu.push(next);
            }
        }

    }

    return false;
}
