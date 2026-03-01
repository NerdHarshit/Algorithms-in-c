#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adj[MAX][MAX];//adjescency matrix
int visited[MAX];
int queue[MAX];

int front = -1;
int back = -1;
int V;//no of vertices in graph

void enqueue(int node){
    if(back == MAX-1)
    {
        return;
    }

    if(front ==-1){
        front =0;
    }

    queue[++back] = node;
}

int dequeue(){
    if(front == -1){
        return -1;
    }

    int node = queue[front];
    if(front == back){
        front = back = -1;
    }

    else{
        front ++;
    }

    return node;
}

void BFS(int start){
    
    for (int i = 0;i<V;i++){
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal");
    while(front !=-1){
        int current = dequeue();
        printf("%d",current);

        for(int i=0;i<V;i++){
            if(adj[current][i] && !visited[i]){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    V = 5;

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Example graph
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    BFS(0);
    printf("\n");

    //DFS(0);
    //printf("\n");

    return 0;
}