extern "C" void kernel_main();

__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
    0x1BADB002,              // magic
    0x0,                     // flags
    (unsigned int)(0 - 0x1BADB002)  // checksum = -(magic + flags)
};

extern "C" void kernel_main() {
    const char* msg = "Welcome to your C++ kernel!";
    char* video = (char*)0xb8000;

    for (int i = 0; msg[i]; ++i) {
        video[i * 2] = msg[i];
        video[i * 2 + 1] = 0x07;
    }

    while (1);
}
