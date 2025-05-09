#include "seryio-ncurses.h"
#include <ncurses.h>
#include <stdlib.h>

/*
 * srync_has_colors: checks if the terminal supports colors
 * @return: void
 * this function checks if the terminal supports colors. If it does not, it ends the ncurses session
 * and prints an error message to the standard output.
 */
void srync_has_colors()
{
    if (!has_colors())
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
}


/*
 * srync_start_color: starts color mode
 * @return: void
 * this function starts color mode in ncurses. If it fails, it ends the ncurses session
 * and prints an error message to the standard output.
*/
void srync_start_color()
{
    if (start_color() == ERR)
    {
        endwin();
        printf("Could not start color\n");
        exit(1);
    }
}

/*
 * srync_init_pair: initializes a color pair
 * @pair: the color pair number
 * @fcolor: the foreground color
 * @bcolor: the background color
 * @return: void
 * this function initializes a color pair. If it fails, it ends the ncurses session
 * and prints an error message to the standard output.
*/
void srync_init_pair(int pair, int fcolor, int bcolor)
{
    if (init_pair(pair, fcolor, bcolor) == ERR)
    {
        endwin();
        printf("Could not initialize color pair\n");
        exit(1);
    }
}

/*
 * srync_check_minimum_terminal_resolution: checks if the terminal resolution is above the minimum
 * @min_rows: the minimum number of rows
 * @min_cols: the minimum number of columns
 * @return: void
 * this function checks if the terminal resolution is above the minimum. If it is not, it ends the ncurses session
 * and prints an error message to the standard output.
*/
void srync_check_minimum_terminal_resolution(int min_rows, int min_cols)
{
    int terminal_rows, terminal_columns;
    getmaxyx(stdscr, terminal_rows, terminal_columns);
    if (terminal_rows < min_rows || terminal_columns < min_cols)
    {
        endwin();
        printf("Terminal size is too small. Minimum size is %d rows and %d columns.\n", min_rows, min_cols);
        exit(1);
    }
}

/*
 * ????????????????????
 * srync_print_row: prints a row of characters in the terminal
 * @config: the configuration for the row
 * @return: void
 * this function prints a row of characters in the terminal. It takes a configuration struct that contains
 * the start height, height, width, character to print and color pair.
*/
void srync_print_row(srync_print_row_configuration_t *config)
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

/*
 * srync_print_cell: prints a cell in the terminal
 * @config: the configuration for the row
 * @return: void
 * this function prints a cell in the terminal. It takes a [x, y] position and configuration struct that contains
 * the character to print and color pair.
*/
void srync_print_cell(short int x, short int y, srync_print_cell_configuration_t *config)
{
    attron(COLOR_PAIR(config->color_pair));
    mvaddch(x, y, config->str);
    attroff(COLOR_PAIR(config->color_pair));
}
