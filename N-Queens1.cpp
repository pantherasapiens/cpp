#include <iostream>

using namespace std;

void printBoard(int *queens, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << ((queens[i] == j) ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int *queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int *queens, int row, int N) {
    if (row == N) {
        printBoard(queens, N);
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(queens, row + 1, N);
            queens[row] = -1; // Backtrack
        }
    }
}

void nQueens(int N) {
    int *queens = new int[N];
    for (int i = 0; i < N; ++i) {
        queens[i] = -1;
    }
    solveNQueens(queens, 0, N);
    delete[] queens; // Don't forget to release the allocated memory
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;

    if (N > 0) {
        nQueens(N);
    } else {
        cout << "Invalid size. Please enter a size greater than 0." << endl;
    }

    return 0;
}
