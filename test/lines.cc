#include "nv/lines.h"
#include <gtest/gtest.h>

TEST(nv_lines, init)
{
    nv_lines lines;

    nv_lines_init(&lines);
    ASSERT_NE(nullptr, lines.data);
    ASSERT_LT(0, lines.capacity);
    ASSERT_EQ(0, lines.size);
 
    nv_lines_cleanup(&lines);
}

TEST(nv_lines, add)
{
    nv_lines lines;

    nv_lines_init(&lines);
    
    nv_lines_add(&lines, 4711);
    ASSERT_EQ(1, lines.size);
    ASSERT_EQ(4711, lines.data[0]);

    nv_lines_cleanup(&lines);
}

TEST(nv_lines, increase_capacity)
{
    nv_lines lines;

    nv_lines_init(&lines);
    size_t initial_capacity = lines.capacity;
    for(size_t i = 0; i < initial_capacity; i++)
    {
        nv_lines_add(&lines, i);
    }
    
    nv_lines_add(&lines, 4711);
    ASSERT_LT(initial_capacity, lines.capacity);
    ASSERT_EQ(initial_capacity + 1, lines.size);
    ASSERT_EQ(4711, lines.data[initial_capacity]);

    nv_lines_cleanup(&lines);
}
