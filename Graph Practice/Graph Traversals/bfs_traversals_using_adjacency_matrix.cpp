#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> adj_matrix;

public:
    Graph(int num_of_vertices){
        this->vertices = num_of_vertices;
        adj_matrix.resize(vertices, vector<int>(vertices, 0));
    }

    void add_edge(int source, int destination){
        adj_matrix[source][destination] = 1;
        adj_matrix[destination][source] = 1;
    }

    void print_graph(){
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                cout << adj_matrix[i][j] << " ";
            }
            cout << '\n';
        }
    }

    void bfs(int source){
        vector<bool> visited(vertices, false);
        queue <int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int current = q.front();
            q.pop();
            cout << current << " ";
            for(int i = 0; i < vertices; i++){
                if(adj_matrix[current][i] == 1 and !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main(){
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 3);
    g.add_edge(1, 4);
    g.add_edge(1, 3);

    g.bfs(0);
    cout << '\n';
    g.print_graph();

    return 0;
}
