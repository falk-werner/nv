#include "nv/buffer.h"

#include <stdio.h>
#include <stdlib.h>

bool
nv_buffer_from_file(
    struct nv_buffer * buffer,
    char const * filename)
{
    FILE * file = fopen(filename, "rb");
    bool result = (NULL != file);
    if (result)
    {
        fseek(file, 0, SEEK_END);        
        size_t size = ftell(file);
        fseek(file, 0, SEEK_SET);

        char * data = malloc(size);
        size_t bytesRead = fread(data, 1, size, file);
        if (bytesRead == size)
        {
            buffer->data = data;
            buffer->size = size;
        }
        else
        {
            free(data);
            result = false;
        }
        
        fclose(file);
    }

    return result;
}

void
nv_buffer_cleanup(
    struct nv_buffer * buffer)
{
    free(buffer->data);
}
