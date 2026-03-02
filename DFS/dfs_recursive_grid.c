#include <stdio.h>

#define ROW 4
#define COL 4

int grid[ROW][COL] = {
    {0, 0, 0, 1},
    {0, 1, 0, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0}
};

int visited[ROW][COL];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int isValid(int x, int y) {
    return (x >= 0 && x < ROW &&
            y >= 0 && y < COL &&
            grid[x][y] == 0 &&
            !visited[x][y]);
}

void DFS_grid(int x, int y) {
    visited[x][y] = 1;
    printf("(%d,%d) ", x, y);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny)) {
            DFS_grid(nx, ny);
        }
    }
}