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

int dx[4] = {-1, 1, 0, 0};  // up, down, left, right
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

void BFS(int sx, int sy) {
    queue[rear++] = (Node){sx, sy};
    visited[sx][sy] = 1;

    printf("BFS Traversal:\n");

    while (front < rear) {
        Node curr = queue[front++];
        printf("(%d,%d) ", curr.x, curr.y);

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isValid(nx, ny)) {
                visited[nx][ny] = 1;
                queue[rear++] = (Node){nx, ny};
            }
        }
    }
}