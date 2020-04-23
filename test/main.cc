#include <gtest/gtest.h>
#include <cstdlib>
#include "nv/main.h"
#include "util/memory_output_stream.hpp"
#include "util/memory_input_stream.hpp"

using nv_test::MemoryOutputStream;
using nv_test::MemoryInputStream;

TEST(nv_main, print_usage)
{
    MemoryInputStream in;
    MemoryOutputStream out;
    MemoryOutputStream err;

    int rc = nv_main(in, out, err, 0, nullptr);
    ASSERT_LT(0, out.size());
    ASSERT_STREQ("", err.c_str());
    ASSERT_EQ(EXIT_SUCCESS, rc);
}