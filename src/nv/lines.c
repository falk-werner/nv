#include "lines.h"
#include <stdlib.h>

#define NV_LINES_DEFAULT_CAPACITY 16

void
nv_lines_init(
    struct nv_lines * lines)
{
    lines->data = malloc(sizeof(size_t) * NV_LINES_DEFAULT_CAPACITY);
    lines->capacity = NV_LINES_DEFAULT_CAPACITY;
    lines->size = 0;

}

void
nv_lines_cleanup(
    struct nv_lines * lines)
{
    free(lines->data);
}

void
nv_lines_add(
    struct nv_lines * lines,
    size_t position)
{
    if (lines->size >= lines->capacity)
    {
        lines->capacity *= 2;
        lines->data = realloc(lines->data, sizeof(size_t) * lines->capacity);
    }

    lines->data[lines->size] = position;
    lines->size++;
}
