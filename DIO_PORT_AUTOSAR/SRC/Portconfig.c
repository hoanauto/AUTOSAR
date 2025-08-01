/**********************************************************
 * @file    Port_cfg.c
 * @brief   Port Driver Configuration Source File
 * @details File này chứa phần hiện thực các tham số cấu hình 
 *          cho từng chân Port của driver Port theo chuẩn AUTOSAR,
 *          dùng cho STM32F103.
 *
 * @version 1.0
 * @date    2024-06-19
 * @author  HALA Academy & ChatGPT
 **********************************************************/

#include "Portconfig.h"

/**********************************************************
 * Cấu hình chi tiết cho từng chân GPIO
 * - PortNum:   PORT_ID_A, PORT_ID_B, PORT_ID_C, ...
 * - PinNum:    Số thứ tự chân trong port (0-15)
 * - Mode:      PORT_PIN_MODE_DIO, ...
 * - Direction: PORT_PIN_OUT / PORT_PIN_IN
 * - DirectionChangeable: 1 = Cho phép đổi chiều runtime
 * - Level:     PORT_PIN_LEVEL_HIGH / PORT_PIN_LEVEL_LOW
 * - Pull:      PORT_PIN_PULL_NONE / UP / DOWN
 * - ModeChangeable: 1 = Cho phép đổi mode runtime
 **********************************************************/

const Port_PinConfigType PortCfg_Pins[] = {
    /* PA0: DIO, Output, Được phép đổi chiều & mode runtime, mặc định HIGH, không pull */
    {
        .PortNum = PORT_ID_A,
        .PinNum = 0,
        .Mode = PORT_PIN_MODE_DIO,
        .Speed = PORT_SPEED_2Mhz, // Tốc độ 2MHz
        .Direction = PORT_PIN_OUT,
        .DirectionChangeable = 1,
        .Level = PORT_PIN_LEVEL_HIGH,
        .Pull = PORT_PIN_PULL_NONE,
        .ModeChangeable = 1
    },
    /* PA1: DIO, Input, Không đổi chiều, pull-up */
    {
        .PortNum = PORT_ID_A,
        .PinNum = 1,
        .Mode = PORT_PIN_MODE_PWM,
        .Speed = PORT_SPEED_50Mhz, // Tốc độ 10MHz
        .Direction = PORT_PIN_OUT,
        .DirectionChangeable = 0,
        .Level = PORT_PIN_LEVEL_LOW, /* Không ảnh hưởng nếu là input */
        .Pull = PORT_PIN_PULL_NONE,
        .ModeChangeable = 0
    },
    /* PB0: DIO, Output, Không đổi chiều, mặc định LOW, không pull */
    {
        .PortNum = PORT_ID_B,
        .PinNum = 0, 
        .Mode = PORT_PIN_MODE_DIO,
        .Speed = PORT_SPEED_50Mhz, // Tốc độ 50MHz
        .Direction = PORT_PIN_OUT,
        .DirectionChangeable = 0,
        .Level = PORT_PIN_LEVEL_LOW,
        .Pull = PORT_PIN_PULL_NONE,
        .ModeChangeable = 0
    },
    /* PC13: DIO, Input, Được phép đổi mode runtime, pull-down */
    {
        .PortNum = PORT_ID_C,
        .PinNum = 13,
        .Mode = PORT_PIN_MODE_DIO,
        .Speed = PORT_SPEED_2Mhz, // Tốc độ 2MHz
        .Direction = PORT_PIN_OUT,
        .DirectionChangeable = 1,
        .Level = PORT_PIN_LEVEL_LOW,
        .Pull = PORT_PIN_PULL_NONE,
        .ModeChangeable = 1
    },
    {
        .PortNum              = PORT_ID_A,
        .PinNum               = 3,
        .Mode                 = PORT_PIN_MODE_PWM,    
        .Speed                = PORT_SPEED_10Mhz, // Tốc độ 2MHz
        .Direction            = PORT_PIN_OUT,
        .DirectionChangeable  = 0,
        .Level                = PORT_PIN_LEVEL_LOW,      // Không quan trọng với AF_PP
        .Pull                 = PORT_PIN_PULL_NONE,
        .ModeChangeable       = 0
    },
    /* PA7 - TIM3_CH2 - PWM Output */
    {
        .PortNum              = PORT_ID_A,
        .PinNum               = 7,
        .Mode                 = PORT_PIN_MODE_PWM,    // Alternate Function Push-Pull
        .Speed                = PORT_SPEED_50Mhz, // Tốc độ 2MHz
        .Direction            = PORT_PIN_OUT,
        .DirectionChangeable  = 0,
        .Level                = PORT_PIN_LEVEL_LOW,
        .Pull                 = PORT_PIN_PULL_NONE,
        .ModeChangeable       = 0
    }
};
//const uint64 PortCfg_PinsCount = sizeof(PortCfg_Pins) / sizeof(Port_PinConfigType);