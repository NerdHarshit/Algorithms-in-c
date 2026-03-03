#include <stdio.h>

// Objective function
int f(int x) {
    return -x*x + 6*x;
}

void hillClimb(int start) {

    int current = start;

    while (1) {

        int left = current - 1;
        int right = current + 1;

        int current_val = f(current);
        int left_val = f(left);
        int right_val = f(right);

        // Choose best neighbor
        if (left_val > current_val) {
            current = left;
        }
        else if (right_val > current_val) {
            current = right;
        }
        else {
            break;  // no improvement
        }
    }

    printf("Local maximum at x = %d\n", current);
    printf("Maximum value = %d\n", f(current));
}

int main() {

    hillClimb(0);

    return 0;
}