#ifndef SERYIO_NCURSES_H
#define SERYIO_NCURSES_H

void ncurses_has_colors();
void ncurses_start_color();
void ncurses_init_pair(int pair, int fcolor, int bcolor);

#endif // SERYIO_NCURSES_H