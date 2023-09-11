//
// Created by AaronR92 on 9/10/2023.
//

#include "../../interface/print.h"
#include "../../interface/vga.h"

extern "C" void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str_newline("Welcome to AuroraOS!");
}
