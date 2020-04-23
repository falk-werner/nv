#include "nv.h"
#include <stdlib.h>
#include <curses.h>
#include <getopt.h>

struct nv_context
{
    FILE * in;
    FILE * out; 
    FILE * err;
    char * filename;
};

extern int
nv_main(
    FILE * in,
    FILE * out,
    FILE * err,
    int argc,
    char * argv[])
{
    struct nv_context context;
    context.in = in;
    context.out = out;
    context.err = err;
    context.filename = NULL;

    fprintf(context.err, "error: not implemented\n");

    return EXIT_FAILURE;
}
