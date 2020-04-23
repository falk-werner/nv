cmake_minimum_required (VERSION 3.10)
project(nv VERSION 0.1.0 DESCRIPTION "text viewer")

option(WITHOUT_TESTS "diable unit tests" OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSES REQUIRED ncurses)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(src/nv/version.h.in gen/nv/version.h)

add_library(nv_static STATIC
    src/nv/main.c
    src/nv/context.c
    src/nv/command.c
    src/nv/print_usage.c
    src/nv/print_version.c
)

target_include_directories(nv_static PUBLIC
    src
    ${CMAKE_CURRENT_BINARY_DIR}/gen
)

target_link_libraries(nv_static PUBLIC
    ${NCURSES_LIBRARIES}
)

add_executable(nv
    src/main.c
)

target_link_libraries(nv
    nv_static
)

install(TARGETS nv DESTINATION bin)

set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "nv-${PROJECT_VERSION}")
set(CPACK_SOURCE_IGNORE_FILES
    "${CMAKE_SOURCE_DIR}/build/"
    "${CMAKE_SOURCE_DIR}/.git/"
)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_DESCRIPTION "text viewer")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Falk Werner")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_FILE_NAME "nv_${PROJECT_VERSION}.deb")
set(CPACK_DEBIAN_PACKAGE_NAME "nv")

include(CPack)

if(NOT WITHOUT_TESTS)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

pkg_check_modules(GTEST gtest_main)
include(GoogleTest)
pkg_check_modules(GMOCK gmock)

add_executable(alltests
    test/util/memory_output_stream.cc
    test/util/memory_input_stream.cc
    test/main.cc
    test/context.cc
)

target_include_directories(alltests PRIVATE
    test
    ${GMOCK_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(alltests PRIVATE
    nv_static
    ${CMAKE_THREAD_LIBS_INIT}
    ${GMOCK_LIBRARIES}
    ${GTEST_LIBRARIES}
)

endif()
