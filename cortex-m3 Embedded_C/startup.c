#include <stdint.h>

/*Remove this file from a project if you will use a startup.s*/

// extern symbols init
extern int main(void);
extern uint32_t _stack_top; // init sp

// Interrupt vector tables
void default_handler();
void Reset_Handler();
void Hard_Fault() __attribute__((weak, alias("default_handler")));
void Bus_Faultr() __attribute__((weak, alias("default_handler")));
void NMI_Fault() __attribute__((weak, alias("default_handler")));
void Usage_Fault() __attribute__((weak, alias("default_handler")));

// memory boundry
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

// Vetctor section  this section will be start at address 0x80000000 in flash
uint32_t vectors[] __attribute__((section(".vectors"))) =
    {
        (uint32_t)&_stack_top,
        (uint32_t)&Reset_Handler,
        (uint32_t)&Hard_Fault,
        (uint32_t)&NMI_Fault,
        (uint32_t)&Bus_Faultr,
        (uint32_t)&Usage_Fault,
};

void default_handler()
{
    Reset_Handler();
}

// implementation of reset handler
void Reset_Handler()
{
    // Initialize the .data section to tansfare form flash to ram
    uint32_t data_size = (uint32_t)&_S_data - (uint32_t)&_E_data;
    uint8_t *src = (uint8_t *)_E_text;
    uint8_t *dest = (uint8_t *)_S_data;
    for (int32_t i = 0; i < data_size; i++)
    {
        *dest++ = *src++;
    }

    // Clear the .bss section
    uint32_t bss_size = (uint32_t)&_S_bss + (uint32_t)&_E_bss;
    dest = (uint8_t *)_S_data;
    for (uint32_t i; i < bss_size; i++)
    {
        *dest++ = 0;
    }

    main();
}