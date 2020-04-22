#include <stdlib.h>
#include <curses.h>

extern int
nv_main(
    int argc,
    char * argv[])
{
    initscr();
    endwin();
    return EXIT_FAILURE;
}
