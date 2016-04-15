#include <iostream>
#include "header.h"
#include "Vertex.h"
#include "ErdosRenyi.h"
#include "Graph.h"
#include "BarabasiAlbert.h"
#include "RandomGeometric.h"
#define ERDOS_RENYI
#define BARABASI_ALBERT
#define RANDOM_GERMETRIC

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
void showMenu(){
    cout<<"input your option"<<endl;
    cout<<"a :ErdosRenyi random graph"<<endl;
    cout<<"b :Random Geometric graph"<<endl;
    cout<<"c :BarabasiAlbert random graph"<<endl;
    cout<<"d :exit"<<endl;
}
int main() {
    int n;
    double p;
    char op;
    showMenu();
    while (cin>>op){
        if(op == 'd'){
            break;
        }
#ifdef ERDOS_RENYI
        if(op=='a'){
            cout<<"input the size (n) of graph and the probability (p) between two vertexes \n"
                    " spilt with  space in order"<<endl;
            cin>>n>>p;
            Graph *graph = ErdosRenyi(n,p);
            if(graph->bfs()){
                cout<<"connected"<<endl;
            } else{
                cout<<"disconnected"<<endl;
            }
            cout<<"Erdos Renyi :"<<endl;
            graph->showMatrix();
            cout<<'\n';
#endif
        } else if (op=='b'){
#ifdef RANDOM_GERMETRIC
            cout<<"input the size (n) of graph and the square (s) size of the geometric \n"
                    " square and the the limit radius (r) between two geometric points in order"<<endl;
            int n,s;
            double r;
            cin>>n>>s>>r;
            RandomGeometric *rgModel = new RandomGeometric(n,s,r);
            rgModel->getRandomGraph();
            if(rgModel->getGraph()->bfs()){
                cout<<"connected"<<endl;
            } else{
                cout<<"disconnected"<<endl;
            }
            cout<<"Random Geometric :"<<endl;
            rgModel->getGraph()->showMatrix();
            cout<<'\n';
#endif

        } else if(op=='c'){
#ifdef BARABASI_ALBERT
            BarabasiAlbert *baModel = new BarabasiAlbert(n);
            cout<<"input the size (n) of graph and the probability (p) between\n"
                    " two vertexes spilt with  space in order"<<endl;
            cin>>n>>p;
            int c,m;
            cout<<"input the size (c) of core graph and the links number of \n"
                    "each vertex spilt with space in order"<<endl;
            cin>>c>>m;
            baModel->getRandomGraph(n,c,m,p);
            if(baModel->getGraph()->bfs()){
                cout<<"connected"<<endl;
            } else{
                cout<<"disconnected"<<endl;
            }
            cout<<"Baarabasi Albert :"<<endl;
            baModel->getGraph()->showMatrix();
            cout<<'\n';
#endif
        }

        showMenu();


    }
    return 0;
}