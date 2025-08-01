#include "stm32f10x_rcc.h"          
#include "stm32f10x.h"       
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"  
#include "Dio.h"
#include "Port.h"
#include "Portconfig.h"
#include "Pwm.h"
#include "Pwm_Lcfg.h"


void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 8000; i++) __NOP();
}
uint16_t duty =0;
int main() {
	    Port_ConfigType portConfig = {
        .PinConfigs = PortCfg_Pins, // con trỏ trỏ tới mảng config
       .PinCount = PortCfg_PinsCount // gán số lượng phần tử trong mảng
    };
    Port_Init(&portConfig);

	Pwm_Init(&PwmDriverConfig);
 /* Bật ngắt cạnh lên của PWM cho kênh 0 nếu cần thiết */
    Pwm_EnableNotification(0, PWM_RISING_EDGE);

    /* Đặt duty cycle 50% cho kênh PWM 0 */
    //Pwm_SetDutyCycle(0, 0x4000);

	while (1) {
		 /* Thay đổi độ rộng xung PWM theo thời gian */
         if (duty < 0x8000){
        for (duty = 0; duty < 0x8000; duty += 0x0800) {
            Pwm_SetDutyCycle(0, duty);
       delay_ms(50); // Đợi 500ms
        }}
        else { for (duty = 0; duty > 0x8000; duty -= 0x0800) {
            Pwm_SetDutyCycle(0, duty);
       delay_ms(30); 
      }
	//Port_SetPinDirection(3, PORT_PIN_IN); // Đặt chân C13 là OUTPUT
	DIO_FlipChannel(DIO_CHANNEL(GPIOC, 13)); 
    delay_ms(30);
	//Port_RefreshPortDirection(); // Làm tươi lại chiều các chân không cho đổi runtime
	//delay_ms(500); // Đợi 500ms
    }
}}


