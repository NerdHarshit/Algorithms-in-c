#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 4

int state[N];

int calculateCost() {
    int cost = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (state[i] == state[j])
                cost++;
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

void simulatedAnnealing() {

    double T = 100.0;      // initial temperature
    double coolingRate = 0.95;

    int currentCost = calculateCost();

    while (T > 0.1 && currentCost > 0) {

        int col = rand() % N;
        int oldRow = state[col];
        int newRow = rand() % N;

        state[col] = newRow;
        int newCost = calculateCost();

        int deltaE = newCost - currentCost;

        if (deltaE < 0) {
            currentCost = newCost;
        } else {
            double probability = exp(-deltaE / T);
            double randomValue = (double)rand() / RAND_MAX;

            if (randomValue < probability) {
                currentCost = newCost;
            } else {
                state[col] = oldRow; // revert
            }
        }

        T *= coolingRate;  // cool down
    }

    printf("Final Cost: %d\n\n", currentCost);
    printBoard();
}

int main() {

    srand(time(0));

    for (int i = 0; i < N; i++)
        state[i] = rand() % N;

    printf("Initial Board:\n");
    printBoard();

    printf("\nRunning Simulated Annealing...\n\n");

    simulatedAnnealing();

    return 0;
}