#include "stm32f10x_rcc.h"          
#include "stm32f10x.h"       
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"  
#include "DIO.h"
#include "Port.h"
#include "Port_cfg.h"
void RCC_Config()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
}

void TIM_Config()
{
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	
	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_Prescaler = 7200 - 1;
	TIM_InitStruct.TIM_Period = 0xFFFF;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM2,&TIM_InitStruct);
	TIM_Cmd(TIM2,ENABLE);
}

void delay_ms(uint32_t time)
{
	TIM_SetCounter(TIM2,0);
	while(TIM_GetCounter(TIM2)< time * 10) {}
}


int hala() {
	RCC_Config(); // Cấu hình RCC cho TIM2
	    Port_ConfigType portConfig = {
        .PinConfigs = PortCfg_Pins,
        .PinCount = PortCfg_PinsCount
    };
    Port_Init(&portConfig);
	TIM_Config();
	while (1) {
	Port_SetPinDirection(3, PORT_PIN_IN); // Đặt chân C13 là OUTPUT
	//DIO_FlipChannel(DIO_CHANNEL_C13); // Đảo trạng thái chân PA0
	//Port_RefreshPortDirection();
	Port_RefreshPortDirection(); // Làm tươi lại chiều các chân không cho đổi runtime
	delay_ms(500); // Đợi 500ms
    }
}


