#include <bits/stdc++.h>
using namespace std;

class Graph{
    static const int MAX_VERTICES = 100;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    Graph(int numVertices) : numVertices(numVertices){
        for(int i = 0; i < numVertices; i++){
            for(int j = 0; j < numVertices; j++){
                adjMatrix[i][j] = false;
            }
        }
    }

    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    bool isConnected(int, int j);
    void printList();
};

void Graph::addEdge(int i, int j){
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
}

void Graph::removeEdge(int i, int j){
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
}

void Graph::printList(){
    cout << "   ";
    for(int i = 0; i < numVertices; ++i){
        cout << i << ":";
    }
    cout << '\n';
    for(int i = 0; i < numVertices; i++){
        cout << i << ": ";
        for(int j = 0; j < numVertices; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 2);

    g.printList();
    return 0;
}
