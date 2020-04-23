#ifndef NV_BUFFER_H
#define NV_BUFFER_H

#ifndef __cplusplus
#include <stddef.h>
#include <stdbool.h>
#else
#include <cstddef>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

struct nv_buffer
{
    size_t size;
    char * data;
};

extern bool
nv_buffer_from_file(
    struct nv_buffer * buffer,
    char const * filename);

extern void
nv_buffer_cleanup(
    struct nv_buffer * buffer);

#ifdef __cplusplus
}
#endif

#endif