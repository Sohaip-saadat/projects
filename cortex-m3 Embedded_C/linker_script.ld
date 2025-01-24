/*
    linker_script for cortex-M32

    @@ Created by Eng.Sohaib saadat
*/


/*Init a Memory section*/
MEMORY
{
    flash(RX): ORIGIN = 0x80000000, LENGTH = 128k
    sram(RwX): ORIGIN = 0x20000000, LENGTH = 20k
}

/* Init a Sections section */

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = .;
    }> flash

    .data :
    {
        _S_data = .;
        *(.data)
        _E_data = .;
    }> sram AT> flash

    .bss :
    {
        _S_bss = .;
        *(.bss)
        _E_bss = .;
        . = . + 0x1000;
        _stack_top = .;
    }>sram
}