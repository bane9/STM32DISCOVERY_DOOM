/*
 * filesystem.c
 *
 *  Created on: Nov 13, 2021
 *      Author: Branislav
 */

#include "filesystem.h"
#include <stdbool.h>
#include <stdio.h>
#include "usb_host.h"
#include "fatfs.h"
#include "main.h"

static FATFS fat_handle;

static bool is_connected = false;

void filesystem_init(void)
{
	while(!is_connected)
	{
		filesystem_loop();
	}
}

void filesystem_on_connect(void)
{
	FRESULT fr = f_mount(&fat_handle, "", 0);

	if(fr != FR_OK)
	{
		Error_Handler();
	}
	else
	{
		is_connected = true;
	}
}

void filesystem_on_disconnect(void)
{
	Error_Handler();
}

void filesystem_loop(void)
{
	MX_USB_HOST_Process();
}
