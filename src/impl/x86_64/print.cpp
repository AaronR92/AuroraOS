//
// Created by AaronR92 on 9/10/2023.
//

#include "../../interface/print.h"
#include "../../interface/vga.h"
#include "stdint.h"

#include "stddef.h"

extern "C" {


    const static size_t NUM_COLS = 80;
    const static size_t NUM_ROWS = 25;


    struct char_t {
        uint8_t character;
        uint8_t color;
    };

    struct char_t* buff = (struct char_t*) 0xb8000;
    size_t col = 0;
    size_t row = 0;
    uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

    void clear_row(size_t row) {
        struct char_t empty = {
            .character = ' ',
            .color = color
        };

        for (int i = 0; i < NUM_COLS; i++) {
            buff[i + NUM_COLS * row] = empty;
        }
    }

    void print_clear() {
        for (size_t i = 0; i < NUM_ROWS; i++) {
            clear_row(i);
        }
    }

    void print_newline() {
        col = 0;

        if (row < NUM_ROWS - 1) {
            row++;
            return;
        }

        for (int row = 1; row < NUM_ROWS; row++) {
            for (int col = 0; col < NUM_COLS; col++) {
                struct char_t character = buff[col + NUM_COLS * row];
                buff[col + NUM_COLS * (row - 1)] = character;
            }
        }

        clear_row(NUM_COLS - 1);
    }

    void print_char(char character) {
        if (character == '\n') {
            print_newline();
            return;
        }

        if (col > NUM_COLS) {
            print_newline();
        }

        buff[col + NUM_COLS * row] = (struct char_t) {
                .character = (uint8_t) character,
                .color = color
        };

        col++;
    }

    void print_str(const char* str) {
        const char *ptr = str;

        while (*ptr)
        {
          print_char(*ptr);
          ++ptr;
        }
    }

    void print_set_color(uint8_t foreground, uint8_t background) {
        color = foreground + (background << 4);
    }

}
