public class adjacency_matrix_in_java{
    private int[][] adjMatrix;
    private int numVertices;

    public adjacency_matrix_in_java(int numVertices){
        this.numVertices = numVertices;
        adjMatrix = new int[numVertices][numVertices];
        for(int i = 0; i < numVertices; i++){
            for(int j = 0; j < numVertices; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }

    public void addEdge(int i, int j){
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }

    public void removeEdge(int i, int j){
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }

    void printList(){
        for(int i = 0; i < numVertices; i++){
            for(int j = 0; j < numVertices; j++){
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args){
        adjacency_matrix_in_java g = new adjacency_matrix_in_java(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(3, 4);

        g.printList();
    }
}
