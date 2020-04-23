#include "nv/main.h"
#include "nv/context.h"

#include <stdlib.h>
#include <curses.h>
#include <getopt.h>

int
nv_main(
    FILE * in,
    FILE * out,
    FILE * err,
    int argc,
    char * argv[])
{
    struct nv_context context;
    nv_context_init(&context, in, out, err, argc, argv);

    int exit_code = nv_command_run(context.command, &context);
    nv_context_cleanup(&context);
    return exit_code;
}
