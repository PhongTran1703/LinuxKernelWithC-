#include "keyboard.h"

extern "C" void keyboard_handler();
extern "C" void load_idt(); // declared in inline assembly

__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
    0x1BADB002,              // magic
    0x0,                     // flags
    (unsigned int)(0 - 0x1BADB002)  // checksum = -(magic + flags)
};

extern "C" void kernel_main() {
    const char* str = "Hello from C++ kernel!";
    char* video = (char*)0xb8000;
    for (int i = 0; str[i] != '\0'; ++i) {
        video[i * 2] = str[i];
        video[i * 2 + 1] = 0x07; // white on black
    }

    // Initialize keyboard interrupt
    load_idt(); // load dummy IDT with handler at IRQ1
    asm volatile("sti");

    while (1);
}

