#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> adj_matrix;
public:
    Graph(int vertices){
        this->vertices = vertices;
        adj_matrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int src, int dest){
        adj_matrix[src][dest] = 1;
        adj_matrix[dest][src] = 1;
    }

    void printGraph(){
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                cout << adj_matrix[i][j] << " ";
            }
            cout << '\n';
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
