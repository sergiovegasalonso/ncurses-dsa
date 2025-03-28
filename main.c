#include <ncurses.h>
#include <stdio.h>
#include "seryio/seryio.h"
#include "seryio-ncurses/seryio-ncurses.h"

int main()
{
    // restrictions configuration
    const int MINIMUM_ROWS = 50;
    const int MINIMUM_COLS = 100;

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
    srync_check_minimum_terminal_resolution(MINIMUM_ROWS, MINIMUM_COLS);

    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    srync_print_row_configuration_t row1 = {/* start height */ 0, /* height */ 2, /* width */ cols, /* char to print */ ' ', /* color_pair */ 2};
    srync_print_row_configuration_t row2 = {/* start height */ 2, /* height */ 1, /* width */ cols, /* char to print */ ' ', /* color_pair */ 1};
    srync_print_row_configuration_t row3 = {/* start height */ 3, /* height */ 2, /* width */ cols, /* char to print */ ' ', /* color_pair */ 2};
    srync_print_row_configuration_t row4 = {/* start height */ 5, /* height */ 1, /* width */ cols, /* char to print */ ' ', /* color_pair */ 1};
    srync_print_row_configuration_t row5 = {/* start height */ 6, /* height */ 2, /* width */ cols, /* char to print */ ' ', /* color_pair */ 2};
    srync_print_row(&row1);
    srync_print_row(&row2);
    srync_print_row(&row3);
    srync_print_row(&row4);
    srync_print_row(&row5);

    bkgd(COLOR_PAIR(1));

    getch();

    endwin();
    return 0;
}
