#ifndef NV_CONTEXT_H
#define NV_CONTEXT_H

#include "nv/command.h"

#ifndef __clusplus
#include <stdio.h>
#else
#include <cstdio>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

struct nv_context
{
    FILE * in;
    FILE * out; 
    FILE * err;
    char * filename;
    nv_command_run_fn * command;
    int exit_code;
};

extern void
nv_context_init(
    struct nv_context * context,
    FILE * in,
    FILE * out,
    FILE * err,
    int argc,
    char * argv[]);

extern void
nv_context_cleanup(
    struct nv_context * context);


#ifdef __cplusplus
}
#endif


#endif