#include "nv/line_reader.h"
#include <gtest/gtest.h>

TEST(nv_line_reader, display_text)
{
    nv_line_reader reader;
    nv_line_reader_init(&reader, "Hello", 0);

    ASSERT_EQ('H', nv_line_reader_current(&reader));
    nv_line_reader_move_next(&reader);

    ASSERT_EQ('e', nv_line_reader_current(&reader));
    nv_line_reader_move_next(&reader);

    ASSERT_EQ('l', nv_line_reader_current(&reader));
    nv_line_reader_move_next(&reader);

    ASSERT_EQ('l', nv_line_reader_current(&reader));
    nv_line_reader_move_next(&reader);

    ASSERT_EQ('o', nv_line_reader_current(&reader));
    nv_line_reader_move_next(&reader);

    ASSERT_EQ(' ', nv_line_reader_current(&reader));
}