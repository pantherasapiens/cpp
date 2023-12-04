#include <stdio.h>

#define MAX_N 10

// Function to check if placing a queen at (row, col) is safe
int isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
    int i, j;

    // Check if there is a queen in the same row
    for (i = 0; i < col; ++i)
        if (board[row][i])
            return 0;

    // Check if there is a queen in the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return 0;

    // Check if there is a queen in the lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j])
            return 0;

    return 1;
}

// Recursive function to solve N-Queens problem using backtracking
int solveNQueensUtil(int board[MAX_N][MAX_N], int col, int N) {
    if (col == N) {
        // All queens are placed successfully
        // Print the solution or perform any other action
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("%c ", (board[i][j] ? 'Q' : '.'));
            }
            printf("\n");
        }
        printf("----------------------\n");
        return 1; // If you want to find only one solution, you can return here.
    }

    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;  // Place queen

            // Recur to place the rest of the queens
            res = solveNQueensUtil(board, col + 1, N) || res;

            // If placing queen in the current position doesn't lead to a solution,
            // then remove the queen from the current position (backtrack)
            board[i][col] = 0;
        }
    }

    return res;
}

// Function to solve the N-Queens problem and print solutions
void solveNQueens(int N) {
    int board[MAX_N][MAX_N] = {0};

    if (!solveNQueensUtil(board, 0, N)) {
        printf("No solution exists.\n");
    }
}

int main() {
    int N;
    printf("Hello World\t~C\nEnter the value of N for N-Queens: ");
    scanf("%d", &N);

    solveNQueens(N);

    return 0;
}
