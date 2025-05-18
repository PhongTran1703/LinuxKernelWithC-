# Makefile

all: os-image

bootloader.bin: bootloader.asm
	nasm -f bin bootloader.asm -o bootloader.bin

kernel.o: kernel.cpp
	i686-elf-g++ -ffreestanding -m32 -c kernel.cpp -o kernel.o

kernel.bin: kernel.o linker.ld
	i686-elf-ld -T linker.ld -o kernel.bin -m elf_i386 kernel.o

os-image: bootloader.bin kernel.bin
	cat bootloader.bin kernel.bin > os-image

run: os-image
	qemu-system-i386 -fda os-image
