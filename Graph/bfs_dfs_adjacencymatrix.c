#include<stdio.h>
#include<stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};

struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct Queue* q) {
    return (q->r == q->f);
}

int isFull(struct Queue* q) {
    return (q->r == q->size - 1);
}

void enqueue(struct Queue* q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct Queue* q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
//void BFS(int startNode, int numNodes, int adjacencyMatrix[][numNodes], int //visited[]) can write in this way also
void BFS(int startNode, int numNodes, int adjacencyMatrix[7][7], int visited[]) {
    struct Queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    printf("Breadth-First Search starting from vertex %d: ", startNode);
    printf("%d ", startNode);
    visited[startNode] = 1;
    enqueue(&q, startNode);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        for (int j = 0; j < numNodes; j++) {
            if (adjacencyMatrix[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    printf("\n");

    free(q.arr);
}

void DFS(int i) {
     printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++) {
        if (A[i][j] == 1 && !visited[j]) {
            DFS(j);
        }
    }
}

int main() {
    int start ,numVertices;
   printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
     // Reset the visited array
    for (int i = 0; i < 7; i++) {
        visited[i] = 0;
    }
    BFS(start, numVertices, A, visited);
    // Reset the visited array again before calling DFS
    for (int i = 0; i < 7; i++) {
        visited[i] = 0;
    }
    printf("Depth-First Search starting from vertex %d: ", start);
    DFS(start);
    return 0;
    
}