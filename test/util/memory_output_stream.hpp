#ifndef NV_MEMORY_OUTPUT_STREAM_H
#define NV_MEMORY_OUTPUT_STREAM_H

#include <cstdio>

namespace nv_test
{

class MemoryOutputStream
{
    MemoryOutputStream(MemoryOutputStream const & other) = delete;
    MemoryOutputStream& operator=(MemoryOutputStream const & other) = delete;
public:
    MemoryOutputStream();
    ~MemoryOutputStream();
    operator FILE*();
    FILE * file();
    size_t size();
    char const * c_str();
private:
    FILE * file_;
    char * buffer_;
    size_t size_;
};

}

#endif
