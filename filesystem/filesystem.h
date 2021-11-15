/*
 * filesystem.h
 *
 *  Created on: Nov 13, 2021
 *      Author: Branislav
 */

#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

void filesystem_init(void);

void filesystem_on_connect(void);

void filesystem_on_disconnect(void);

void filesystem_loop(void);

#endif /* FILESYSTEM_H_ */
