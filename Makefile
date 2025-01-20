TN=arm-none-eabi-
CFLAGS= -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OPJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
OPJAS=$(AS:.s=.o)
PROJNAME=uart_config
all: $(PROJNAME).bin
		@echo "============Build is done================"
INCS=
startup.o: startup.s
		$(TN)as $(CFLAGS) $< -o $@
%.o: %.c 														# %الي قبلك و تعوض بيها هنا(dependes) يعني انك تيشل كل فايل من ال 
		$(TN)gcc -c $(CFLAGS)  $(INCS)  $< -o $@
$(PROJNAME).elf: $(OPJAS) $(OPJ) 
		$(TN)ld -T linker_Script.ld app.o uart.o startup.o -o $@ -Map=Map_flie.map

$(PROJNAME).bin : $(PROJNAME).elf
		$(TN)objcopy -O binary $<  $@
clean_all: 
		rm *.elf *.bin *.o

clean: 
		rm *.elf *.bin