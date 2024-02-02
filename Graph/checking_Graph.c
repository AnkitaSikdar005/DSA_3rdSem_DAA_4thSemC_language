#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;

// Function to input the graph as an adjacency matrix
void inputGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
}

// Function to test if the graph is complete
bool isComplete() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j && adjacencyMatrix[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Function to obtain the degree of a node u (undirected graph)
int getDegree(int u) {
    int degree = 0;
    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[u][i] == 1) {
            degree++;
        }
    }
    return degree;
}

// Function to obtain the indegree of a node u (directed graph)
int getIndegree(int u) {
    int indegree = 0;
    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[i][u] == 1) {
            indegree++;
        }
    }
    return indegree;
}

// Function to obtain the outdegree of a node u (directed graph)
int getOutdegree(int u) {
    int outdegree = 0;
    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[u][i] == 1) {
            outdegree++;
        }
    }
    return outdegree;
}

// Function to check if the graph is directed or undirected
bool isDirected() {
   for (int i = 0; i < numVertices; i++) {
       for (int j = i + 1; j < numVertices; j++) {
           // If there's an edge in one direction but not the other, it's directed
           if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
               return true;
           }
       }
   }
   return false; // If all edges are symmetric, it's undirected
}

int main() {
    inputGraph();
    int a=0;
     // Check for directedness
   if (isDirected()) {
        a=1;
       printf("The graph is directed.\n");
   } else {
       printf("The graph is undirected.\n");
   }

    // Test for completeness
    if (isComplete()) {
        printf("The graph is complete.\n");
    } else {
        printf("The graph is not complete.\n");
    }

    // Get degree, indegree, and outdegree (assuming undirected)
    int node = 3; // Example node
    printf("Degree of node %d: %d\n", node, getDegree(node));
    if(a==1)
    {
    printf("Indegree of node %d: %d\n", node, getIndegree(node));
    printf("Outdegree of node %d: %d\n", node, getOutdegree(node));
}
    return 0;
}