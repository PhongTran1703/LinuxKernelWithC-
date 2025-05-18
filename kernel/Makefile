CXX = i686-linux-gnu-g++
LD = i686-linux-gnu-ld
CXXFLAGS = -ffreestanding -m32 -nostdlib -fno-exceptions -fno-rtti
LDFLAGS = -T linker.ld -m elf_i386

ISO = os.iso
KERNEL = kernel.bin

all: $(ISO)

$(KERNEL): kernel.cpp
	$(CXX) $(CXXFLAGS) -c kernel.cpp -o kernel.o
	$(LD) $(LDFLAGS) -o $(KERNEL) kernel.o

$(ISO): $(KERNEL)
	mkdir -p isodir/boot/grub
	cp $(KERNEL) isodir/boot/kernel.bin
	cp grub/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) isodir

run: $(ISO)
	qemu-system-i386 -cdrom $(ISO)

clean:
	rm -rf *.o *.bin isodir $(ISO)

