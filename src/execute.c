#include <stdio.h>
#include <stdint.h>

#include "defines.h"

static void skip_loop(char *code, size_t *i) {
    size_t deep = 0;

    i[0]++;
    for (; code[*i] != ']' || deep != 0; i[0]++) {
        switch (code[*i]) {
            case '[': deep++; break;
            case ']': deep--; break;
            default:break;
        }
    }
}

static void loop_back(char *code, size_t *i) {
    size_t deep = 0;

    i[0]--;
    for (; code[*i] != '[' || deep != 0; i[0]--) {
        switch (code[*i]) {
            case '[': deep--; break;
            case ']': deep++; break;
            default:break;
        }
    }
}

uint8_t execute(char *code) {
    char chr = 0;
    uint16_t ptr = PTR_START_AT;
    CELL_TYPE values[BUFFER_SIZE] = {0};

    for (size_t i = 0; code[i] != 0; i++) {
        chr = code[i];
        switch (chr) {
            case '+': values[ptr]++; break;
            case '-': values[ptr]--; break;
            case '<': 
                if (ptr==0) {
                    fputs("\nthe pointer has overtaken the pointer on the left side!\n", stderr);
                    return 1;
                }
                ptr--;
                break;
            case '>':
                if (ptr==BUFFER_SIZE-1) {
                    fputs("\nthe pointer has overtaken the pointer on the right side!\n", stderr);
                    return 1;
                }
                ptr++;
                break;
            case '.': putc(values[ptr], stdout); break;
            case ',': printf("%d", values[ptr]); break;
            case '[': if(values[ptr] == 0) skip_loop(code, &i); break;
            case ']': if(values[ptr] != 0) loop_back(code, &i); break;
            default:break;
        }
    }

    putc('\n', stdout);

    return 0;
}