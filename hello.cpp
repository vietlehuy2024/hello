// hello.cpp : Defines the entry point for the application.
//

#include "hello.h"

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

void clearScreen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
}

void drawFrame(const vector<string>& buffer) {
    clearScreen();
    for (const auto& line : buffer) {
        cout << line << endl;
    }
}

int main()
{
    vector<string> buffer(HEIGHT, string(WIDTH, ' '));

    // Draw a box
    for (int x = 0; x < WIDTH; ++x) {
        buffer[0][x] = '-';
        buffer[HEIGHT - 1][x] = '-';
    }
    for (int y = 0; y < HEIGHT; ++y) {
        buffer[y][0] = '|';
        buffer[y][WIDTH - 1] = '|';
    }

    buffer[0][0] = buffer[0][WIDTH - 1] = '+';
    buffer[HEIGHT - 1][0] = buffer[HEIGHT - 1][WIDTH - 1] = '+';

    drawFrame(buffer);

    this_thread::sleep_for(chrono::seconds(3));
	return 0;
}
