#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6

int adj[V][V] = {
    //0 1 2 3 4 5
    { 0,2,4,1,0,0 }, // 0
    { 2,0,0,0,7,0 }, // 1
    { 4,0,0,3,0,0 }, // 2
    { 1,0,3,0,2,0 }, // 3
    { 0,7,0,2,0,1 }, // 4
    { 0,0,0,0,1,0 }  // 5
};

int h[V] = {7,6,2,1,1,0}; // heuristic values toward goal (node 5)

int g[V];
int parent[V];
int visited[V];

typedef struct {
    int node;
    int f;
} PQNode;

PQNode pq[100];
int pqSize = 0;

void swap(PQNode *a, PQNode *b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, int f) {
    pq[pqSize].node = node;
    pq[pqSize].f = f;
    int i = pqSize;
    pqSize++;

    while (i > 0) {
        int parentIndex = (i - 1) / 2;
        if (pq[parentIndex].f > pq[i].f) {
            swap(&pq[parentIndex], &pq[i]);
            i = parentIndex;
        } else break;
    }
}

int pop() {
    int node = pq[0].node;
    pq[0] = pq[pqSize - 1];
    pqSize--;

    int i = 0;

    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < pqSize && pq[left].f < pq[smallest].f)
            smallest = left;
        if (right < pqSize && pq[right].f < pq[smallest].f)
            smallest = right;

        if (smallest != i) {
            swap(&pq[i], &pq[smallest]);
            i = smallest;
        } else break;
    }

    return node;
}

void printPath(int goal) {
    if (parent[goal] == -1) {
        printf("%d ", goal);
        return;
    }
    printPath(parent[goal]);
    printf("%d ", goal);
}

void Astar(int start, int goal) {

    for (int i = 0; i < V; i++) {
        g[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    pqSize = 0;

    g[start] = 0;
    push(start, h[start]);

    while (pqSize > 0) {

        int current = pop();

        if (visited[current])
            continue;

        visited[current] = 1;

        printf("Expanding: %d\n", current);

        if (current == goal) {
            printf("\nGoal Found!\nPath: ");
            printPath(goal);
            printf("\nTotal Cost: %d\n", g[goal]);
            return;
        }

        for (int i = 0; i < V; i++) {

            if (adj[current][i] > 0) {

                int tentative_g = g[current] + adj[current][i];

                if (tentative_g < g[i]) {
                    g[i] = tentative_g;
                    parent[i] = current;

                    int f = g[i] + h[i];
                    push(i, f);
                }
            }
        }
    }

    printf("Goal Not Reachable\n");
}

int main() {

    int start = 0;
    int goal = 5;

    printf("Running A* from %d to %d\n\n", start, goal);

    Astar(start, goal);

    return 0;
}