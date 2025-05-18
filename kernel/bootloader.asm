; bootloader.asm (512 bytes MBR)
BITS 16
ORG 0x7C00

mov si, message
call print_string
jmp $

print_string:
    mov ah, 0x0E
.loop:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .loop
.done:
    ret

message db "Booting C++ Kernel...", 0

times 510 - ($ - $$) db 0
dw 0xAA55  ; Boot signature
