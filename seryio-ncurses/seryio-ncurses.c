#include "seryio-ncurses.h"
#include <ncurses.h>
#include <stdlib.h>

void ncurses_has_colors()
{
    if (!has_colors())
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
}

void ncurses_start_color()
{
    if (start_color() == ERR)
    {
        endwin();
        printf("Could not start color\n");
        exit(1);
    }
}

void ncurses_init_pair(int pair, int fcolor, int bcolor)
{
    if (init_pair(pair, fcolor, bcolor) == ERR)
    {
        endwin();
        printf("Could not initialize color pair\n");
        exit(1);
    }
}