#include "util/memory_output_stream.hpp"

#include <cstdlib>
#include <stdexcept>


namespace nv_test
{

MemoryOutputStream::MemoryOutputStream()
{
    file_ = open_memstream(&buffer_, &size_);
    if(nullptr == file_)
    {
        throw std::runtime_error("open_memstream: failed to create");
    }
}

MemoryOutputStream::~MemoryOutputStream()
{
    fclose(file_);
    free(buffer_);
}

MemoryOutputStream::operator FILE *()
{
    return file_;
} 

FILE * MemoryOutputStream::file()
{
    return file_;
}

size_t MemoryOutputStream::size()
{
    fflush(file_);
    return size_;
}

char const * MemoryOutputStream::c_str()
{
    fflush(file_);
    return buffer_;
}

}