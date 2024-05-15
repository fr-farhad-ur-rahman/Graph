#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    Graph(int nodes) {
        V = nodes;
        adjList.resize(V);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void colorGraph(){
        vector<int> result(V, -1);
        unordered_set<int> usedColors;

        result[0] = 0;
        for(int v = 1; v < V; v++){
            for(int neighbor : adjList[v]){
                if(result[neighbor] != -1){
                    usedColors.insert(result[neighbor]);
                }
            }

            int color;
            for(color = 0; color < V; ++color){
                if(!usedColors.count(color)) break;
            }

            result[v] = color;
            usedColors.clear();
        }

        for(int i = 0; i < V; ++i){
            cout << "Vertex " << i << " is assigned color " << result[i] << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.colorGraph();

    return 0;
}
