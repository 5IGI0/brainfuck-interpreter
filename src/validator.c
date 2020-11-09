#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t validate(char *code) {
    size_t codeSize = strlen(code);
    size_t loopDeep = 0;

    for (size_t i = 0; i < codeSize; i++) {
        
        if (code[i] == '[')
            loopDeep++;
        else if (code[i] == ']') {
            if (loopDeep == 0) {
                fputs("unexisting loop closed!\n", stderr);
                return 0;
            } 
            loopDeep--;
        }
    }
    
    if (loopDeep != 0) {
        fprintf(stderr, "%lu loop(s) unclosed!\n", (long unsigned int)loopDeep);
        return 0;
    }

    return 1;
}