# Tools
AS = nasm
CXX = i686-linux-gnu-g++
LD = i686-linux-gnu-ld

# Flags
CXXFLAGS = -ffreestanding -m32 -nostdlib -fno-exceptions -fno-rtti
LDFLAGS = -m elf_i386 -T linker.ld

# Files
KERNEL = kernel.bin
ISO = os.iso
BOOTLOADER = bootloader.bin
OBJS = kernel.o keyboard.o idt.o

# Default target
all: $(ISO)

# Build object files
kernel.o: kernel.cpp
	$(CXX) $(CXXFLAGS) -c kernel.cpp -o kernel.o

keyboard.o: keyboard.cpp
	$(CXX) $(CXXFLAGS) -c keyboard.cpp -o keyboard.o

idt.o: idt.asm
	$(AS) -f elf32 idt.asm -o idt.o

# Link kernel binary
$(KERNEL): $(OBJS)
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJS)

# Create GRUB bootable ISO
$(ISO): $(KERNEL)
	mkdir -p isodir/boot/grub
	cp $(KERNEL) isodir/boot/kernel.bin
	cp grub/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) isodir

# Optional: If you're using a flat bootloader
$(BOOTLOADER): bootloader.asm
	$(AS) -f bin bootloader.asm -o $(BOOTLOADER)

# Alternative ISO using bootloader (if not using GRUB)
flat-iso: $(BOOTLOADER) $(KERNEL)
	cat $(BOOTLOADER) $(KERNEL) > os-image

# Run kernel in QEMU
run: $(ISO)
	qemu-system-i386 -fda $(ISO)

# Clean up build files
clean:
	rm -rf *.o *.bin *.iso isodir os-image $(BOOTLOADER)
