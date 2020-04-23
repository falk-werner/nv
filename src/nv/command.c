#include "nv/command.h"

int
nv_command_run(
    nv_command_run_fn * run,
    struct nv_context * context)
{
    return run(context);
}
