#include "nv/commands.h"
#include "nv/context.h"
#include "nv/document.h"
#include "nv/line_reader.h"

#include <curses.h>

#include <stdlib.h>
#include <stdio.h>


int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

static void quit(void)
{
    endwin();
}

static void update_screen(
    int offset_x,
    int offset_y,
    struct nv_document * document)
{
    int height, width;
    getmaxyx(stdscr, height ,width);
    clear();

    int line_count = nv_document_count_lines(document);
    int displayed_lines = min(height, line_count - offset_y);
    for (int y = 0; y < displayed_lines; y++)
    {
        char const * line = nv_document_get_line(document, offset_y + y);
        struct nv_line_reader reader;
        nv_line_reader_init(&reader, line, offset_x);

        for(int x = 0; x < width; x++)
        {
            char c = nv_line_reader_current(&reader);
            color_set(nv_line_reader_mode(&reader), NULL);
            mvaddch(y, x, c);
            nv_line_reader_move_next(&reader); 
        }
    }

    refresh();
}

int
nv_view_file(
    struct nv_context * context)
{
    if (NULL == context->filename) 
    {
        fprintf(context->err, "error: not implemented\n");
        return EXIT_FAILURE;
    }

    struct nv_document * document = nv_document_load(context->filename);
    if (NULL == document)
    {
        fprintf(context->err, "error: failed to read file\n");
        return EXIT_FAILURE;
    }

    initscr();
    atexit(&quit);
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    start_color();

    if (can_change_color())
    {
        init_color(COLOR_BLACK, 100, 100, 100);
        init_color(COLOR_GREEN, 800, 800, 800);
        init_color(COLOR_WHITE, 300, 300, 300);
    }

    init_pair(NV_LINE_READER_MODE_NORMAL, COLOR_GREEN, COLOR_BLACK);
    init_pair(NV_LINE_READER_MODE_SPECIAL, COLOR_WHITE, COLOR_BLACK);


    int const line_count = nv_document_count_lines(document);
    int offset_x = 0;
    int offset_y = 0;
    update_screen(offset_x, offset_y, document);
    bool is_running = true;
    while (is_running)
    {
        int key = getch();
        switch (key)
        {
            case 27: //fall-through
            case KEY_F(10): //fall-through
            case 'q':
                is_running = false;
                break;
            case 'w':
                // fall-through
            case KEY_UP:
                if (0 < offset_y)
                {
                    offset_y--;
                    update_screen(offset_x, offset_y, document);
                }
                break;
            case 's':
                // fall-through
            case KEY_DOWN:
                if (line_count > offset_y)
                {
                    offset_y++;
                    update_screen(offset_x, offset_y, document);
                }
                break;
            case 'a':
                // fall-through
            case KEY_LEFT:
                if (0 < offset_x)
                {
                    offset_x--;
                    update_screen(offset_x, offset_y, document);
                }
                break;
            case 'd':
                // fall-through
            case KEY_RIGHT:
                {
                    offset_x++;
                    update_screen(offset_x, offset_y, document);
                }
                break;
            case KEY_HOME:
                {
                    offset_y = 0;
                    offset_x = 0;
                    update_screen(offset_x, offset_y, document);
                }
                break;
            case KEY_END:
                {
                    offset_y = line_count;
                    offset_x = 0;
                    update_screen(offset_x, offset_y, document);
                }
                break;
            case KEY_PPAGE:
                {
                    int height = getmaxy(stdscr);
                    offset_y = (offset_y > height) ? offset_y - height : 0;
                    update_screen(offset_x, offset_y, document);
                }
                break;
            case KEY_NPAGE:
                {
                    int height = getmaxy(stdscr);
                    offset_y = min(offset_y + height, line_count);
                    update_screen(offset_x, offset_y, document);
                }
                break;
            default:
                break;
        }

    }

    nv_document_release(document);
    return EXIT_SUCCESS;

}
