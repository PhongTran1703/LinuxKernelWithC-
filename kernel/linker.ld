ENTRY(kernel_main)

SECTIONS {
    . = 1M;

    .multiboot : {
        KEEP(*(.multiboot))
    }

    .text : {
        *(.text)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}
