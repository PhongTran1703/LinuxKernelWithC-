<<<<<<< HEAD
# Cross compiler tools
CXX = i686-linux-gnu-g++
LD = i686-linux-gnu-ld
NASM = nasm
=======
# Makefile for simple C++ kernel using i686-linux-gnu-g++

# Tools
AS = nasm
CXX = i686-linux-gnu-g++
LD = i686-linux-gnu-ld
>>>>>>> parent of 9ca7420... worked init version

# Flags
CXXFLAGS = -ffreestanding -m32 -nostdlib -fno-exceptions -fno-rtti
LDFLAGS = -m elf_i386 -T linker.ld

<<<<<<< HEAD
# File names
ISO = os.iso
KERNEL = kernel.bin
OBJS = kernel.o keyboard.o idt.o

# Default target
all: $(ISO)

# Build kernel object files
kernel.o: kernel.cpp
	$(CXX) $(CXXFLAGS) -c kernel.cpp -o kernel.o

keyboard.o: keyboard.cpp
	$(CXX) $(CXXFLAGS) -c keyboard.cpp -o keyboard.o

idt.o: idt.asm
	$(NASM) -f elf32 idt.asm -o idt.o

# Link kernel binary
$(KERNEL): $(OBJS)
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJS)

# Create GRUB bootable ISO
$(ISO): $(KERNEL)
	mkdir -p isodir/boot/grub
	cp $(KERNEL) isodir/boot/kernel.bin
	cp grub/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) isodir
=======
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
>>>>>>> parent of 9ca7420... worked init version

# Run kernel in QEMU
run: $(ISO)
	qemu-system-i386 -fda $(ISO)

# Clean up build files
clean:
<<<<<<< HEAD
	rm -rf *.o *.bin *.iso isodir
=======
	rm -f $(KERNEL_OBJ) $(KERNEL) $(BOOTLOADER) $(ISO)

>>>>>>> parent of 9ca7420... worked init version
