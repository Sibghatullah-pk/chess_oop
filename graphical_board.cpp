#include <iostream>
#include <graphics.h>
#include <iostream>

using namespace std;
const int SQUARE_SIZE = 50; 


void drawStartPage() {
    setbkcolor(BLUE); // Set background color
    cleardevice(); // Clear the screen
    
    // Set text properties
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    
    // Draw title
    outtextxy(50, 50, "Chess Game");
    
    // Draw start button
    setfillstyle(SOLID_FILL, BLACK);
    bar(130, 200, 400, 250); // Button rectangle
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(150, 210, "Start Game");
    
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(160, 260, "..press any key");
}
// Function to draw the base version of the chessboard
void drawBaseChessBoard() {
    int left = 50, top = 50, right = left + SQUARE_SIZE, bottom = top + SQUARE_SIZE;
    int row, col;

    // Drawing column indices
    for (col = 0; col < 8; ++col) {
        outtextxy(left + col * SQUARE_SIZE + 20, top - 20, "1");
    }

    // Drawing row indices and the chessboard
    for (row = 0; row < 8; ++row) {
        // Drawing row indices
        outtextxy(left - 20, top + row * SQUARE_SIZE + 20, "1");

        for (col = 0; col < 8; ++col) {
            if ((row + col) % 2 == 0)
                setfillstyle(SOLID_FILL, WHITE);
            else
                setfillstyle(SOLID_FILL, BROWN);

            bar(left + col * SQUARE_SIZE, top + row * SQUARE_SIZE, right + col * SQUARE_SIZE, bottom + row * SQUARE_SIZE);
        }
    }
}


// Function to draw the updated version of the chessboard
void drawUpdatedChessBoard() {
    // Your updated chessboard drawing code here
    // This could include drawing pieces in different positions or adding effects
    // For simplicity, let's just draw a border around the board
     int left = 50, top = 50, right = 100, bottom = 100;
  drawBaseChessBoard();
setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);

    // Drawing white pieces
    outtextxy(left + 25, top + 25, "R"); // Rook
    outtextxy(left + 75, top + 25, "N"); // Knight
    outtextxy(left + 125, top + 25, "B"); // Bishop
    outtextxy(left + 175, top + 25, "Q"); // Queen
    outtextxy(left + 225, top + 25, "K"); // King
    outtextxy(left + 275, top + 25, "B"); // Bishop
    outtextxy(left + 325, top + 25, "N"); // Knight
    outtextxy(left + 375, top + 25, "R"); // Rook
    // Drawing white pawns
    for (int i = 0; i < 8; ++i) {
        outtextxy(left + i * 50+25, top + 75, "P"); // Pawn
    }

    // Drawing black pieces
    outtextxy(left + 25, top + 375, "r"); // Rook
    outtextxy(left + 75, top + 375, "n"); // Knight
    outtextxy(left + 125, top + 375, "b"); // Bishop
    outtextxy(left + 175, top + 375, "q"); // Queen
    outtextxy(left + 225, top + 375, "k"); // King
    outtextxy(left + 275, top + 375, "b"); // Bishop
    outtextxy(left + 325, top + 375, "n"); // Knight
    outtextxy(left + 375, top + 375, "r"); // Rook
    // Drawing black pawns
    for (int i = 0; i < 8; ++i) {
        outtextxy(left + i * 50+25, top + 325, "p"); // Pawn
    }
    setcolor(RED);
    rectangle(50, 50, 450, 450); 
	// Draw a border around the chessboard
}

int main() {
    initwindow(500, 500, "Chess Board");
 	drawStartPage(); // Draw start page
    
    getch(); // Wait for user input
    
    // Draw the base version of the chessboard
    drawBaseChessBoard();

    // Prompt the user to press a key
    std::cout << "Press Enter to continue...";
    std::cin.ignore(); // Wait for the user to press Enter

    // Clear the screen
    cleardevice();

    // Draw the updated version of the chessboard
    drawUpdatedChessBoard();

    getch(); // Wait for a key press before closing the window

    closegraph();

    return 0;
}