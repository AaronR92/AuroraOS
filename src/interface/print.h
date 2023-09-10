//
// Created by AaronR92 on 9/10/2023.
//

#ifndef AURORAOS_PRINT_H
#define AURORAOS_PRINT_H

typedef unsigned char uint8_t;

extern "C" {

    void print_clear();
    void print_char(char character);
    void print_str(const char* str);
    void print_set_color(uint8_t foreground, uint8_t background);

};


#endif //AURORAOS_PRINT_H
