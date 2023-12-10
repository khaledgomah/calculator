/*
 * KBD_int.h
 *
 *  Created on: Dec 9, 2023
 *      Author: khaled
 */

#ifndef KBD_INT_H_
#define KBD_INT_H_

void KPD_Init(void) ;

u8 KBD_u8_grtPressedkey(void);


#define KBD_NO_PRESSED_KEY		0xff
#endif /* KBD_INT_H_ */
