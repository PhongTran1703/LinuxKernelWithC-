// kernel.cpp
extern "C" void kernel_main() {
    const char* str = "Hello from C++ kernel!";
    char* video = (char*)0xb8000;
    for (int i = 0; str[i] != '\0'; ++i) {
        video[i * 2] = str[i];
        video[i * 2 + 1] = 0x07; // white on black
    }
    while (1);
}
