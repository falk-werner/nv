#include "nv/line_reader.h"

static void nv_line_reader_update(
    struct nv_line_reader * reader)
{
    reader->current= reader->line[reader->pos];
    reader->mode = NV_LINE_READER_MODE_NORMAL;
    if (('\n' == reader->current) || ('\0' == reader->current))
    {
        reader->current = '$';
        reader->mode = NV_LINE_READER_MODE_SPECIAL;
        reader->hint = -1;
    }
    else if (' ' == reader->current)
    {
        reader->current = '.';
        reader->mode = NV_LINE_READER_MODE_SPECIAL;
    }
    else if ('\t' == reader->current)
    {
        reader->current = ' ';
        reader->mode = NV_LINE_READER_MODE_SPECIAL;
        reader->hint = 3;
    }
    else if ((('\0' < reader->current) && (reader->current < ' ')) || (127 < reader->current))
    {
        reader->current = '?';
        reader->mode = NV_LINE_READER_MODE_SPECIAL;
    }
}

void
nv_line_reader_init(
    struct nv_line_reader * reader,
    char const * line,
    int start)
{
    reader->hint = 0;
    reader->line = line;
    reader->pos = 0;
    reader->mode = NV_LINE_READER_MODE_NORMAL;

    nv_line_reader_update(reader);
    for(int i = 0; i < start; i++)
    {
        nv_line_reader_move_next(reader);
    }
}

void
nv_line_reader_move_next(
    struct nv_line_reader * reader)
{
    if (0 == reader->hint)
    {
        reader->pos++;
        nv_line_reader_update(reader);
    }
    else if (0 < reader->hint)
    {
        reader->hint--;
        reader->current = (0 < reader->hint) ? '>' : ' ';
    }
    else
    {
        reader->current = ' ';
    }
    
}

char
nv_line_reader_current(
    struct nv_line_reader * reader)
{
    return reader->current;
}

int
nv_line_reader_mode(
    struct nv_line_reader * reader)
{
    return reader->mode;
}
