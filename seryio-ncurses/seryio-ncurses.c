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

void ncurses_check_minimum_terminal_resolution(int min_rows, int min_cols)
{
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    if (rows < min_rows || cols < min_cols)
    {
        endwin();
        printf("Terminal size is too small. Minimum size is %d rows and %d columns.\n", min_rows, min_cols);
        exit(1);
    }
}

void ncurses_print_row(ncurses_print_row_configuration_t *config)
{
    attron(COLOR_PAIR(config->color_pair));
    for (int i = 0; i < config->width; i++)
    {
        for (int j = config->start_height; j < config->start_height + config->height; j++)
        {
            mvaddch(j, i, config->str);
        }
    }
    attroff(COLOR_PAIR(config->color_pair));
}
