/*
 * virtual_joystick.c
 *
 *  Created on: 15.11.2021.
 *      Author: Branislav
 */

#include "virtual_joystick.h"
#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery.h"
#include "../../Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_ts.h"
#include "../Display/display.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	virtual_joystick_event_type event_type;
	bool needs_to_be_sent;
} events;

typedef struct
{
	uint16_t top;
	uint16_t bottom;
	uint16_t left;
	uint16_t right;
} constraint;

static events event_buffer[VJ_KEY_COUNT];

const constraint constraints[] = {

		[VJ_SCREEN_LEFT] = {
			.top    = 45,
			.bottom = 195,
			.left   = 0,
			.right  = 75
		},

		[VJ_SCREEN_RIGHT] = {
			.top    = 45,
			.bottom = 195,
			.left   = 245,
			.right  = 320
		},

		[VJ_SCREEN_UP] = {
			.top    = 0,
			.left   = 0,
			.bottom = 65,
			.right  = 320
		},

		[VJ_SCREEN_DOWN] = {
			.top    = 175,
			.bottom = 240,
			.left   = 0,
			.right  = 320
		},

		[VJ_SCREEN_CENTER] = {
			.top    = 45,
			.bottom = 195,
			.left   = 45,
			.right  = 275
		},
};

void virtual_joystick_init(void)
{
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_TS_Init(display_get_width(), display_get_height());
}

static inline void set_state(virtual_joystick_key key, virtual_joystick_event_type event_type)
{
	events* evt = &event_buffer[key];

	if(evt->needs_to_be_sent || evt->event_type == event_type)
	{
		return;
	}

	evt->event_type = event_type;
	evt->needs_to_be_sent = true;
}

static inline bool does_fit_constraint(uint16_t x, uint16_t y, const constraint* cstr)
{
	return (x >= cstr->left && x <= cstr->right) && (y >= cstr->top && y <= cstr->bottom);
}

static void check_ts(void)
{
	TS_StateTypeDef ts = {};
	BSP_TS_GetState(&ts);

	if(!ts.TouchDetected)
	{
		for(int i = VJ_SCREEN_UP; i <= VJ_SCREEN_CENTER; i++)
		{
			if(!event_buffer[i].needs_to_be_sent
					&& event_buffer[i].event_type == VJ_PRESSED)
			{
				event_buffer[i].event_type = VJ_RELEASED;
				event_buffer[i].needs_to_be_sent = true;
			}
		}

		return;
	}

	int temp = ts.X;
	ts.X = display_get_height() - ts.Y;
	ts.Y = temp;

	for(int i = 0; i < sizeof(constraints) / sizeof(constraints[0]); i++)
	{

		if(i >= VJ_SCREEN_UP
				&& i <= VJ_SCREEN_CENTER
				&& !event_buffer[i].needs_to_be_sent
				&& does_fit_constraint(ts.X, ts.Y, &constraints[i]))
		{
			event_buffer[i].event_type = VJ_PRESSED;
			event_buffer[i].needs_to_be_sent = true;

			return;
		}
	}
}

static inline void check_pb(void)
{
	uint32_t pb;

	pb = BSP_PB_GetState(BUTTON_KEY);

	set_state(VJ_PUSH_BUTTON, pb ? VJ_PRESSED : VJ_RELEASED);
}

void virtual_joystick_loop(void)
{
	check_ts();
	check_pb();
}

virtual_joystick_event virtual_joystick_get_event(void)
{
	virtual_joystick_event evt = {};
	int evt_idx = -1;

	for(int i = 0; i < VJ_KEY_COUNT; i++)
	{
		if(event_buffer[i].needs_to_be_sent)
		{
			evt_idx = i;
			break;
		}
	}

	if(evt_idx == -1)
	{
		return evt;
	}

	evt.event_type = event_buffer[evt_idx].event_type;
	evt.key = (virtual_joystick_key) evt_idx;

	event_buffer[evt_idx].needs_to_be_sent = false;

	return evt;
}
