#include "nv/commands.h"
#include "nv/context.h"

int
nv_print_usage(
    struct nv_context * context)
{
    fprintf(context->out, 
        "nv, (C) 2020 Falk Werner\n"
        "eNVy text viewer\n"
        "\n"
        "Usage:\n"
        "\tnv -f <filname>\n"
        "\n"
        "Arguments:\n"
        "\t-f, --file <filename>  file to view\n"
    );

    return context->exit_code;
}