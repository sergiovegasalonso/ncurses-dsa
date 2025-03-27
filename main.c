#include <ncurses.h>
#include <stdio.h>
#include "seryio/seryio.h"

int main()
{
    char *message = "This is a test message";
    initscr();

    addstr(get_concat_string(message, "\n"));
    printw("Press any key to exit...");
    refresh();

    getch();

    endwin();
    return 0;
}
