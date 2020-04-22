#include <gtest/gtest.h>
#include <cstdlib>
#include "nv.h"

TEST(nv, test)
{
    int rc = nv_main(0, nullptr);
    ASSERT_EQ(EXIT_FAILURE, rc);
}