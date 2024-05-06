#include <iostream>

using namespace std;

bool isValidPawnMove(char board[][8], int fromRow, int fromCol, int toRow, int toCol) {
    // Check if the pawn is moving in the correct direction (up for white)
    if (fromRow - toRow <= 0) {
        return false;
    }

    // Check for single or double square move from starting position
    if (fromRow == 6) {
        if (toRow - fromRow != 1 && toRow - fromRow != 2) {
            return false;
        }
    } else {
        if (toRow - fromRow != 1) {
            return false;
        }
    }

    // Check for capturing diagonally (only if there's an enemy piece)
    if (toCol != fromCol && board[toRow][toCol] != ' ') {
        if (board[toRow][toCol] >= 'a' && board[toRow][toCol] <= 'z') { // Black piece
            return true;
        } else {
            return false; // Invalid capture
        }
    }

    // Check for moving onto an empty square
    if (board[toRow][toCol] == ' ') {
        return true;
    } else {
        return false; // Invalid move (occupied square)
    }
}

int main() {
    char board[8][8] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'p', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    int fromRow, fromCol, toRow, toCol;

    cout << "Enter the starting row (0-7): ";
    cin >> fromRow;

    cout << "Enter the starting column (0-7): ";
    cin >> fromCol;

    cout << "Enter the destination row (0-7): ";
    cin >> toRow;

    cout << "Enter the destination column (0-7): ";
    cin >> toCol;

    if (isValidPawnMove(board, fromRow, fromCol, toRow, toCol)) {
        cout << "Valid pawn move." << endl;
    } else {
        cout << "Invalid pawn move." << endl;
    }

    return 0;
}