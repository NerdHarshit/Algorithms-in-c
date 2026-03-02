#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int V;

int DLS(int node, int goal, int limit) {

    if (node == goal)
        return 1;  // Success

    if (limit <= 0)
        return -1; // Cutoff

    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            int result = DLS(i, goal, limit - 1);

            if (result == 1)
                return 1;   // Found

            if (result == -1)
                return -1;  // Cutoff
        }
    }

    return 0;  // Failure
}

int main() {
    V = 5;

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    printf("%d",DLS(0,3,2));
    printf("\n");
    
    return 0;
}