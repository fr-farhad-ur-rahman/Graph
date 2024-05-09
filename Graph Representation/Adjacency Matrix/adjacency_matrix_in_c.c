#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100

bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void Graph(int n){
    numVertices = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adjMatrix[i][j] = false;
        }
    }
}

void addEdge(int i, int j){
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
}

void removeEdge(int i, int j){
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
}

void printList(){
    printf("   ");
    for(int i = 0; i < numVertices; i++){
        printf("%d:", i);
    }
    puts("");
    for(int i = 0; i < numVertices; i++){
        printf("%d :", i);
        for(int j = 0; j < numVertices; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        puts("");
    }
}

int main(){
    int n = 4; 
    Graph(n);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    printList();
    return 0;
}
