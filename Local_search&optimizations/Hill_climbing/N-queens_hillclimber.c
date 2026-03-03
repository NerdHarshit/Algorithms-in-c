#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int state[N];

// Count number of attacking pairs
int calculateCost() {
    int cost = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            // Same row
            if (state[i] == state[j])
                cost++;

            // Same diagonal
            if (abs(state[i] - state[j]) == abs(i - j))
                cost++;
        }
    }

    return cost;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (state[j] == i)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void hillClimb() {

    int currentCost = calculateCost();

    while (1) {

        int bestCost = currentCost;
        int bestCol = -1;
        int bestRow = -1;

        // Try all neighbors
        for (int col = 0; col < N; col++) {
            int originalRow = state[col];

            for (int row = 0; row < N; row++) {

                if (row == originalRow)
                    continue;

                state[col] = row;
                int newCost = calculateCost();

                if (newCost < bestCost) {
                    bestCost = newCost;
                    bestCol = col;
                    bestRow = row;
                }
            }

            state[col] = originalRow;  // restore
        }

        if (bestCost >= currentCost)
            break;

        state[bestCol] = bestRow;
        currentCost = bestCost;
    }

    printf("Final Cost: %d\n\n", currentCost);
    printBoard();
}

int main() {

    srand(time(0));

    // Random initial state
    for (int i = 0; i < N; i++)
        state[i] = rand() % N;

    printf("Initial Board:\n");
    printBoard();

    printf("\nRunning Hill Climbing...\n\n");

    hillClimb();

    return 0;
}