#include "nv/commands.h"
#include "nv/context.h"
#include "nv/buffer.h"

#include <stdlib.h>
#include <stdio.h>

int
nv_view_file(
    struct nv_context * context)
{
    if (NULL == context->filename) 
    {
        fprintf(context->err, "error: not implemented\n");
        return EXIT_FAILURE;
    }

    struct nv_buffer  buffer;
    bool result = nv_buffer_from_file(&buffer, context->filename); 
    if (!result)
    {
        fprintf(context->err, "error: failed to read file\n");
        return EXIT_FAILURE;
    }

    fprintf(context->out, "size: %zu\n", buffer.size);

    nv_buffer_cleanup(&buffer);
    return EXIT_SUCCESS;

}
