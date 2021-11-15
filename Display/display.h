/*
 * display.h
 *
 *  Created on: Nov 13, 2021
 *      Author: Branislav
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

typedef uint16_t* display_frame_buffer_t;
typedef uint16_t  display_frame_base_t;

void display_init(void);

display_frame_buffer_t display_get_framebuffer(void);

uint16_t display_get_width(void);

uint16_t display_get_height(void);


#endif /* DISPLAY_H_ */
