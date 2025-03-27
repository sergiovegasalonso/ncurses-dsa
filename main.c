#include <ncurses.h>
#include "arithmetics/arithmetics.h"

int main()
{
    initscr();

    addstr("Hello World");

    int num1 = 10, num2 = 5;
    printf("Addition: %d\n", add(num1, num2));

    endwin();
    return 0;
}
