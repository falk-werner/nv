#include "nv/context.h"
#include "nv/commands.h"
#include "util/memory_input_stream.hpp"
#include "util/memory_output_stream.hpp"
#include <gtest/gtest.h>

using nv_test::MemoryInputStream;
using nv_test::MemoryOutputStream;

TEST(nv_context, init_default)
{
    MemoryInputStream in;
    MemoryOutputStream out;
    MemoryOutputStream err;

    nv_context context;
    nv_context_init(&context, in, out, err, 0, nullptr);
    ASSERT_EQ(EXIT_SUCCESS, context.exit_code);
    ASSERT_STREQ("", out.c_str());
    ASSERT_STREQ("", err.c_str());
    ASSERT_EQ(nullptr, context.filename);

    nv_context_cleanup(&context);
}

TEST(nv_context, init_filename)
{
    MemoryInputStream in;
    MemoryOutputStream out;
    MemoryOutputStream err;

    int argc = 2;
    char argv0[] = "nv";
    char argv1[] = "some.file";
    char * argv[] = {argv0, argv1, nullptr};

    nv_context context;
    nv_context_init(&context, in, out, err, argc, argv);
    ASSERT_EQ(EXIT_SUCCESS, context.exit_code);
    ASSERT_STREQ("", out.c_str());
    ASSERT_STREQ("", err.c_str());
    ASSERT_STREQ("some.file", context.filename);

    nv_context_cleanup(&context);
}

TEST(nv_context, invalid_option)
{
    MemoryInputStream in;
    MemoryOutputStream out;
    MemoryOutputStream err;

    int argc = 2;
    char argv0[] = "nv";
    char argv1[] = "--invalid";
    char * argv[] = {argv0, argv1, nullptr};

    nv_context context;
    nv_context_init(&context, in, out, err, argc, argv);
    ASSERT_EQ(EXIT_FAILURE, context.exit_code);
    ASSERT_STREQ("", out.c_str());
    ASSERT_STRNE("", err.c_str());

    nv_context_cleanup(&context);
}

TEST(nv_context, print_usage)
{
    MemoryInputStream in;
    MemoryOutputStream out;
    MemoryOutputStream err;

    int argc = 2;
    char argv0[] = "nv";
    char argv1[] = "--help";
    char * argv[] = {argv0, argv1, nullptr};

    nv_context context;
    nv_context_init(&context, in, out, err, argc, argv);
    ASSERT_EQ(EXIT_SUCCESS, context.exit_code);
    ASSERT_STREQ("", out.c_str());
    ASSERT_STREQ("", err.c_str());
    ASSERT_EQ(&nv_print_usage, context.command);

    nv_context_cleanup(&context);
}

TEST(nv_context, print_version)
{
    MemoryInputStream in;
    MemoryOutputStream out;
    MemoryOutputStream err;

    int argc = 2;
    char argv0[] = "nv";
    char argv1[] = "--version";
    char * argv[] = {argv0, argv1, nullptr};

    nv_context context;
    nv_context_init(&context, in, out, err, argc, argv);
    ASSERT_EQ(EXIT_SUCCESS, context.exit_code);
    ASSERT_STREQ("", out.c_str());
    ASSERT_STREQ("", err.c_str());
    ASSERT_EQ(&nv_print_version, context.command);

    nv_context_cleanup(&context);
}
