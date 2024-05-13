#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string chessboard[8][8] = {
    {"R", "H", "B", "Q", "K", "B", "H", "R"},
    {"P", "P", "P", "P", "P", "P", "P", "P"},
    {"__", "__", "__", "__", "__", "__", "__", "__"},
    {"__", "__", "__", "__", "__", "__", "__", "__"},
    {"__", "__", "__", "__", "__", "__", "__", "__"},
    {"__", "__", "__", "__", "__", "__", "__", "__"},
    {"p", "p", "p", "p", "p", "p", "p", "p"},
    {"r", "h", "b", "q", "k", "b", "h", "r"}};

int count = 1; // this will be even for user2 and odd for user1

class Board
{

private:
  int size = 8;
  int label[8] = {1, 2, 3, 4, 5, 6, 7, 8};

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

class Pawn : public Board
{
};
class King : public Board
{
};
class Queen : public Board
{
public:
  void validMoveQueen(int r, int c, int r_m, int c_m)
  {
    if (r == r_m || c == c_m || abs(r_m - r) == abs(c_m - c))
    {
      // Move is along a row, column, or diagonal
      chessboard[r_m][c_m] = "q";
      chessboard[r][c] = "__";
      cout << "Queen moved successfully." << endl;
    }
    else
    {
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
class Knight : protected Board
{

public:
  bool validMoveHorse(int r, int c, int r_m, int c_m)
  {
    if (r - 1 == r_m && c + 2 == c_m)
    {
      if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
      {
        // ye user2 ke leye chlai ga
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__")// jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai 
        {
          // agr enemy ya empty space hai tu , humari move valid hugi
          chessboard[r_m][c_m] = "H";
          chessboard[r][c] = "__";
        }
        else // jb jis jga pr move krna hai agr waha apna he piece prha hua tu ye line of code chlai ga, aur invalid move ka kahai ga userku
          return 0;
      }
      else
      {
        //ye user1 ke leye hai 
        if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
        {
        // same wohi user2 wali logic hai isme 
          chessboard[r_m][c_m] = "h";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      return 1;
    }// baki else if be same hai , bs main condition mai difference hai
    else if (r + 1 == r_m && c + 2 == c_m)
    {
      
      if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
      {
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "H";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else
      {
        if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "h";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      return 1;
    }
    else if (r - 2 == r_m && c + 1 == c_m)
    {
      
      if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
      {
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "H";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else
      {
        if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "h";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      return 1;
    }
    else if (r - 2 == r_m && c - 1 == c_m)
    {
     
      if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
      {
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "H";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else
      {
        if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "h";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      return 1;
    }
    else if (r - 1 == r_m && c - 2 == c_m)
    {
     if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
      {
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "H";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else
      {
        if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "h";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      return 1;
    }
    else if (r + 1 == r_m && c - 2 == c_m)
    {
      
     if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
      {
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "H";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else
      {
        if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "h";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      return 1;
    }
    else if (r + 2 == r_m && c - 1 == c_m)
    {
      
      if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
      {
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "H";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else
      {
        if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "h";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      return 1;
    }
    else if (r + 2 == r_m && c + 1 == c_m)
    {
     
      if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
      {
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "H";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else
      {
        if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
        {
          chessboard[r_m][c_m] = "h";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      return 1;
    }
    else
    {
      cout << "Invalid Move" << endl;
      return 0;
    }
  }
};

class Bishop : public Board
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
};
class Player : public Board
{
private:
  string userName;
  int row, col, row_m, col_m;
  Knight h;
  Bishop b;
  Rook r;
  Queen q;

public:
  Player()
  {
    userName = "N/A";
    row = 0;
    col = 0;

    row_m = 0;
    col_m = 0;
  }
  Player(string name)
  {
    userName = name;
  }
  void set_entireDate()
  {
    cout << "\nEnter Your User Name:";
    getline(cin, userName);
  }

  void selection_piece()
  {

    bool flag;
    do
    {
      cout << "\nTo move your Desired Piece , Enter the Piece location according to the label:";
      cout << "\nEnter row number:";
      cin >> row; // 8
      cout << "\nEnter coloumn number:";
      cin >> col; // 7

      row = row - 1; // 7
      col = col - 1; // 6

      if (count % 2 == 0) // agr user2 huga tu ye code chalai ga
      {
        if (chessboard[row][col] > "A" && chessboard[row][col] < "Z") // capital letter piece recognition ke leye ye condition hai
        {
          flag = 0; // user2 ke capital letter pieces hugai , agr user2 ne ju piece move krna hai agr wu capital hua tu ye block of code chlai ga aur agai jakai loop break hujai ga
        }
        else
        {
          // agr small letter piece huga tu ye block of code chlai ga
          cout << "\nThats not your piece.Yours is in Capital letters";
          cout << "\nRe-Enter";
          flag = 1; // is se input dubara leya jai ga , mtlb loop fer se chlai ga
        }
      }
      else
      {
        if (chessboard[row][col] > "a" && chessboard[row][col] < "z") // small letter piece recognition ke leye
        {
          flag = 0; // ye user1 ke leye hai 
        }
        else
        {
          // agr small letters na huai tu ye line of code chlai ga
          cout << "\nThats not your piece.Yours is in Small letters";
          cout << "\nRe-Enter";
          flag = 1;
        }
      }
    } while (flag);
    
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

  bool chk_peice()
  {
    if (chessboard[row][col] == "H" || chessboard[row][col] == "h")
    {
      if (h.validMoveHorse(row, col, row_m, col_m))
      {
        return 1; 
      }
      else
      {
        return 0; // ye invalid move ke surat mai huga aur 0 return huga , aur goto statement ke help se input dobara leya jai user se 
      }
    }
    else if (chessboard[row][col] == "R" || chessboard[row][col] == "r")
    {
      r.validMoveRook(row, col, row_m, col_m);
    }
    else if (chessboard[row][col] == "Q" || chessboard[row][col] == "q")
    {
      q.validMoveQueen(row, col, row_m, col_m);
    }
    else if (chessboard[row][col] == "B" || chessboard[row][col] == "b")
    {
      b.validMoveBishop(row, col, row_m, col_m);
    }
    else if (chessboard[row][col] == "P" || chessboard[row][col] == "p")
    {
    }
    else if (chessboard[row][col] == "K" || chessboard[row][col] == "k")
    {
    }
    else
    {
      cout << "\nInvalid index." << endl;
    }
  }

  friend ostream &operator<<(ostream &output, const Player &p)
  {
    output << p.userName << " turn.";
  }
};
bool checkmate(const Player &obj)
{

  return 1;
}
int main()
{
  bool checkmate = 1;
  Board obj;
  cout << "\n----------------------------Welcome--------------------------------" << endl;
  obj.displayBoard();
  // small letter pieces is for user1
  // Capital letter pieces is for user2
  Player user1("Hamza"), user2("SibghatUllah");
  // user1 gets the first turn and its pieces are in small letters
  do
  {
    cout << "\n"
         << user1 << endl;
  again:
    user1.selection_piece();
    user1.move_piece();

    if (!(user1.chk_peice())) // agr ye chk_piece() 0 return krta hai tu tb ye block of code chlai ga , 0 ka mtlb invalid move hai
    {
      cout << "\nRe-Enter:";
      goto again; // invalid move ke wja se fer se  user1.selection_piece(); line se code dubara chalai ga
    }

    user1.displayBoard();
    ++count; // count mai increament kr ke uski value ku even bna dai ga 
    if (checkmate == 0) // checkmate ke condition abhi dalni hai baad mai
    {
      break;
    }
    cout << "\n"
         << user2 << endl;
  again1:
    user2.selection_piece();
    user2.move_piece();

    if (!(user2.chk_peice()))
    {// same upr wali logic he hai ismai bhi
      cout << "\nRe-Enter:";
      goto again1;
    }

    user2.displayBoard();
    ++count; // count mai increament kr ke uski value ku odd bna dai ga 
  } while (checkmate);// checkmate ke condition abhi dalni hai baad mai
  return 0;
}
