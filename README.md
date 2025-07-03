# Autosar newbie
📦 AUTOSAR Drivers for STM32F103 (SPL-based)
This project implements basic AUTOSAR-compliant MCAL modules for STM32F103 using the Standard Peripheral Library (SPL). Developed and built in VS Code with Makefile and arm-none-eabi-gcc.

✅ Implemented Modules
 - DIO	Digital Input/Output: Read/Write single pins, ports, and channel groups.
- PORT	Pin configuration: Mode, Direction, Pull, and Runtime configurability.
- PWM	Pulse Width Modulation driver using TIM peripherals (supports duty cycle, period, idle state, and notifications).

🔧 Development Tools
- IDE: Visual Studio Code
- Compiler: arm-none-eabi-gcc (GCC for ARM Cortex-M)
- MCU: STM32F103C8T6
- Peripheral Library: STM32 SPL (Standard Peripheral Library)
- Build system: Custom Makefile

📁 Project Structure
```c
├── INC/                  # Header files (.h)
│   ├── Dio.h
│   ├── Port.h
│   ├── Pwm.h
│   ├── Dio_Cfg.h
│   └── Pwm_Lcfg.h
├── SRC/                  # Source files (.c)
│   ├── Dio.c
│   ├── Port.c
│   ├── Pwm.c
│   ├── main.c
├── STARTUP/              # Linker script & startup assembly
│   ├── startup_stm32f10x_md.s
│   └── linker.ld
├── LIB/                  # STM32 SPL libraries
├── makefile              # Build script for VSCode terminal
└── README.md             # This file

▶️ How to Build
Make sure you have arm-none-eabi-gcc in your PATH.

# Clean old builds
make clean

# Compile and link the project
make build
Output ELF file will be generated in the BUILD/ directory.

🔌 Flashing to MCU
Use any STM32 flashing tool (e.g., ST-Link Utility, OpenOCD, STM32CubeProgrammer) to flash BUILD/test.elf or convert it to .hex/.bin.

✍️ Author
Developed by HALA Academy student as a personal embedded software project practicing AUTOSAR Layered Architecture.

