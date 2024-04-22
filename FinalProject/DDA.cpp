/**
    * C++ implementation of DDA line drawing algorithm
    * for console visualization
    *
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void drawLineOnConsole(int x0, int y0, int x1, int y1) {
    const int width = 50;  // Console width
    const int height = 20; // Console height
    std::vector<std::vector<char>> canvas(height, std::vector<char>(width, '.'));

    // DDA Algorithm for line drawing adapted for console visualization
    float dx = x1 - x0;
    float dy = y1 - y0;
    int steps = std::max(abs(dx), abs(dy));
    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x0, y = y0;
    for (int i = 0; i <= steps; i++) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            canvas[static_cast<int>(y)][static_cast<int>(x)] = '#';
        }
        x += xInc;
        y += yInc;
    }

    // Print the canvas
    for (const auto& row : canvas) {
        for (char pixel : row) {
            std::cout << pixel;
        }
        std::cout << '\n';
    }
}

int main() {
    drawLineOnConsole(10, 5, 40, 15); // Adjust parameters to fit the console size
    return 0;
}
