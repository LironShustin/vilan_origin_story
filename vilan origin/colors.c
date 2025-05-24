#include "colors.h"
#include <stdio.h>
#include <windows.h>

void print_colored_rgb(const char* text, int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m", r, g, b, text);
}
