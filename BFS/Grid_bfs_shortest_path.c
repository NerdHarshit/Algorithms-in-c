#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 4

int grid[ROW][COL] = {
    {0, 0, 0, 1},
    {0, 1, 0, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0}
};

int visited[ROW][COL];
int parentX[ROW][COL];
int parentY[ROW][COL];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct {
    int x, y;
} Node;

Node queue[ROW * COL];
int front = 0, rear = 0;

int isValid(int x, int y) {
    return (x >= 0 && x < ROW &&
            y >= 0 && y < COL &&
            grid[x][y] == 0 &&
            !visited[x][y]);
}

void printPath(int gx, int gy) {
    if (parentX[gx][gy] == -1) {
        printf("(%d,%d) ", gx, gy);
        return;
    }
    printPath(parentX[gx][gy], parentY[gx][gy]);
    printf("(%d,%d) ", gx, gy);
}

void BFS_shortest(int sx, int sy, int gx, int gy) {

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++) {
            visited[i][j] = 0;
            parentX[i][j] = -1;
            parentY[i][j] = -1;
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
                parentX[nx][ny] = curr.x;
                parentY[nx][ny] = curr.y;
                queue[rear++] = (Node){nx, ny};
            }
        }
    }

    printf("No Path Found\n");
}