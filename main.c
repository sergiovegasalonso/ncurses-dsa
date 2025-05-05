#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "seryio/seryio.h"
#include "seryio-ncurses/seryio-ncurses.h"

int main()
{
    // restrictions configuration
    const int MINIMUM_ROWS = 50;
    const int MINIMUM_COLS = 100;

    // texts configuration
    char *windows_title = "SERGIO'S NCURSES APPLICATION";

    initscr();

    // set color configuration
    use_default_colors();

    // check restrictions
    srync_check_minimum_terminal_resolution(MINIMUM_ROWS, MINIMUM_COLS);

    // app
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    srync_print_row_configuration_t padding_top = {/* start height */ 0, /* height */ 2, /* width */ cols, /* char to print */ ' ', /* color_pair */ 0};
    srync_print_row_configuration_t row2 = {/* start height */ 2, /* height */ 1, /* width */ cols, /* char to print */ ' ', /* color_pair */ 1};
    srync_print_row_configuration_t row3 = {/* start height */ 3, /* height */ 2, /* width */ cols, /* char to print */ ' ', /* color_pair */ 2};
    srync_print_row_configuration_t row4 = {/* start height */ 5, /* height */ 1, /* width */ cols, /* char to print */ ' ', /* color_pair */ 1};
    srync_print_row_configuration_t row5 = {/* start height */ 6, /* height */ 2, /* width */ cols, /* char to print */ ' ', /* color_pair */ 2};

    // second row
    mvaddch(1, 0, 'Y');
    printw(" jeejj");

    getch();

    endwin();
    return 0;
}
