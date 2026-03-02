#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int v;

void push(int node) {
    stack[++top] = node;
}

int pop() {
    return stack[top--];
}

void DFS_iterative(int start) {
    for (int i = 0; i < v; i++)
        visited[i] = 0;

    push(start);

    while (top != -1) {
        int current = pop();

        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            for (int i = v - 1; i >= 0; i--) {
                if (adj[current][i] && !visited[i]) {
                    push(i);
                }
            }
        }
    }
}


int main() {
    v = 5;

    // Initialize adjacency matrix
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            adj[i][j] = 0;

    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    DFS_iterative(0);
    printf("\n");
    
    return 0;
}