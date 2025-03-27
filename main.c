#include <ncurses.h>
#include <stdio.h>
#include "seryio/seryio.h"

int main()
{
    char *message = "This is a test message";
    initscr();

    addstr(get_concat_string(message, "\n")); // Print the message to the screen
    printw("Press any key to exit...");
    refresh();

    getch(); // Wait for user input

    endwin();
    return 0;
}
