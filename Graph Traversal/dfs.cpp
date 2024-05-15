#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

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

    void DFSUtil(int v, vector<bool>& visited){
        visited[v] = true;
        cout << v << " ";

        for(int neighbor : adjList[v]){
            if(!visited[neighbor]){
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start){
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
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

    cout << "BFS traversal starting from vertex 0: ";
    g.DFS(0);
    cout << "\n\n";
    g.printGraph();
    return 0;
}
