#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
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

// string chessboard[8][8] = {
//     {"__", "__", "__", "__", "__", "__", "__", "__"},
//     {"__", "__", "__", "__", "__", "__", "__", "__"},
//     {"__", "__", "__", "__", "__", "K", "__", "__"},
//     {"__", "__", "__", "__", "__", "__", "__", "__"},
//     {"__", "__", "__", "__", "__", "__", "__", "__"},
//     {"__", "__", "__", "__", "__", "__", "__", "__"},
//     {"__", "__", "__", "__", "__", "__", "__", "__"},
//     {"__", "__", "__", "__", "k", "__", "__", "__"}};

// string chessboard[8][8] = {
// {"R", "H", "B", "Q", "K", "B", "H", "R"},
// {"__", "__", "__", "__", "__", "__", "__", "__"},
// {"__", "__", "__", "__", "__", "__", "__", "__"},
// {"__", "__", "__", "__", "__", "__", "__", "__"},
// {"__", "__", "__", "__", "__", "__", "__", "__"},
// {"__", "__", "__", "__", "__", "__", "__", "__"},
// {"__", "__", "__", "__", "__", "__", "__", "__"},
// {"r", "h", "b", "q", "k", "b", "h", "r"}};

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

  virtual bool validMove()
  {
    return 1;
  }
};

class Pawn : public Board
{
public:
  bool forPawn(int r, int c, int r_m, int c_m, bool e = 0)
  {
    if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
    {
      // ye user2 ke leye chlai ga
      if (e)
      {
        if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z")) // jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai
        {
          // agr enemy ya empty space hai tu , humari move valid hugi
          chessboard[r_m][c_m] = "P";
          chessboard[r][c] = "__";
        }
        else if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z"))
        {
          // agr enemy ya empty space hai tu , humari move valid hugi
          chessboard[r_m][c_m] = "P";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else if (chessboard[r_m][c_m] == "__")
      {
        chessboard[r_m][c_m] = "P";
        chessboard[r][c] = "__";
      }
      else // jb jis jga pr move krna hai agr waha apna he piece prha hua tu ye line of code chlai ga, aur invalid move ka kahai ga userku
        return 0;
    }
    else
    {
      // ye user1 ke leye hai
      if (e)
      {
        if ((chessboard[r - 1][c - 1] > "A" && chessboard[r - 1][c - 1] < "Z")) // jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai
        {
          // agr enemy ya empty space hai tu , humari move valid hugi
          chessboard[r_m][c_m] = "p";
          chessboard[r][c] = "__";
        }
        else if ((chessboard[r - 1][c + 1] > "A" && chessboard[r - 1][c + 1] < "Z"))
        {
          // agr enemy ya empty space hai tu , humari move valid hugi
          chessboard[r_m][c_m] = "p";
          chessboard[r][c] = "__";
        }
        else
          return 0;
      }
      else if (chessboard[r_m][c_m] == "__")
      {
        chessboard[r_m][c_m] = "p";
        chessboard[r][c] = "__";
      }
      else
        return 0;
    }
    return 1;
  }

  virtual bool validMove(int r, int c, int r_m, int c_m)
  {
    if (count % 2 == 0) // for user2
    {
      if (r + 1 == r_m && c == c_m)
      { // usuall move
        return forPawn(r, c, r_m, c_m);
      }
      else if (r + 2 == r_m && c == c_m)
      { // Only when it is moving first time
        if (r == 1)
        { // for user2 first pawn movement
          return forPawn(r, c, r_m, c_m);
        }
        else
          return 0;
      }
      else if (r + 1 == r_m && c - 1 == c_m)
      { // when enemey is on the left side
        bool e = 1;
        return forPawn(r, c, r_m, c_m, e);
      }
      else if (r + 1 == r_m && c + 1 == c_m) // when enemey is on the right side
      {
        bool e = 1;
        return forPawn(r, c, r_m, c_m, e);
      }
    }
    else if (!(count % 2 == 0))
    { // for user1
      if (r - 1 == r_m && c == c_m)
      { // usuall move
        return forPawn(r, c, r_m, c_m);
      }
      else if (r - 2 == r_m && c == c_m)
      { // Only when it is moving first time
        if (r == 6)
        { // for user1 first pawn movement
          return forPawn(r, c, r_m, c_m);
        }
        else
          return 0;
      }
      else if (r - 1 == r_m && c - 1 == c_m)
      { // when enemey is on the left side
        bool e = 1;
        return forPawn(r, c, r_m, c_m, e);
      }
      else if (r - 1 == r_m && c + 1 == c_m) // when enemey is on the right side
      {
        bool e = 1;
        return forPawn(r, c, r_m, c_m, e);
      }
    }
    else
    {
      return 0;
    }
  }
};
class King : public Board
{
public:
  bool forKing(int r, int c, int r_m, int c_m)
  {
    if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
    {
      // ye user2 ke leye chlai ga
      if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__") // jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai
      {
        // agr enemy ya empty space hai tu , humari move valid hugi
        chessboard[r_m][c_m] = "K";
        chessboard[r][c] = "__";
      }
      else // jb jis jga pr move krna hai agr waha apna he piece prha hua tu ye line of code chlai ga, aur invalid move ka kahai ga userku
        return 0;
    }
    else
    {
      // ye user1 ke leye hai
      if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
      {
        // same wohi user2 wali logic hai isme
        chessboard[r_m][c_m] = "k";
        chessboard[r][c] = "__";
      }
      else
        return 0;
    }
    return 1;
  }

  virtual bool validMove(int r, int c, int r_m, int c_m)
  {
    if (r - 1 == r_m && c == c_m) // for up
    {

      return forKing(r, c, r_m, c_m);
    }
    else if (r + 1 == r_m && c == c_m) // for down
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r == r_m && c - 1 == c_m) // left
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r == r_m && c + 1 == c_m) // right
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r - 1 == r_m && c + 1 == c_m) // top diagonal right
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r - 1 == r_m && c - 1 == c_m) // top diagonal left
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r + 1 == r_m && c - 1 == c_m) // bottom diagonal left
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r + 1 == r_m && c + 1 == c_m) // bottom diagonal right
    {
      return forKing(r, c, r_m, c_m);
    }
    else
    {
      return 0;
    }
  }

  bool forKing(int r, int c, int r_m, int c_m, bool checkmateCall)
  {
    if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
    {
      // ye user2 ke leye chlai ga
      if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__") // jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai
      {
        // agr enemy ya empty space hai tu , humari move valid hugi
        return 1;
      }
      else // jb jis jga pr move krna hai agr waha apna he piece prha hua tu ye line of code chlai ga, aur invalid move ka kahai ga userku
        return 0;
    }
    else
    {
      // ye user1 ke leye hai
      if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
      {
        // same wohi user2 wali logic hai isme
        return 1;
      }
      else
        return 0;
    }
  }
  virtual bool validMove(int r, int c, int r_m, int c_m, bool checkmateCall)
  {
    if (r - 1 == r_m && c == c_m) // for up
    {

      return forKing(r, c, r_m, c_m);
    }
    else if (r + 1 == r_m && c == c_m) // for down
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r == r_m && c - 1 == c_m) // left
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r == r_m && c + 1 == c_m) // right
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r - 1 == r_m && c + 1 == c_m) // top diagonal right
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r - 1 == r_m && c - 1 == c_m) // top diagonal left
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r + 1 == r_m && c - 1 == c_m) // bottom diagonal left
    {
      return forKing(r, c, r_m, c_m);
    }
    else if (r + 1 == r_m && c + 1 == c_m) // bottom diagonal right
    {
      return forKing(r, c, r_m, c_m);
    }
    else
    {
      return 0;
    }
  }
};
class Queen : public Board
{
public:
  bool forQueen(int r, int c, int r_m, int c_m)
  {
    if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
    {
      // ye user2 ke leye chlai ga
      if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__") // jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai
      {
        // agr enemy ya empty space hai tu , humari move valid hugi
        chessboard[r_m][c_m] = "Q";
        chessboard[r][c] = "__";
      }
      else // jb jis jga pr move krna hai agr waha apna he piece prha hua tu ye line of code chlai ga, aur invalid move ka kahai ga userku
        return 0;
    }
    else
    {
      // ye user1 ke leye hai
      if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
      {
        // same wohi user2 wali logic hai isme
        chessboard[r_m][c_m] = "q";
        chessboard[r][c] = "__";
      }
      else
        return 0;
    }
    return 1;
  }
  virtual bool validMove(int r, int c, int r_m, int c_m)
  {
    if (r - r_m == c - c_m)
    {

      return forQueen(r, c, r_m, c_m);
    }
    else if (r - r_m == c_m - c)
    {
      return forQueen(r, c, r_m, c_m);
    }
    else if (r_m - r == c - c_m)
    {

      return forQueen(r, c, r_m, c_m);
    }
    else if (r_m - r == c_m - c)

    {
      return forQueen(r, c, r_m, c_m);
    }
    else if (r == r_m || c == c_m) // this conditon is valid for all the movements of rook.
    {

      return forQueen(r, c, r_m, c_m);
    }
    else
      return 0;
  }
};
class Rook : protected Board
{
public:
  bool forRook(int r, int c, int r_m, int c_m)
  {
    if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
    {
      // ye user2 ke leye chlai ga
      if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__") // jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai
      {
        // agr enemy ya empty space hai tu , humari move valid hugi
        chessboard[r_m][c_m] = "R";
        chessboard[r][c] = "__";
      }
      else // jb jis jga pr move krna hai agr waha apna he piece prha hua tu ye line of code chlai ga, aur invalid move ka kahai ga userku
        return 0;
    }
    else
    {
      // ye user1 ke leye hai
      if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
      {
        // same wohi user2 wali logic hai isme
        chessboard[r_m][c_m] = "r";
        chessboard[r][c] = "__";
      }
      else
        return 0;
    }
    return 1;
  }
  virtual bool validMove(int r, int c, int r_m, int c_m)
  {
    if (r == r_m || c == c_m) // this conditon is valid for all the movements of rook.
    {
      return forRook(r, c, r_m, c_m);
    }
    else
    {
      cout << "Invalid move. Rook can only move along rows or columns." << endl;
      return 0;
    }
  }
};
class Knight : protected Board
{

public:
  bool forKnight(int r, int c, int r_m, int c_m)
  {
    if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
    {
      // ye user2 ke leye chlai ga
      if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__") // jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai
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
      // ye user1 ke leye hai
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
  }
  virtual bool validMove(int r, int c, int r_m, int c_m)
  {
    if (r - 1 == r_m && c + 2 == c_m)
    {

      return forKnight(r, c, r_m, c_m);
    } // baki else if be same hai , bs main condition mai difference hai
    else if (r + 1 == r_m && c + 2 == c_m)
    {

      return forKnight(r, c, r_m, c_m);
    }
    else if (r - 2 == r_m && c + 1 == c_m)
    {

      return forKnight(r, c, r_m, c_m);
    }
    else if (r - 2 == r_m && c - 1 == c_m)
    {

      return forKnight(r, c, r_m, c_m);
    }
    else if (r - 1 == r_m && c - 2 == c_m)
    {

      return forKnight(r, c, r_m, c_m);
    }
    else if (r + 1 == r_m && c - 2 == c_m)
    {

      return forKnight(r, c, r_m, c_m);
    }
    else if (r + 2 == r_m && c - 1 == c_m)
    {

      return forKnight(r, c, r_m, c_m);
    }
    else if (r + 2 == r_m && c + 1 == c_m)
    {

      return forKnight(r, c, r_m, c_m);
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
  bool forBishop(int r, int c, int r_m, int c_m)
  {
    if (count % 2 == 0) // condition to check who is playing if its true; meaning user2 is playing and if it is false ; meaning user1 is playing
    {
      // ye user2 ke leye chlai ga
      if ((chessboard[r_m][c_m] > "a" && chessboard[r_m][c_m] < "z") || chessboard[r_m][c_m] == "__") // jis jga pr move krna hai uske leye check hu rha hai kai udr kya prha hai enemy hai ya empty space hai
      {
        // agr enemy ya empty space hai tu , humari move valid hugi
        chessboard[r_m][c_m] = "B";
        chessboard[r][c] = "__";
      }
      else // jb jis jga pr move krna hai agr waha apna he piece prha hua tu ye line of code chlai ga, aur invalid move ka kahai ga userku
        return 0;
    }
    else
    {
      // ye user1 ke leye hai
      if ((chessboard[r_m][c_m] > "A" && chessboard[r_m][c_m] < "Z") || chessboard[r_m][c_m] == "__")
      {
        // same wohi user2 wali logic hai isme
        chessboard[r_m][c_m] = "b";
        chessboard[r][c] = "__";
      }
      else
        return 0;
    }
    return 1;
  }
  virtual bool validMove(int r, int c, int r_m, int c_m)
  {
    if (r - r_m == c - c_m)
    {
      return forBishop(r, c, r_m, c_m);
    }
    else if (r - r_m == c_m - c)
    {
      return forBishop(r, c, r_m, c_m);
    }
    else if (r_m - r == c - c_m)
    {
      return forBishop(r, c, r_m, c_m);
    }
    else if (r_m - r == c_m - c)
    {
      return forBishop(r, c, r_m, c_m);
    }
    else
      return 0;
  }
};
class Player : public Board
{
private:
  string userName;
  int row, col, row_m, col_m, score;
  Knight h;
  Bishop b;
  Rook r;
  Queen q;
  Pawn p;
  King k;

public:
  Player()
  {
    userName = "N/A";
    row = 0;
    col = 0;

    row_m = 0;
    col_m = 0;

    score = 0;
  }
  Player(string name)
  {
    userName = name;
    score = 0;
  }

  void set_score(int score)
  {
    this->score = score;
  }

  int get_score()
  {
    return score;
  }

  void set_entireData()
  {
    cout << "\nEnter Your User Name:";
    getline(cin, userName);
  }

  void selection_piece()
  {

    bool flag;
    do
    {
     do{
        cout << "\nTo move your Desired Piece , Enter the Piece location according to the label:";
        cout << "\nEnter row number:";
        if(!(cin >> row)){ // Check if input is a number
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the input buffer
            cin.ignore(10000, '\n'); // Ignore any remaining characters in the buffer
        }
        cout << "\nEnter column number:";
        if(!(cin >> col)){ // Check if input is a number
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the input buffer
            cin.ignore(10000, '\n'); // Ignore any remaining characters in the buffer
        }
    } while((row < 1 || row > 8) || (col < 1 || col > 8));
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
do{
        cout << "\nEnter the location to where you want to move the piece:";
        cout << "\nEnter row number:";
        if(!(cin >> row_m)){ // Check if input is a number
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the input buffer
            cin.ignore(10000, '\n'); // Ignore any remaining characters in the buffer
        }
        cout << "\nEnter column number:";
        if(!(cin >> col_m)){ // Check if input is a number
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the input buffer
            cin.ignore(10000, '\n'); // Ignore any remaining characters in the buffer
        }
    } while((row_m < 1 || row_m > 8) || (col_m < 1 || col_m > 8));
    

    row_m = row_m - 1; // 5
    col_m = col_m - 1; // 7
  }

  bool check_piece()
  {
    if (chessboard[row][col] == "H" || chessboard[row][col] == "h")
    {
      if (h.validMove(row, col, row_m, col_m))
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
      if (r.validMove(row, col, row_m, col_m))
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else if (chessboard[row][col] == "Q" || chessboard[row][col] == "q")
    {
      if (q.validMove(row, col, row_m, col_m))
        return 1;
      else
        return 0;
    }
    else if (chessboard[row][col] == "B" || chessboard[row][col] == "b")
    {
      if (b.validMove(row, col, row_m, col_m))
        return 1;
      else
        return 0;
    }
    else if (chessboard[row][col] == "P" || chessboard[row][col] == "p")
    {
      if (p.validMove(row, col, row_m, col_m))
        return 1;
      else
        return 0;
    }
    else if (chessboard[row][col] == "K" || chessboard[row][col] == "k")
    {
      if (k.validMove(row, col, row_m, col_m))
        return 1;
      else
        return 0;
    }
    else
    {
      cout << "\nInvalid index." << endl;
    }
  }

  bool draw()
  {

    int UpperCaseKingCount = 0;
    int LowerCaseKingCount = 0;

    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        if (chessboard[i][j] == "K")
        {
          UpperCaseKingCount++;
        }
        else if (chessboard[i][j] == "k")
        {
          LowerCaseKingCount++;
        }
        else if (chessboard[i][j] != "__")
        {
          // If there's any piece other than empty or the two kings, it's not a draw
          return false;
        }
      }
    }

    if (UpperCaseKingCount == 1 && LowerCaseKingCount == 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool Checkmate()
  {
    if (count % 2 == 0)
    {

      for (int i = 0; i < 8; i++)
      {
        for (int j = 0; j < 8; j++)
        {

          if (chessboard[i][j] == "K")
          {
            if (k.validMove(i, j, i - 1, j, 1) && k.validMove(i, j, i + 1, j, 1) && k.validMove(i, j, i, j - 1, 1) && k.validMove(i, j, i, j + 1, 1) && k.validMove(i, j, i - 1, j + 1, 1) && k.validMove(i, j, i - 1, j - 1, 1) && k.validMove(i, j, i + 1, j - 1, 1) && k.validMove(i, j, i + 1, j + 1, 1))
            {
              return true;
            }
            else
              return false;
          }
        }
      }
    }
    else
    {
      for (int i = 0; i < 8; i++)
      {
        for (int j = 0; j < 8; j++)
        {

          if (chessboard[i][j] == "k")
          {
            if (k.validMove(i, j, i - 1, j, 1) && k.validMove(i, j, i + 1, j, 1) && k.validMove(i, j, i, j - 1, 1) && k.validMove(i, j, i, j + 1, 1) && k.validMove(i, j, i - 1, j + 1, 1) && k.validMove(i, j, i - 1, j - 1, 1) && k.validMove(i, j, i + 1, j - 1, 1) && k.validMove(i, j, i + 1, j + 1, 1))
            {
              return true;
            }
            else
              return false;
          }
        }
      }
    }
  }
  friend ostream &operator<<(ostream &output, const Player &p)
  {
    output << p.userName << " turn.";
  }
};

int main()
{
  ifstream read;
  ofstream write;

  bool checkmate = 0;
  int draw;
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
    draw = user1.draw();
  again:
    user1.selection_piece();
    user1.move_piece();

    if (!(user1.check_piece())) // agr ye chk_piece() 0 return krta hai tu tb ye block of code chlai ga , 0 ka mtlb invalid move hai
    {
      cout << "\nRe-Enter:";
      goto again; // invalid move ke wja se fer se  user1.selection_piece(); line se code dubara chalai ga
    }

    user1.displayBoard();

    // checkmate = user1.Checkmate();
    ++count;                                   // count mai increament kr ke uski value ku even bna dai ga
    if (checkmate == 1 || (user1.draw() == 1)) // checkmate ke condition abhi dalni hai baad mai
    {
      if (checkmate)
      {
        cout << "\nCheckmate," << user1 << "Wins.";
        checkmate = 0; // idr zero isleye keya hai kuinke , jab break hu kai bahir jai ga tu udr ju if lga hai wu na chalai , user2 wla

        int a;
        read.open("usr2.txt"); // Cutting -1 point for user2 for losing game
        read >> a;
        a -= 1;
        user2.set_score(a);
        read.close();

        write.open("usr2.txt");
        write << a; // adding user1 score to the text file
        write.close();

        int s; // adding 1 point for user2 for winning the game
        read.open("usr1.txt");
        read >> s;
        read.close();
        s += 1;
        user1.set_score(s);
        write.open("usr1.txt");
        write << s;
        write.close();
      }
      break;
    }
    cout << "\n"
         << user2 << endl;
  again1:
    user2.selection_piece();
    user2.move_piece();

    if (!(user2.check_piece()))
    { // same upr wali logic he hai ismai bhi
      cout << "\nRe-Enter:";
      goto again1;
    }

    user2.displayBoard();
    // checkmate = user2.Checkmate();
    ++count; // count mai increament kr ke uski value ku odd bna dai ga
  } while (!(checkmate) && !(user2.draw() == 1)); // checkmate ke condition abhi dalni hai baad mai

  if (checkmate)
  {
    cout << "\nCheckmate," << user2 << "Wins.";

    int a;
    read.open("usr1.txt"); // Cutting -1 point for user1 for losing game
    read >> a;
    a -= 1;
    user1.set_score(a);
    read.close();

    write.open("usr1.txt");
    write << a; // adding user1 score to the text file
    write.close();

    int s; // adding 1 point for user2 for winning the game
    read.open("usr2.txt");
    read >> s;
    read.close();
    s += 1;
    user2.set_score(s);
    write.open("usr2.txt");
    write << s;
    write.close();
  }

  if (draw)
  {
    cout << "\nNo One Wins. \n\tGame is Draw.";
  }
  return 0;
}
