#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#include "defines.h"
#include "reader.h"
#include "validator.h"
#include "execute.h"

int main(int argc, char const *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "usage: %s <source code>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *code = NULL;
    FILE *fcode = NULL;

    fcode = fopen(argv[1], "r");

    if (!fcode) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }
    
    code = read_brainfuck(fcode);
    fclose(fcode);

    if(!validate(code)) {
        return EXIT_FAILURE;
    }

    if(!execute(code)) {
        free(code);
        return EXIT_FAILURE;
    }

    free(code);
    return EXIT_SUCCESS;
}
