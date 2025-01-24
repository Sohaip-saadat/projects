Embedded System Project: ARM Cortex-M3 Startup and Build System
Project Overview
This project is designed for an ARM Cortex-M3 microcontroller and focuses on initializing the CPU and memory. The project includes the following components:

##### Startup Code:
A startup.s file that defines the vector table and handles the low-level initialization.
A startup.c file for initializing the data section (copying from flash to RAM) and clearing the BSS section in RAM.

##### Linker Script:
A custom linker script (linker.ld) to define memory regions for flash, RAM, and various sections (.text, .data, .bss, etc.).

#### Build System :
A Makefile to automate the compilation, linking, and generation of the final binary file.

#### Features ######
1. Startup Code (startup.s and startup.c)
Vector Table:
Defines the interrupt vector table in assembly.
Links the Reset Handler and other exception handlers to the appropriate function addresses.
Memory Initialization:
Copies the .data section from flash to RAM.
Initializes the .bss section (sets all uninitialized variables to 0).
Provides a basic implementation for the Reset Handler.

#### Linker Script (linker.ld) #######
Defines memory regions for:
Flash: Stores the program code and initialized data.
RAM: Used for the stack, .data, and .bss sections.
Maps sections like .text, .data, and .bss to their appropriate memory regions.
##### Makefile ######
Automates the build process, including:
Compiling source files (.c and .s).
Linking the object files using the custom linker script.
Generating an ELF file and converting it to a binary file for flashing onto the microcontroller.

##### How to Build the Project #####
Prerequisites:

Install gcc-arm-none-eabi (ARM GCC toolchain).
Install make if it's not already available.
Build Instructions: Run the following command in the project directory:

bash
make ## to build the project ###
make clean ##  to rm *.elf *.bin files ##
make clean_all ##  to rm *.elf *.bin *.o files ##


