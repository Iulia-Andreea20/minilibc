#include "../include/internal/io.h"
#include"../include/stdio.h"

#define STDOUT_FILENO 1
int puts(const char* str) {
    int count = 0;
    while (*str != '\0') {
        if (write(STDOUT_FILENO, str, 1) == -1) {
            return -1;
        }
        str++;
        count++;
    }
    if (write(STDOUT_FILENO, "\n", 1) == -1) {
        return -2;
    }
    count++;
    return count;
}