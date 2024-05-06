#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Board
{

private:
  int size = 8;
  int label[8] = {1, 2, 3, 4, 5, 6, 7, 8};

protected:
  string chessboard[8][8] = {
      {"R", "H", "B", "Q", "K", "B", "H", "R"},
      {"P", "P", "P", "P", "P", "P", "P", "P"},
      {"__", "__", "__", "__", "__", "__", "__", "__"},
      {"__", "__", "__", "__", "__", "__", "__", "__"},
      {"__", "__", "__", "__", "__", "__", "__", "__"},
      {"__", "__", "__", "__", "__", "__", "__", "__"},
      {"__", "__", "__", "__", "__", "__", "__", "__"},
      {"r", "h", "b", "q", "k", "b", "h", "r"}};

public:
  void displayBoard()
  {
    cout << " ";
    for (int i = 0; i < size; ++i)
    {
      cout << setw(3) << label[i];
    }
    cout << endl;
    for (int i = 0; i < size; ++i)
    {
      cout << label[i];
      for (int j = 0; j < size; ++j)
      {

        cout << setw(3) << chessboard[i][j];
      }
      cout << endl;
    }
  }

  void condition()
  {
  }
};
class Queen : protected Board {
public:
    void validMoveQueen(int r, int c, int r_m, int c_m) {
        if (r == r_m || c == c_m || abs(r_m - r) == abs(c_m - c)) {
            // Move is along a row, column, or diagonal
            chessboard[r_m][c_m] = "q";
            chessboard[r][c] = "__";
            cout << "Queen moved successfully." << endl;
        } else {
            cout << "Invalid move. Queen can move along rows, columns, or diagonals." << endl;
        }
    }
     void board()
  {
    displayBoard();
  }
};
class Rook : protected Board
{
public:
  void validMoveRook(int r, int c, int r_m, int c_m)
  {
    if (r == r_m || c == c_m)
    {
      // Move is along a row or column
      chessboard[r_m][c_m] = "r";
      chessboard[r][c] = "__";
      cout << "Rook moved successfully." << endl;
    }
    else
    {
      cout << "Invalid move. Rook can only move along rows or columns." << endl;
    }
  }

  void board()
  {
    displayBoard();
  }
};
class knight : protected Board
{

public:
  void validmove(int r, int c, int r_m, int c_m)
  {
    if (r - 1 == r_m && c + 2 == c_m)
    {
      chessboard[r_m][c_m] = "h";
      chessboard[r][c] = "__";
    }
    else if (r + 1 == r_m && c + 2 == c_m)
    {
      chessboard[r_m][c_m] = "h";
      chessboard[r][c] = "__";
    }
    else if (r - 2 == r_m && c + 1 == c_m)
    {
      chessboard[r_m][c_m] = "h";
      chessboard[r][c] = "__";
    }
    else if (r - 2 == r_m && c - 1 == c_m)
    {
      chessboard[r_m][c_m] = "h";
      chessboard[r][c] = "__";
    }
    else if (r - 1 == r_m && c - 2 == c_m)
    {
      chessboard[r_m][c_m] = "h";
      chessboard[r][c] = "__";
    }
    else if (r + 1 == r_m && c - 2 == c_m)
    {
      chessboard[r_m][c_m] = "h";
      chessboard[r][c] = "__";
    }
    else if (r + 2 == r_m && c - 1 == c_m)
    {
      chessboard[r_m][c_m] = "h";
      chessboard[r][c] = "__";
    }
    else if (r + 2 == r_m && c + 1 == c_m)
    {
      chessboard[r_m][c_m] = "h";
      chessboard[r][c] = "__";
    }
    else
      cout << "inavalid!!!move---";
  }
  void board()
  {
    displayBoard();
  }
};

class bishop : protected Board
{
public:
  void validMoveBishop(int r, int c, int r_m, int c_m)
  {
    // Check if the move is diagonal
    if (abs(r_m - r) != abs(c_m - c))
    {
      cout << "Invalid move. Bishop can only move diagonally." << endl;
      return;
    }

    // Determine direction of movement
    int dr = (r_m - r > 0) ? 1 : -1;
    int dc = (c_m - c > 0) ? 1 : -1;
    // agr 1 to downward movement osy trha bqe .....yah row ka lia
    //  Check for obstacles along the diagonal path
    int rr = r + dr;
    int cc = c + dc;
    while (rr != r_m && cc != c_m)
    {
      if (chessboard[rr][cc] != "__")
      {
        // Path is blocked
        cout << "Invalid move. Path is blocked." << endl;
        return;
      }
      rr += dr;
      cc += dc;
    }

    // Move bishop if path is clear
    chessboard[r_m][c_m] = "b";
    chessboard[r][c] = "__";
  }
  void board()
  {
    displayBoard();
  }
};
class Player : protected Board
{
private:
  string userName, level;
  int age, row, col, row_m, col_m;
  knight h;
  bishop b;
  Rook r;
  Queen q;

public:
  Player()
  {
    userName = "N/A";
    level = "N/A";
    age = 0;

    row = 0;
    col = 0;

    row_m = 0;
    col_m = 0;
  }

  void set_entireDate()
  {
    cout << "\nEnter Your User Name:";
    getline(cin, userName);
    cout << "\nEnter Your Age:";
    cin >> age;
    cout << "\nEnter Your Level:";
    cin >> level;
  }

  void selection_piece()
  {

    cout << "\nTo move your Desired Piece , Enter the Piece location according to the label:";
    cout << "\nEnter row number:";
    cin >> row; // 8
    cout << "\nEnter coloumn number:";
    cin >> col; // 7

    row = row - 1; // 7
    col = col - 1; // 6
  }

  void move_piece()
  {

    cout << "\nEnter the location to where you want to move the piece:";
    cout << "\nEnter row number:";
    cin >> row_m; // 6
    cout << "\nEnter coloumn number:";
    cin >> col_m; // 8

    row_m = row_m - 1; // 5
    col_m = col_m - 1; // 7
  }

  void chk_peice()
  {
    if (chessboard[row][col] == "H" || chessboard[row][col] == "h")
    {
      h.validmove(row, col, row_m, col_m);
      h.board();
    }
    else if (chessboard[row][col] == "R"|| chessboard[row][col] == "r")
    {
      r.validMoveRook(row, col, row_m, col_m);
      r.board();
    }
    else if (chessboard[row][col] == "Q"|| chessboard[row][col] == "q")
    {
      q.validMoveQueen(row, col, row_m, col_m);
      q.board();
    }
    else if (chessboard[row][col] == "B" || chessboard[row][col] == "b")
    {
      b.validMoveBishop(row, col, row_m, col_m);
      b.board();
    }
    else if (chessboard[row][col] == "P"|| chessboard[row][col] == "p")
    {
    }
    else if (chessboard[row][col] == "K"|| chessboard[row][col] == "k")
    {
    }
    else
    {
      cout << "\nInvalid index.";
    }
  }
  void updated_Board()
  {
    displayBoard();
  }
};

// class Pawn {
// private:
//     int currentRow;
//     int currentCol;
//     bool isWhite;

// public:
//     Pawn(int row, int col, bool white) : currentRow(row), currentCol(col), isWhite(white) {}

//     bool isValidMove(int newRow, int newCol) const {
//         // Check if the pawn is moving in the correct direction
//         int direction = isWhite ? 1 : -1;
//         if (newRow != currentRow + direction) {
//            cout << "Invalid move: Pawns can only move one square forward.\n";
//             return false;
//         }

//         // Check if the pawn is moving straight
//         if (newCol == currentCol) {
//             return true;
//         }

//         // Check if the pawn is capturing diagonally
//         if (newCol == currentCol + 1 || newCol == currentCol - 1) {
//             return true;
//         }

//         cout << "Invalid move: Pawns can only move forward or capture diagonally.\n";
//         return false;
//     }
// };

int main()
{
  Board obj;
  cout << "\nWelcome" << endl;
  obj.displayBoard();

  Player user1;
  user1.selection_piece();
  user1.move_piece();
  user1.chk_peice();

  return 0;
}