#include<stdio.h>
#include<stdlib.h>

#define max 100

int adj[max][max];
int visited[max];
int v;

void dfs_recursive(int node){
    visited[node] = 1;
    printf("%d",node);

    for(int i=0;i<v;i++)
    {
        if(adj[node][i] && !visited[i])
        {
            dfs_recursive(i);
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

    dfs_recursive(0);
    printf("\n");
    
    return 0;
}