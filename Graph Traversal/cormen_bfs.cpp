#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Structure to represent a vertex in the graph
struct Vertex {
    char color; // Color of the vertex: 'W' for white, 'G' for gray, 'B' for black
    int d;      // Distance of the vertex from the source
};

// Function to perform Breadth-First Search on a graph
void BFS(vector<vector<int>>& graph, int source) {
    int n = graph.size(); // Number of vertices in the graph

    // Initialize an array of vertices
    vector<Vertex> vertices(n);
    for (int i = 0; i < n; ++i) {
        vertices[i].color = 'W'; // Initialize all vertices to white
        vertices[i].d = -1;      // Initialize all distances to -1
    }

    // Set the color and distance of the source vertex
    vertices[source].color = 'G'; // Source vertex is gray
    vertices[source].d = 0;       // Distance of source vertex is 0

    // Create a queue for BFS
    queue<int> q;

    // Enqueue the source vertex
    q.push(source);

    // Perform BFS
    while (!q.empty()) {
        int u = q.front(); // Dequeue a vertex u
        q.pop();

        // Explore all neighbors of vertex u
        for (int v : graph[u]) {
            // If neighbor v is white (unvisited)
            if (vertices[v].color == 'W') {
                vertices[v].color = 'G';     // Mark v as gray (visited but not explored)
                vertices[v].d = vertices[u].d + 1; // Update distance of v from the source
                q.push(v);                  // Enqueue v
            }
        }

        // Mark vertex u as black (explored)
        vertices[u].color = 'B';
    }

    // Output the distances from the source vertex
    for (int i = 0; i < n; ++i) {
        cout << "Distance of vertex " << i << " from source: " << vertices[i].d << endl;
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1},     // Adjacency list of vertex 0
        {0, 2},  // Adjacency list of vertex 1
        {1, 3},  // Adjacency list of vertex 2
        {2, 4},  // Adjacency list of vertex 3
        {3}      // Adjacency list of vertex 4
    };

    // Start BFS from vertex 0
    BFS(graph, 0);

    return 0;
}
