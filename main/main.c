#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "soc/gpio_reg.h"
#include "freertos/task.h"
#include "esp_log.h"

void app_main(void)
{
  (*(volatile uint32_t *)GPIO_ENABLE_REG) = 0x02000000;
 while(1){
  	(*(volatile uint32_t *)GPIO_OUT_W1TS_REG) = 0x02000000; //access register 
  	printf("led on \n");
  	vTaskDelay(2000/portTICK_PERIOD_MS);
  	(*(volatile uint32_t *)GPIO_OUT_W1TC_REG) = 0x02000000;
  	printf("led off \n");
	vTaskDelay(2000/portTICK_PERIOD_MS);
 }

}