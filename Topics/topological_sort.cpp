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
        adjList[src].push_back(dest); // For undirected graph, you might want to push dest to adjList[src] and also push src to adjList[dest]
    }

    void DFSUtil(int v, vector<bool>& visited, stack<int>& order) {
        visited[v] = true; // Mark the current node as visited

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited, order); // Recursive call for unvisited neighbors
            }
        }

        order.push(v); // Push the current node onto the stack after processing all its neighbors
    }

    void topologicalSort() {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        stack<int> order;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFSUtil(i, visited, order);
            }
        }

        // Print the topological order
        cout << "Topological order: ";
        while (!order.empty()) {
            cout << order.top() << " ";
            order.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6); // Create a graph with 6 nodes

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
