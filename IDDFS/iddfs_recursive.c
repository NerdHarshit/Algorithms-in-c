#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int V;


int DLS(int node, int goal, int limit) {

    if (node == goal)
        return 1;

    if (limit == 0)
        return -1;  // Cutoff

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            int result = DLS(i, goal, limit - 1);

            if (result == 1)
                return 1;
        }
    }

    return 0;  // Failure
}

int IDDFS(int start, int goal, int maxDepth) {

    for (int depth = 0; depth <= maxDepth; depth++) {

        int result = DLS(start, goal, depth);

        if (result == 1) {
            printf("Found at depth %d\n", depth);
            return 1;
        }
    }

    return 0;
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

    printf("%d",IDDFS(0,3,4));
    printf("\n");
    
    return 0;
}