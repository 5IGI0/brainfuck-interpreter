#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <stdint.h>

#define BUFFER_SIZE 500
#define PTR_START_AT (int)(BUFFER_SIZE/2)
#define CELL_TYPE int16_t
#define MAX_VALUE SHRT_MAX
#define MIN_VALUE SHRT_MIN
#define READER_BUFFER_SIZE 1024

#define IS_CODE_CHAR(x) (\
    x == '+' ||\
    x == '-' ||\
    x == '<' ||\
    x == '>' ||\
    x == '[' ||\
    x == ']' ||\
    x == '.' ||\
    x == ','\
)

#endif