/*
 * display.c
 *
 *  Created on: Nov 13, 2021
 *      Author: Branislav
 */

#include "display.h"
#include "../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.h"
#include <stdlib.h>
#include "../umm_malloc/umm_malloc.h"

display_frame_buffer_t ST_Framebuffer = (display_frame_buffer_t) LCD_FRAME_BUFFER;

void display_init(void)
{
	uint32_t framebuffer_size;

	BSP_LCD_Init();

	framebuffer_size = display_get_width() * display_get_height() * sizeof(display_frame_base_t);

	BSP_LCD_LayerDefaultInit(0, (uint32_t) ST_Framebuffer);
	BSP_LCD_SelectLayer(0);
	BSP_LCD_SetLayerVisible(1, DISABLE);
	BSP_LCD_DisplayOn();

	for(int i = 0; i < framebuffer_size; i++)
	{
		char* p = (char*) ST_Framebuffer + i;
		*p = 0xff;
	}
}

display_frame_buffer_t display_get_framebuffer(void)
{
	return ST_Framebuffer;
}

uint16_t display_get_width(void)
{
	return BSP_LCD_GetXSize();
}

uint16_t display_get_height(void)
{
	return BSP_LCD_GetYSize();
}

uint16_t display_write_pixel_landscape(uint16_t x, uint16_t y, display_frame_base_t value)
{


	return BSP_LCD_GetYSize();
}
