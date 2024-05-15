#include <iostream>
#include <vector>
using namespace std;

enum class Color{ WHITE, GRAY, BLACK };

struct Vertex{
    Color color;
    int d;
    int f;
    int parent;
};

void dfs_visit(vector<vector<int>>& graph, vector<Vertex>& vertices, int u, int& time){
    time++;
    vertices[u].d = time;
    vertices[u].color = Color::GRAY;

    for(int v : graph[u]){
        if(vertices[v].color == Color::WHITE){
            vertices[v].parent = u;
            dfs_visit(graph, vertices, v, time);
        }
    }

    vertices[u].color = Color::BLACK;
    time++;
    vertices[u].f = time;
}

void dfs(vector<vector<int>>& graph, vector<Vertex>& vertices){
    int time = 0;
    for(int u = 0; u < vertices.size(); ++u){
        if(vertices[u].color == Color::WHITE){
            dfs_visit(graph, vertices, u, time);
        }
    }
}

int main(){
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1},
        {0, 4},
        {3}
    };

    int n = graph.size();
    vector<Vertex> vertices(n, {Color:: WHITE, -1, -1, -1});
    dfs(graph, vertices);

    for(int i = 0; i < vertices.size(); i++){
        cout << "Vertex " << i << ": discovery time = " << vertices[i].d << ", finish time = " << vertices[i].f << '\n';
    }

    return 0;
}