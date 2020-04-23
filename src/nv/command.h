#ifndef NV_COMMAND_H
#define NV_COMMAND_H

#ifdef __cplusplus
extern "C"
{
#endif

struct nv_context;

typedef int
nv_command_run_fn(
    struct nv_context * context);

extern int
nv_command_run(
    nv_command_run_fn * run,
    struct nv_context * context);

#ifdef __cplusplus
}
#endif

#endif
