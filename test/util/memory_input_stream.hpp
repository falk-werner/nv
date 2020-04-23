#ifndef NV_MEMORY_INPUT_STREAM_H
#define NV_MEMORY_INPUT_STREAM_H

#include <cstdio>
#include <string>

namespace nv_test
{

class MemoryInputStream
{
    MemoryInputStream(MemoryInputStream const & other) = delete;
    MemoryInputStream& operator=(MemoryInputStream const & other) = delete;
public:
    MemoryInputStream();
    explicit MemoryInputStream(std::string const & contents);
    ~MemoryInputStream();
    operator FILE*();
    FILE * file();
private:
    void init();
    std::string contents_;
    FILE * file_;
};

}

#endif
