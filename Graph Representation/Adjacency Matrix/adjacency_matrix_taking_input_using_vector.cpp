#include <iostream>
#include <vector>
using namespace std;

class Graph{
    vector<vector<bool>> adjMatrix;
    int numVertices;

public:
    // Constructor to inititialzie the graph with given number of vertices
    Graph(int numVertices) : numVertices(numVertices){
        // Resize the adjacency matrix to numVertices x numVertices and inititialize with false
        adjMatrix.resize(numVertices, vector<bool> (numVertices, false));
    }
    // function to add edge
    void addEdge(int i, int j){
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }
    // function to remove edge
    void removeEdge(int i, int j){
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }
    // function to check connectivity of two edges
    bool isConnect(int i, int j){

    }
    // function to print graph
    void printGraph(){
        cout << "    ";
        for(int i = 0; i < numVertices; i++){
            cout << i << "_";
        }
        cout << '\n';
        for(int i = 0; i < numVertices; i++){
            cout << i << "_: ";
            for(int j = 0; j < numVertices; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

int main(){
    cout << "Enter number of vertices: " << '\n';
    int numVertices; cin >> numVertices;
    Graph g(numVertices);

    cout << "Enter edges: (vertex1, vertex2) ->\n";
    for(int i = 0; i < numVertices; i++){
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;

        g.addEdge(vertex1, vertex2);
    }

    g.printGraph();
    return 0;
}
