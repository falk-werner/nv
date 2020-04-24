#include "nv/document.h"
#include "nv/lines.h"
#include "nv/buffer.h"

#include <stdlib.h>

struct nv_document
{
    struct nv_buffer buffer;
    struct nv_lines lines;
};

static void
nv_document_init_lines(
    struct nv_document * document)
{
    size_t position = 0;
    if (position < document->buffer.size)
    {
        nv_lines_add(&document->lines, position);
    }

    while (position < document->buffer.size)
    {
        char const c = document->buffer.data[position];
        position++;

        if (('\n' == c) && (position < document->buffer.size))
        {
            nv_lines_add(&document->lines, position);
        }
    }
}

struct nv_document *
nv_document_load(
    char const * filename)
{
    struct nv_document * document = NULL;

    struct nv_buffer buffer;
    if (nv_buffer_from_file(&buffer, filename))
    {
        document = malloc(sizeof(struct nv_document));
        document->buffer.data = buffer.data;
        document->buffer.size = buffer.size;
        nv_lines_init(&document->lines);

        nv_document_init_lines(document);
    }

    return document;
}

void
nv_document_release(
    struct nv_document * document)
{    
    nv_lines_cleanup(&document->lines);
    nv_buffer_cleanup(&document->buffer);
}

size_t
nv_document_count_lines(
    struct nv_document * document)
{
    return document->lines.size;
}

char const *
nv_document_get_line(
    struct nv_document * document,
    size_t line)
{
    char const * result = NULL;
    if (line < document->lines.size)
    {
        size_t position = document->lines.data[line];
        result = &(document->buffer.data[position]);
    }

    return result;
}
