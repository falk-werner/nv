#ifndef LINE_READER_H
#define LINE_READER_H

#ifdef __cplusplus
extern "C"
{
#endif

#define NV_LINE_READER_MODE_NORMAL 1
#define NV_LINE_READER_MODE_SPECIAL 2

struct nv_line_reader
{
    char const * line;
    int pos;
    int hint;
    char current;
    int mode;
};

extern void
nv_line_reader_init(
    struct nv_line_reader * reader,
    char const * line,
    int start);

extern void
nv_line_reader_move_next(
    struct nv_line_reader * reader);

extern char
nv_line_reader_current(
    struct nv_line_reader * reader);

extern int
nv_line_reader_mode(
    struct nv_line_reader * reader);


#ifdef __cplusplus
}
#endif

#endif
