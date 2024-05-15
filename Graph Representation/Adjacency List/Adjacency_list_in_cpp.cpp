#include <iostream>
#include <vector>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int nodes){
        V = nodes;
        adjList.resize(V);
    }

    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void printGraph(){
        for(int i = 0; i < V; ++i){
            cout << "Adjacency list of vertex: " << i << ": ";
            for(int j : adjList[i]){
                cout << j << " ";
            }
            cout << '\n';
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}