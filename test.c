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
    const int MAIN_FONT_COLOR = COLOR_RED;
    const int MAIN_BACKGROUND_COLOR = COLOR_WHITE;
    const int HEADER_FONT_COLOR = COLOR_WHITE;
    const int HEADER_BACKGROUND_COLOR = COLOR_BLUE;

    initscr();

    // set color configuration
    srync_has_colors();
    srync_start_color();
    srync_init_pair(1, MAIN_FONT_COLOR, MAIN_BACKGROUND_COLOR);
    srync_init_pair(2, HEADER_FONT_COLOR, HEADER_BACKGROUND_COLOR);

    // check restrictions
    srync_check_minimum_terminal_resolution(MINIMUM_ROWS, MINIMUM_COLUMNS);

    int terminal_rows, terminal_columns;
    getmaxyx(stdscr, terminal_rows, terminal_columns);

    char grid[10][12] = {
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'T', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'T', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'T', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'},
    };

    int grid_rows = sizeof(grid) / sizeof(grid[0]);
    int grid_columns = sizeof(grid[0]) / sizeof(grid[0][0]);

    int row_density = terminal_rows / grid_rows;
    int column_density = terminal_columns / grid_columns;

    for (int i = 0; i < terminal_rows; i++)
    {
        for (int j = 0; j < terminal_columns; j++)
        {
            char row_position_to_find_in_grid = i / row_density;
            if(row_position_to_find_in_grid >= grid_rows) {
                row_position_to_find_in_grid = grid_rows - 1;
            }
            
            char column_position_to_find_in_grid = j / column_density;
            if(column_position_to_find_in_grid >= grid_columns) {
                column_position_to_find_in_grid = grid_columns - 1;
            }
            char character_to_print = grid[row_position_to_find_in_grid][column_position_to_find_in_grid];
            mvaddch(i, j, character_to_print);
        }
    }

    getch();
    endwin();
    return 0;
}