#include "nv/commands.h"
#include "nv/context.h"
#include "nv/version.h"

int
nv_print_usage(
    struct nv_context * context)
{
    fprintf(context->out, 
        "nv V" NV_VERSION ", " NV_COPYRIGHT "\n"
        "eNVy text viewer\n"
        "\n"
        "Usage:\n"
        "\tnv <filname>\n"
        "\n"
        "Options:\n"
        "\t-v, --version  print version and exit\n"
        "\t-h, --help     print usage and exit\n"
    );

    return context->exit_code;
}