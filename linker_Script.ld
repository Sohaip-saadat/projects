ENTRY(reset)

MEMORY
{
    Flash (rwx): ORIGIN = 0x00000000, LENGTH = 64M 
}

SECTIONS
{
    . = 0x10000;
    .startup . :
    {
        startup.o(.text)
    }> Flash
    .text :
    {
        *(.text)
    }> Flash
    .data :
    {
        *(.data)
    }> Flash
    .bss :
    {
        *(.bss)
    }> Flash

    . = . + 0x1000;
    stackPointer = .;
}