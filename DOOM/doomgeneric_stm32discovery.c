#include "doomgeneric.h"
#include "doomkeys.h"
#include "main.h"
#include "../VirtualJoystick/virtual_joystick.h"
#include "doomtype.h"

void DG_Init()
{
	virtual_joystick_init();
}

void DG_DrawFrame()
{

}

void DG_SleepMs(uint32_t ms)
{
	HAL_Delay(ms);
}

uint32_t DG_GetTicksMs()
{
	return HAL_GetTick();
}


int DG_GetKey(int* pressed, unsigned char* key)
{
	extern boolean	menuactive;
	virtual_joystick_event evt;

	evt = virtual_joystick_get_event();

	if(evt.key == VJ_KEY_NONE)
	{
		return 0;
	}

	switch(evt.key)
	{
	case VJ_PUSH_BUTTON:
	{
		if(menuactive)
		{
			*key = KEY_ENTER;
		}
		else
		{
			*key = KEY_FIRE;
		}

		break;
	}
	case VJ_SCREEN_UP:
	{
		*key = KEY_UPARROW;
		break;
	}
	case VJ_SCREEN_DOWN:
	{
		*key = KEY_DOWNARROW;
		break;
	}
	case VJ_SCREEN_LEFT:
	{
		*key = KEY_LEFTARROW;

		break;
	}
	case VJ_SCREEN_RIGHT:
	{
		*key = KEY_RIGHTARROW;
		break;
	}
	case VJ_SCREEN_CENTER:
	{
		if(menuactive)
		{
			*key = KEY_ENTER;
		}
		else
		{
			*key = KEY_USE;
		}
		break;
	}
	default:
	{
		return 0;
	}
	}

	*pressed = evt.event_type == VJ_PRESSED;

	return 1;
}

void DG_SetWindowTitle(const char * title)
{

}
