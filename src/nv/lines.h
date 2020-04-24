#ifndef NV_LINES_H
#define NV_LINES_H

#ifndef __cplusplus
#include <stddef.h>
#else
#include <cstddef>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

struct nv_lines
{
    size_t * data;
    size_t size;
    size_t capacity;
};

extern void
nv_lines_init(
    struct nv_lines * lines);

extern void
nv_lines_cleanup(
    struct nv_lines * lines);

extern void
nv_lines_add(
    struct nv_lines * lines,
    size_t position);

#ifdef __cplusplus
}
#endif

#endif
