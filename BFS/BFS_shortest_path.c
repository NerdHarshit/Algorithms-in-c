#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adj[MAX][MAX];//adjescency matrix
int visited[MAX];
int parent[MAX];
int queue[MAX];
int goal;

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

void BFS_SP(int start , int goal){
    for(int i = 0;i<V;i++){
        visited[i] = 0;
        parent[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    while (front !=-1)
    {
        int current = dequeue();
        printf("%d\t",current);

        //only extra part on top of normal bfs code
        if(current == goal){
            printf("found the node! at node%d",current);
            return;
        }

        for(int i = 0;i<V;i++)
        {
            if(adj[current][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
                
            }
        }
    }

    printf("goal not found");
    
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

    BFS_SP(0,3);
    printf("\n");
    

    //DFS(0);
    //printf("\n");

    return 0;
}