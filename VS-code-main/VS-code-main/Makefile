# Tool chain
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as

#Flags
CFLAGS = -mcpu=cortex-m3 -mthumb  -std=c11 -Wall -g -O0 \
	-IINC \
	-ILIB \
	-DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER \

LDFLAGS = -Tlinker.ld -nostartfiles -Wl,--gc-sections
LIBS = -lm -lc

# Source files
SRC = $(wildcard SRC/*.c)

STARTUP = STARTUP/startup_stm32f10x_md.s

OBJ = $(SRC:.c=.o) $(STARTUP:.s=.o)
OUT = BUILD/test.elf

#Rules
build : $(OUT)
$(OUT) : $(OBJ)
	@mkdir -p BUILD
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)
clean :
	rm -rf SRC/*.o LIB/SPL/src/*.o BUILD STARTUP/*.o 
Flash : $(OUT)
	openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program $(OUT) verify reset exit"