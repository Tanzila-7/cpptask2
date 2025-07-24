#include <iostream>
using namespace std;
bool isValid(int board[9][9], int row, int col, int num) {
    
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

   
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }


    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}


bool solveSudoku(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, i, j, num)) {
                        board[i][j] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < 8) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < 8) {
            cout << "---------------------" << endl;
        }
    }
}


void takeInput(int board[9][9]) {
    cout << "Enter the Sudoku board (0 for empty cells):" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << "Enter value for row " << i + 1 << " column " << j + 1 << ": ";
            cin >> board[i][j];
            while (board[i][j] < 0 || board[i][j] > 9) {
                cout << "Invalid input. Please enter a value between 0 and 9: ";
                cin >> board[i][j];
            }
        }
    }
}

int main() {
    int board[9][9];
    takeInput(board);
    cout << "Input Sudoku board:" << endl;
    printBoard(board);
    if (solveSudoku(board)) {
        cout << "Solved Sudoku board:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
