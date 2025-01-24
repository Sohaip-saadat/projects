TN=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
OBJAS=$(AS:.s=.o)
PROJNAME=cortexM3
all: $(PROJNAME).bin
		@echo "============Build is done================"
INCS=
#if you use the startup.c file in project remove this section
startup.o: startup.s
		$(TN)as $(CFLAGS) $< -o $@
%.o: %.c 														# %الي قبلك و تعوض بيها هنا(dependes) يعني انك تيشل كل فايل من ال 
		$(TN)gcc -c $(CFLAGS)  $(INCS)  $< -o $@
$(PROJNAME).elf: $(OBJAS) $(OBJ) 
		$(TN)ld -T linker_Script.ld $(OBJ) $(OBJAS) $(LIBS) -o $@ -Map=Map_flie.map

$(PROJNAME).bin : $(PROJNAME).elf
		$(TN)objcopy -O binary $<  $@
clean_all: 
		rm *.elf *.bin *.o

clean: 
		rm *.elf *.bin