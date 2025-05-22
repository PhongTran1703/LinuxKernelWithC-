#include "keyboard.h"

extern "C" void keyboard_handler();
extern "C" void load_idt(); //declared in inline assembly

extern "C" void kernel_main();

__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
    0x1BADB002,              // magic
    0x0,                     // flags
    (unsigned int)(0 - 0x1BADB002)  // checksum = -(magic + flags)
};


extern "C" void kernel_main() {
    const char* msg = "Hello from your C++ kernel!";
    char* video = (char*)0xb8000;

    for (int i = 0; msg[i]; ++i) {
        video[i * 2] = msg[i];
        video[i * 2 + 1] = 0x07;
    }

    //Inittialize keyboard interrupt
    load_idt(); //load dummy IDT with handler at IRQ1
    asm volatile("sti");


    while (1);
}

