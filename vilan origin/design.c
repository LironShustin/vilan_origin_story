#include <stdio.h>
#include "design.h"

const char* RED = "\033[1;31m";
const char* YELLOW = "\033[1;33m";
const char* ORANGE = "\033[38;5;208m";
const char* BLUE = "\033[1;34m";
const char* GREEN = "\033[1;32m";
const char* CYAN = "\033[1;36m";
const char* PURPLE = "\033[0;35m";
const char* PINK = "\033[1;35m";
const char* RESET = "\033[0m";

void print_colored(const char* text, const char* color_code) {
    printf("%s%s\033[0m", color_code, text);
}