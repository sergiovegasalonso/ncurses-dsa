#ifndef SERYIO_NCURSES_H
#define SERYIO_NCURSES_H

void ncurses_has_colors();
void ncurses_start_color();
void ncurses_init_pair(int pair, int fcolor, int bcolor);
void ncurses_check_minimum_terminal_resolution(int min_rows, int min_cols);
typedef struct
{
    int start_height;
    int height;
    int width;
    const char str;
    int color_pair;
} ncurses_print_row_configuration_t;
void ncurses_print_row(ncurses_print_row_configuration_t *config);

#endif // SERYIO_NCURSES_H