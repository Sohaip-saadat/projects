Overview
This project aims to set up a startup file to initialize the stack pointer before transitioning to the main function. The project includes a linker script to define the locations of sections in flash memory and a make file to link all files, performing compilation, assembling, and final linking operations. The ultimate goal is to send data over UART using the VersatilePB board.

Components
startup.s: Assembly file that initializes the stack pointer and jumps to the main function.

linker script: Defines the locations of sections in flash memory.

make file: Links all files and performs compiling, assembling, and linking operations.

Steps
Set up the startup.s file to initialize the stack pointer and transition to the main function.

Write the linker script to appropriately define the locations of sections in flash memory.

Set up the make file to link all files, perform compiling, assembling, and final linking operations.

Send data over UART using the VersatilePB board.

How to Use
To build the project, follow these steps:

Open the command line and navigate to the project directory.

Run the following command:

bash
$make

Once the build is complete, you can load the program onto the board and send data over UART.