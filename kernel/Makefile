# Makefile for simple C++ kernel using i686-linux-gnu-g++

# Tools
AS = nasm
CXX = i686-linux-gnu-g++
LD = i686-linux-gnu-ld

# Flags
CXXFLAGS = -ffreestanding -m32 -nostdlib -fno-exceptions -fno-rtti
LDFLAGS = -m elf_i386 -T linker.ld

# Files
KERNEL = kernel.bin
ISO = os-image
BOOTLOADER = bootloader.bin
KERNEL_OBJ = kernel.o

# Targets
all: $(ISO)

$(BOOTLOADER): bootloader.asm
	$(AS) -f bin $< -o $@

$(KERNEL_OBJ): kernel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(KERNEL): $(KERNEL_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

$(ISO): $(BOOTLOADER) $(KERNEL)
	cat $(BOOTLOADER) $(KERNEL) > $@

run: $(ISO)
	qemu-system-i386 -fda $(ISO)

clean:
	rm -f $(KERNEL_OBJ) $(KERNEL) $(BOOTLOADER) $(ISO)

