#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6

// Adjacency matrix
int adj[V][V];

// Heuristic values
int h[V];

// Parent array for path reconstruction
int parent[V];

// Visited array
int visited[V];


// ----------------------
// Min Heap (Priority Queue)
// ----------------------

typedef struct {
    int node;
    int priority;
} PQNode;

PQNode pq[100];
int pqSize = 0;

void swap(PQNode *a, PQNode *b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, int priority) {
    pq[pqSize].node = node;
    pq[pqSize].priority = priority;
    int i = pqSize;
    pqSize++;

    // Heapify up
    while (i > 0) {
        int parentIndex = (i - 1) / 2;
        if (pq[parentIndex].priority > pq[i].priority) {
            swap(&pq[parentIndex], &pq[i]);
            i = parentIndex;
        } else {
            break;
        }
    }
}

int pop() {
    if (pqSize == 0)
        return -1;

    int node = pq[0].node;

    pq[0] = pq[pqSize - 1];
    pqSize--;

    int i = 0;

    // Heapify down
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pqSize && pq[left].priority < pq[smallest].priority)
            smallest = left;

        if (right < pqSize && pq[right].priority < pq[smallest].priority)
            smallest = right;

        if (smallest != i) {
            swap(&pq[i], &pq[smallest]);
            i = smallest;
        } else {
            break;
        }
    }

    return node;
}


// ----------------------
// Greedy Best First Search
// ----------------------

void printPath(int goal) {
    if (parent[goal] == -1) {
        printf("%d ", goal);
        return;
    }
    printPath(parent[goal]);
    printf("%d ", goal);
}

void Greedy(int start, int goal) {

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    pqSize = 0;

    push(start, h[start]);

    while (pqSize > 0) {

        int current = pop();

        if (visited[current])
            continue;

        printf("Visiting: %d\n", current);
        visited[current] = 1;

        if (current == goal) {
            printf("\nGoal Found!\nPath: ");
            printPath(goal);
            printf("\n");
            return;
        }

        for (int i = 0; i < V; i++) {
            if (adj[current][i] && !visited[i]) {
                parent[i] = current;
                push(i, h[i]);
            }
        }
    }

    printf("Goal Not Reachable\n");
}


// ----------------------
// Main
// ----------------------

int main() {

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Example graph
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[3][5] = adj[5][3] = 1;

    // Example heuristic values (estimate to goal node 5)
    h[0] = 5;
    h[1] = 3;
    h[2] = 4;
    h[3] = 2;
    h[4] = 6;
    h[5] = 0;

    Greedy(0, 5);

    return 0;
}