#ifndef NV_DOCUMENT_H
#define NV_DOCUMENT_H

#ifndef __cplusplus
#include <stddef.h>
#else
#include <cstddef>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

struct nv_document;

extern struct nv_document *
nv_document_load(
    char const * filename);

extern void
nv_document_release(
    struct nv_document * document);

extern size_t
nv_document_count_lines(
    struct nv_document * document);

extern char const *
nv_document_get_line(
    struct nv_document * document,
    size_t line);

#ifdef __cplusplus
}
#endif

#endif
