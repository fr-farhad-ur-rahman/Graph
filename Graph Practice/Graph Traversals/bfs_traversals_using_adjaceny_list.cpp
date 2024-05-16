#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int vertices){
        this->vertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void bfs(int source){
        vector<int> visited(vertices, false);
        queue <int> q;

        visited[source] = 1;
        q.push(source);

        while(!q.empty()){
            int current = q.front();
            q.pop();

            cout << current << " ";

            for(int adjacent_vertex: adjList[current]){
                if(!visited[adjacent_vertex]){
                    visited[adjacent_vertex] = true;
                    q.push(adjacent_vertex);
                }
            }
        }
    }

    void printGraph(){
        for(int i = 0; i < vertices; i++){
            cout << "Adjacency list of " << i << " : ";
            for(int j : adjList[i]){
                cout << j << ' ';
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

    g.bfs(0);

    cout << '\n';
    g.printGraph();

    return 0;
}