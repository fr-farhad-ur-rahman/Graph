#include <stdio.h>
#include <stdlib.h>

// Define the structure for the graph node
typedef struct Node {
    int vertex;         // Vertex of the node
    int weight;         // Weight of the edge (if any)
    struct Node* next;  // Pointer to the next node in the adjacency list
} Node;

// Define the structure for the graph
typedef struct Graph {
    int numVertices;    // Number of vertices in the graph
    Node** adjList;     // Array of pointers to the adjacency lists
} Graph;

// Function prototypes
Node* createNode(int vertex, int weight);
Graph* createGraph(int numVertices);
void freeGraph(Graph* graph);
void addEdge(Graph* graph, int src, int dest, int weight);
void printGraph(Graph* graph);
int hasEdge(Graph* graph, int src, int dest);
int getDegree(Graph* graph, int vertex);
int getNumEdges(Graph* graph);
int pathDistance(Graph* graph, int* path, int pathLength);
int isConnected(Graph* graph);
void dfs(Graph* graph, int vertex, int visited[]);

// Function to create a new node
Node* createNode(int vertex, int weight) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Initialize the node's data
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with the given number of vertices
Graph* createGraph(int numVertices) {
    // Allocate memory for the graph structure
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    // Set the number of vertices
    graph->numVertices = numVertices;
    // Allocate memory for the array of adjacency lists
    graph->adjList = malloc(numVertices * sizeof(Node*));
    // Initialize each adjacency list to NULL
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to free the memory allocated for the graph
void freeGraph(Graph* graph) {
    // Free memory for each adjacency list
    for (int i = 0; i < graph->numVertices; i++) {
        Node* curr = graph->adjList[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    // Free memory for the array of adjacency lists
    free(graph->adjList);
    // Free memory for the graph structure
    free(graph);
}

// Function to add an edge between two vertices with a weight
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Create a new node for the destination vertex with the given weight
    Node* newNode = createNode(dest, weight);
    // Add the new node to the beginning of the adjacency list of the source vertex
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* curr = graph->adjList[i];
        if(curr == NULL) continue;
        printf("Adjacency list of vertex %d\n", i);
        while (curr != NULL) {
            printf("(%d, %d) -> ", curr->vertex, curr->weight);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

// Function to check if an edge exists between two vertices
int hasEdge(Graph* graph, int src, int dest) {
    Node* curr = graph->adjList[src];
    while (curr != NULL) {
        if (curr->vertex == dest) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

// Function to find the degree of a vertex
int getDegree(Graph* graph, int vertex) {
    int degree = 0;
    Node* curr = graph->adjList[vertex];
    while (curr != NULL) {
        degree++;
        curr = curr->next;
    }
    return degree;
}

// Function to find the number of edges in the graph
int getNumEdges(Graph* graph) {
    int numEdges = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        Node* curr = graph->adjList[i];
        while (curr != NULL) {
            numEdges++;
            curr = curr->next;
        }
    }
    // Since each edge is counted twice (once for each direction), divide by 2
    return numEdges / 2;
}


// Function to check if the graph is connected
int isConnected(Graph* graph) {
    // Perform a depth-first search (DFS) from the first vertex
    // Mark all vertices reachable from the first vertex
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    dfs(graph, 0, visited);

    // Check if all vertices are visited
    for (int i = 0; i < graph->numVertices; i++) {
        if (visited[i] == 0) {
            return 0; // Graph is not connected
        }
    }
    return 1; // Graph is connected
}

// Depth-First Search (DFS) traversal
void dfs(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    Node* curr = graph->adjList[vertex];
    while (curr != NULL) {
        if (visited[curr->vertex] == 0) {
            dfs(graph, curr->vertex, visited);
        }
        curr = curr->next;
    }
}

// Main function
int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(10);

    // Add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 4, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 3, 4, 1);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    // Check if the graph is connected
    if (isConnected(graph)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }
    // Find the distance of a path in the graph
    int path[] = {0, 1, 4, 3};
    int pathLength = sizeof(path) / sizeof(path[0]);
    int distance = pathDistance(graph, path, pathLength);
    if (distance != -1) {
        printf("The distance of the path is: %d\n", distance);
    }
    // Free the memory allocated for the graph
    freeGraph(graph);

    return 0;
}
