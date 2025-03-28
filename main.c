#include <ncurses.h>
#include <stdio.h>
#include "seryio/seryio.h"
#include "seryio-ncurses/seryio-ncurses.h"

int main()
{
    char *message = "This is a test message";
    initscr();

    // colors configuration
    ncurses_has_colors();
    ncurses_start_color();
    ncurses_init_pair(1, COLOR_RED, COLOR_BLACK);

    bkgd(COLOR_PAIR(1));
    //refresh();
    getch();    

    endwin();
    return 0;
}
