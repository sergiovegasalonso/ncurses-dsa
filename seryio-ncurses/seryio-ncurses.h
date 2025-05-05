#ifndef SERYIO_NCURSES_H
#define SERYIO_NCURSES_H

void srync_has_colors();

void srync_start_color();

void srync_init_pair(int pair, int fcolor, int bcolor);

void srync_check_minimum_terminal_resolution(int min_rows, int min_cols);

typedef struct
{
    int start_height;
    int height;
    int width;
    const char str;
    int color_pair;
} srync_print_row_configuration_t;

void srync_print_row(srync_print_row_configuration_t *config);

typedef struct
{
    const char str;
    int color_pair;
} srync_print_cell_configuration_t;

void srync_print_cell(short int x, short int y, srync_print_cell_configuration_t *config);
#endif // SERYIO_NCURSES_H