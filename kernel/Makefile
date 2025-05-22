# Cross compiler tools
CXX = i686-linux-gnu-g++
LD = i686-linux-gnu-ld
NASM = nasm

# Flags
CXXFLAGS = -ffreestanding -m32 -nostdlib -fno-exceptions -fno-rtti
LDFLAGS = -T linker.ld -m elf_i386

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

# Run kernel in QEMU
run: $(ISO)
	qemu-system-i386 -cdrom $(ISO)

# Clean up build files
clean:
	rm -rf *.o *.bin *.iso isodir
