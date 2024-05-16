#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    int Vertices;
    vector<list<int>> adjList;
public:
    Graph(int Vertices){
        this->Vertices = Vertices;
        adjList.resize(Vertices);
    }

    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void printGraph(){
        for(int i = 0; i < Vertices; i++){
            cout << "Adjacency list of vertex " << i << " :";
            for(auto j : adjList[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g(5);

    g.addEdge(0, 4);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.printGraph();

    return 0;
}

