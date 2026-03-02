#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 4

typedef struct {
    int x;
    int y;
} Node;

int grid[ROW][COL] = {
    {0, 0, 0, 1},
    {0, 1, 0, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0}
};

int visited[ROW][COL];
Node parent[ROW][COL];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

Node queue[ROW * COL];
int front = 0, rear = 0;

int isValid(int x, int y) {
    return (x >= 0 && x < ROW &&
            y >= 0 && y < COL &&
            grid[x][y] == 0 &&
            !visited[x][y]);
}

void printPath(int x, int y) {
    if (parent[x][y].x == -1) {
        printf("(%d,%d) ", x, y);
        return;
    }

    printPath(parent[x][y].x, parent[x][y].y);
    printf("(%d,%d) ", x, y);
}

void BFS_shortest(int sx, int sy, int gx, int gy) {

    front = rear = 0;

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++) {
            visited[i][j] = 0;
            parent[i][j].x = -1;
            parent[i][j].y = -1;
        }

    queue[rear++] = (Node){sx, sy};
    visited[sx][sy] = 1;

    while (front < rear) {
        Node curr = queue[front++];

        if (curr.x == gx && curr.y == gy) {
            printf("Shortest Path:\n");
            printPath(gx, gy);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isValid(nx, ny)) {
                visited[nx][ny] = 1;
                parent[nx][ny] = curr;
                queue[rear++] = (Node){nx, ny};
            }
        }
    }

    printf("No Path Found\n");
}