#ifndef NV_COMMANDS_H
#define NV_COMMANDS_H

#include "nv/command.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern int
nv_print_usage(
    struct nv_context * context);

extern int
nv_print_version(
    struct nv_context * context);

#ifdef __cplusplus
}
#endif

#endif