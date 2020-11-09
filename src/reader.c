#include <stdio.h>
#include <stdlib.h>

#include "defines.h"

char *read_brainfuck(FILE *file) {
    char *out = NULL;
    char buffer[READER_BUFFER_SIZE] = "";
    size_t codeSize = 0;
    size_t read = 0;

    while ((read = fread(buffer, 1, READER_BUFFER_SIZE, file)) > 0) {
        
        size_t to_append = 0;

        for (size_t i = 0; i < read; i++)
            if IS_CODE_CHAR(buffer[i])
                to_append += 1;
            
        if (!out) {
            out = malloc(to_append+1);

            if (!out) {
                perror("malloc()");
                exit(EXIT_FAILURE);
            }
        } else {
            out = realloc(out, codeSize+to_append+1);

            if (!out) {
                perror("realloc()");
                exit(EXIT_FAILURE);
            }
        }
        
        {
            size_t y = 0;
            for (size_t i = 0; i < to_append; i++) {
                for (; !IS_CODE_CHAR(buffer[y]); y++);

                out[codeSize+i] = buffer[y];
                y++;
            }
        }

        buffer[codeSize+to_append] = 0;
        codeSize+=to_append;

        if (read != READER_BUFFER_SIZE) /* end of file reached */
            break;
    }

    return out;
}