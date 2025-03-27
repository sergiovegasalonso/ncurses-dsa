#include <ncurses.h>

int main() {
    initscr();

    addstr("Hello World");
    
    endwin();
    return 0;
}
// Compile with: g++ main.cpp -o hello_world -lncurses
// Run with: ./hello_world