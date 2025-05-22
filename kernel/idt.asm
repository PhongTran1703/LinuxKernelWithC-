[bits 32]

section .text
global load_idt
global _keyboard_stub

; IRQ1 handler (Keyboard)
_keyboard_stub:
    pusha
    call keyboard_handler
    popa
    iretd

load_idt:
    lidt [idt_descriptor]
    ret

section .data

; Split _keyboard_stub into low and high 16-bit manually using labels
_stub_offset_low:
    dw 0                ; placeholder
_stub_selector:
    dw 0x08             ; code segment selector
_stub_zero:
    db 0
_stub_type:
    db 0x8E             ; present, DPL=0, 32-bit interrupt gate
_stub_offset_high:
    dw 0                ; placeholder

idt:
    ; Manually copy the full entry
    ; This layout builds a 64-bit IDT entry
    ; Must match the order: offset_low, selector, zero, type, offset_high
    incbin "stub.bin"

idt_end:

idt_descriptor:
    dw idt_end - idt - 1
    dd idt
