#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// #include "arithmetics/arithmetics.h"
// printf("Addition: %d\n", add(num1, num2));

char *getConcatString(const char *str1, const char *str2)
{
    char *finalString = NULL;
    size_t n = 0;

    if (str1)
        n += strlen(str1);
    if (str2)
        n += strlen(str2);

    if ((str1 || str2) && (finalString = malloc(n + 1)) != NULL)
    {
        *finalString = '\0';

        if (str1)
            strcpy(finalString, str1);
        if (str2)
            strcat(finalString, str2);
    }

    return finalString;
}

int main()
{
    char *message = "This is a test message";
    initscr();

    addstr(getConcatString(message, "\n")); // Print the message to the screen
    printw("Press any key to exit...");
    refresh();

    int num1 = 10, num2 = 5;

    refresh();

    getch(); // Wait for user input

    endwin();
    return 0;
}
