#include <stdio.h>

#define MAX_SIZE 18

// Funcție pentru a genera matricea conform cerințelor
void generateMatrix(int N, int K, int matrix[MAX_SIZE][MAX_SIZE]) {
    int num = 1;
    int row = K - 1;
    int col = 0;
    int direction = 1;

    // Inițializăm matricea cu 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }

    while (num <= N * N) {
        matrix[row][col] = num;
        num++;

        // Determinăm următoarea poziție în funcție de direcție
        if (direction == 1) {
            if (col + 1 < N && matrix[row][col + 1] == 0) {
                col++;
            } else {
                direction = 2;
                row++;
            }
        } else if (direction == 2) {
            if (row + 1 < N && matrix[row + 1][col] == 0) {
                row++;
            } else {
                direction = 3;
                col--;
            }
        } else if (direction == 3) {
            if (col - 1 >= 0 && matrix[row][col - 1] == 0) {
                col--;
            } else {
                direction = 4;
                row--;
            }
        } else if (direction == 4) {
            if (row - 1 >= 0 && matrix[row - 1][col] == 0) {
                row--;
            } else {
                direction = 1;
                col++;
            }
        }
    }
}

// Funcție pentru a afișa matricea
void printMatrix(int N, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N, K;
    int matrix[MAX_SIZE][MAX_SIZE];

    // Citim N și K
    scanf("%d %d", &N, &K);

    // Generăm matricea
    generateMatrix(N, K, matrix);

    // Afișăm matricea
    printMatrix(N, matrix);

    return 0;
}
