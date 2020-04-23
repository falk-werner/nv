#include "nv/context.h"
#include "nv/commands.h"

#include <getopt.h>

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void
nv_context_init(
    struct nv_context * context,
    FILE * in,
    FILE * out,
    FILE * err,
    int argc,
    char * argv[])
{
    context->in = in;
    context->out = out;
    context->err = err;
    context->filename = NULL;
    context->command = &nv_print_usage;
    context->exit_code = EXIT_SUCCESS;

    static struct option const options[] =
    {
        {"file", required_argument, NULL, 'f'},
        {"help", no_argument, NULL, 'h'},
        {NULL, 0, NULL, 0}
    };

    optind = 0;
    bool is_finished = false;
    while (!is_finished)
    {
        int option_index = 0;
        int const c = getopt_long(argc, argv, "f:h", options, &option_index);
        
        switch (c)
        {
            case -1:
                is_finished = true;
                break;
            case 'h':
                context->command = &nv_print_usage;
                is_finished = true;
                break;
            case 'f':
                free(context->filename);
                context->filename = strdup(optarg);
                break;
            default:
                fprintf(context->err, "error: unknown argument\n");
                context->command = &nv_print_usage;
                context->exit_code = EXIT_FAILURE;
                is_finished = true;
                break;
        }
    }

}

void
nv_context_cleanup(
    struct nv_context * context)
{
    free(context->filename);
}
