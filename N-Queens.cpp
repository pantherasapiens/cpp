#include <iostream>

using namespace std;

bool isSafe(int** board, int row, int col, int N) {
    // Check the row on the left side
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int** board, int col, int N) {
    if (col == N) {
        return true; // All queens are placed successfully
    }

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1, N)) {
                return true;
            }

            board[i][col] = 0; // Backtrack if placing the queen at (i, col) doesn't lead to a solution
        }
    }

    return false; // If no queen can be placed in this column, backtrack
}

void solveNQueens(int N) {
    int** board = new int*[N];
    for (int i = 0; i < N; ++i) {
        board[i] = new int[N];
        fill(board[i], board[i] + N, 0);
    }

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist" << endl;
        return;
    }

    // Print the solution
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < N; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

int main() {
    int N;
    cout << "Enter the value of N for N-Queens: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
