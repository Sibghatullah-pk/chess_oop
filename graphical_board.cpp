#include <iostream>
#include <graphics.h>
#include <iostream>

using namespace std;
// Function to draw the base version of the chessboard
void drawBaseChessBoard()
{
    int left = 50, top = 50, right = 100, bottom = 100;
    int row, col;

    for (row = 0; row < 8; ++row)
    {
        for (col = 0; col < 8; ++col)
        {
            if ((row + col) % 2 == 0)
                setfillstyle(SOLID_FILL, WHITE);
            else
                setfillstyle(SOLID_FILL, BROWN);

            bar(left + col * 50, top + row * 50, right + col * 50, bottom + row * 50);
        }
    }
}

// Function to draw the updated version of the chessboard
void drawUpdatedChessBoard()
{
    // Your updated chessboard drawing code here
    // This could include drawing pieces in different positions or adding effects
    // For simplicity, let's just draw a border around the board
    int left = 50, top = 50, right = 100, bottom = 100;
    drawBaseChessBoard();
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);

    // Drawing white pieces
    outtextxy(left + 25, top + 25, "R");  // Rook
    outtextxy(left + 75, top + 25, "N");  // Knight
    outtextxy(left + 125, top + 25, "B"); // Bishop
    outtextxy(left + 175, top + 25, "Q"); // Queen
    outtextxy(left + 225, top + 25, "K"); // King
    outtextxy(left + 275, top + 25, "B"); // Bishop
    outtextxy(left + 325, top + 25, "N"); // Knight
    outtextxy(left + 375, top + 25, "R"); // Rook
    // Drawing white pawns
    for (int i = 0; i < 8; ++i)
    {
        outtextxy(left + i * 50 + 25, top + 75, "P"); // Pawn
    }

    // Drawing black pieces
    outtextxy(left + 25, top + 375, "r");  // Rook
    outtextxy(left + 75, top + 375, "n");  // Knight
    outtextxy(left + 125, top + 375, "b"); // Bishop
    outtextxy(left + 175, top + 375, "q"); // Queen
    outtextxy(left + 225, top + 375, "k"); // King
    outtextxy(left + 275, top + 375, "b"); // Bishop
    outtextxy(left + 325, top + 375, "n"); // Knight
    outtextxy(left + 375, top + 375, "r"); // Rook
    // Drawing black pawns
    for (int i = 0; i < 8; ++i)
    {
        outtextxy(left + i * 50 + 25, top + 325, "p"); // Pawn
    }
    setcolor(RED);
    rectangle(50, 50, 450, 450);
    // Draw a border around the chessboard
}

int main()
{

    initwindow(500, 500, "Chess Board");

    // Draw the base version of the chessboard
    drawBaseChessBoard();

    // Prompt the user to press a key
    std::cout << "Press Enter to continue...";
    std::cin.ignore(); // Wait for the user to press Enter

    // Clear the screen
    cleardevice();

    // Draw the updated version of the chessboard
    drawUpdatedChessBoard();
    system("cls");
    getch(); // Wait for a key press before closing the window

    closegraph();

    return 0;
}