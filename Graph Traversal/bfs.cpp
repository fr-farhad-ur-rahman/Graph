#include <iostream>
#include <vector>
#include <queue>
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
    }

    void bfs(int start){
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while(!q.empty()){
            int current = q.front();
            cout << current << " ";
            q.pop();

            for(int neighbor : adjList[current]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
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
    g.bfs(0);
    cout << "\n\n";
    g.printGraph();
    return 0;
}
