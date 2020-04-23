#include "util/memory_input_stream.hpp"
#include <stdexcept>

namespace nv_test
{

MemoryInputStream::MemoryInputStream()
: contents_()
{
    init();
}


MemoryInputStream::MemoryInputStream(std::string const & contents)
: contents_(contents)
{
    init();
}

void MemoryInputStream::init()
{
    void * buffer = const_cast<void*>(reinterpret_cast<void const *>(contents_.c_str()));
    file_ = fmemopen(buffer, contents_.size(), "rb");
    if (nullptr == file_)
    {
        throw std::runtime_error("fmemopen: failed to create");
    }
}

MemoryInputStream::~MemoryInputStream()
{
    fclose(file_);
}

MemoryInputStream::operator FILE*()
{
    return file_;
}

FILE * MemoryInputStream::file()
{
    return file_;
}

}