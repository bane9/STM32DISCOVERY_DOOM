/*
 * virtual_joystick.h
 *
 *  Created on: 15.11.2021.
 *      Author: Branislav
 */

#ifndef VIRTUAL_JOYSTICK_H_
#define VIRTUAL_JOYSTICK_H_

typedef enum
{
	VJ_KEY_NONE,
	VJ_PUSH_BUTTON,
	VJ_SCREEN_TOP_LEFT,
	VJ_SCREEN_TOP_RIGHT,
	VJ_SCREEN_BOTTOM_LEFT,
	VJ_SCREEN_BOTOM_RIGHT,
	VJ_SCREEN_UP,
	VJ_SCREEN_DOWN,
	VJ_SCREEN_LEFT,
	VJ_SCREEN_RIGHT,
	VJ_SCREEN_CENTER,

	VJ_KEY_COUNT
} virtual_joystick_key;

typedef enum
{
	VJ_EVENT_NONE,
	VJ_PRESSED,
	VJ_RELEASED,
} virtual_joystick_event_type;

typedef struct
{
	virtual_joystick_key key;
	virtual_joystick_event_type event_type;
} virtual_joystick_event;

void virtual_joystick_init(void);

void virtual_joystick_loop(void);

virtual_joystick_event virtual_joystick_get_event(void);

#endif /* VIRTUAL_JOYSTICK_H_ */
