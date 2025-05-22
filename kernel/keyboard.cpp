// keyboard.cpp

#include "keyboard.h"
#include <stdint.h>

#define PORT_DATA 0x60
#define PORT_CMD  0x64

static const char scancode_map[128] = {
    0,  27, '1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0, '\\',
    'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' ',
    // rest are empty
};

static void print_char(char c) {
    static int row = 0, col = 0;
    char* video = (char*)0xb8000;
    int index = (row * 80 + col) * 2;
    video[index] = c;
    video[index + 1] = 0x07;

    col++;
    if (col >= 80) {
        col = 0;
        row++;
    }
}

extern "C" void keyboard_handler() {
    uint8_t scancode = inb(PORT_DATA);
    if (scancode & 0x80) {
        // key release — ignore
    } else {
        char c = scancode_map[scancode];
        if (c) {
            print_char(c);
        }
    }

    // Send end-of-interrupt (EOI) to PIC
    outb(0x20, 0x20);
}
