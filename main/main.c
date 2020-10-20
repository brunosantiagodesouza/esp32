#include <stdio.h>                //inclui biblioteca stdio que comporta printf 
#include <freertos/FreeRTOS.h>	  //inclui FreeRTOS
#include "soc/gpio_reg.h"		  // inclui biblioteca soc que habilita o trabalho com registradores	
#include "freertos/task.h"		  // inclui biblioteca task que permite usar delay 


void app_main(void)
{
	uint32_t result;
 
  	(*(volatile uint32_t *)GPIO_ENABLE_REG) = 0x02000000;  // habilita a gpio 25 como output pelo registrador  
  	while(1){
		result =REG_READ(GPIO_IN_REG) & BIT10; // ler todos bits do registrador GPIO_IN_REG
		if(result == BIT10){	  
		
			(*(volatile uint32_t *)GPIO_OUT_W1TS_REG) = 0x02000000; // set gpio 25 
			printf("led on \n");									
			vTaskDelay(2000/portTICK_PERIOD_MS);					// Delay de 2000 ms		
			(*(volatile uint32_t *)GPIO_OUT_W1TC_REG) = 0x02000000; // reset  gpio 25
			printf("led off \n");
			vTaskDelay(2000/portTICK_PERIOD_MS);
		}
	
	printf("LED OFF \n");
 	}

}