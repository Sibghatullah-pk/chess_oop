#include <iostream>

void drawChessboard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                std::cout << "\u2588\u2588"; // Black square
            } else {
                std::cout << "  "; // White square
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    drawChessboard();
    return 0;
}
