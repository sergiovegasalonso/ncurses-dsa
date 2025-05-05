#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "seryio/seryio.h"
#include "seryio-ncurses/seryio-ncurses.h"

int main()
{
    // restrictions configuration
    const int MINIMUM_ROWS = 50;
    const int MINIMUM_COLUMNS = 100;

    // texts configuration
    char *windows_title = "SERGIO'S NCURSES APPLICATION";

    // theme configuration
    const int HEADER_FONT_COLOR = COLOR_WHITE;
    const int HEADER_BACKGROUND_COLOR = COLOR_BLUE;
    const int MAIN_FONT_COLOR = COLOR_WHITE;
    const int MAIN_BACKGROUND_COLOR = COLOR_BLACK;

    initscr();

    // set color configuration
    srync_has_colors();
    srync_start_color();
    srync_init_pair(1, HEADER_FONT_COLOR, HEADER_BACKGROUND_COLOR);
    srync_init_pair(2, MAIN_FONT_COLOR, MAIN_BACKGROUND_COLOR);

    // check restrictions
    srync_check_minimum_terminal_resolution(MINIMUM_ROWS, MINIMUM_COLUMNS);

    // app
    unsigned short int terminal_rows, terminal_columns;
    getmaxyx(stdscr, terminal_rows, terminal_columns);

    const srync_print_cell_configuration_t HEADER = {/* char to print */ ' ', /* color_pair */ 1};
    const srync_print_cell_configuration_t MAIN = {/* char to print */ ' ', /* color_pair */ 2};
    const srync_print_cell_configuration_t grid[40][12] = {
        {HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER},
        {HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER},
        {HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER, HEADER},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
        {  MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN,   MAIN},
    };

    unsigned short int grid_rows = sizeof(grid) / sizeof(grid[0]);
    unsigned short int grid_columns = sizeof(grid[0]) / sizeof(grid[0][0]);

    unsigned short int row_density = terminal_rows / grid_rows;
    unsigned short int column_density = terminal_columns / grid_columns;

    for (unsigned short int i = 0; i < terminal_rows; i++)
    {
        for (unsigned short int j = 0; j < terminal_columns; j++)
        {
            char row_position_to_find_in_grid = i / row_density;
            if (row_position_to_find_in_grid >= grid_rows)
            {
                row_position_to_find_in_grid = grid_rows - 1;
            }

            char column_position_to_find_in_grid = j / column_density;
            if (column_position_to_find_in_grid >= grid_columns)
            {
                column_position_to_find_in_grid = grid_columns - 1;
            }
            srync_print_cell_configuration_t cell_to_print = grid[row_position_to_find_in_grid][column_position_to_find_in_grid];
            srync_print_cell(i, j, &cell_to_print);
        }
    }

    // bkgd(COLOR_PAIR(1));

    getch();
    endwin();
    return 0;
}