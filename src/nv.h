#ifndef NV_H
#define NV_H

#ifndef __cplusplus
#include <stdio.h>
#else
#include <cstdio>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

extern int
nv_main(
    FILE * stdin,
    FILE * stdout,
    FILE * stderr,
    int argc,
    char * argv[]);

#ifdef __cplusplus
}
#endif

#endif
