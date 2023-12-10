/*
 * KBD_conf.h
 *
 *  Created on: Dec 9, 2023
 *      Author: khaled
 */

#ifndef KBD_CONF_H_
#define KBD_CONF_H_

#define KPD_PORT				DIO_u8PORTD
#define KBD_NO_PRESSED_KEY		0XFF

//#define KPD_ARR_VAL				{{7 , 8, 9 , '/'},{4 , 5 , '6' , '*'},{1 , 2 , 3 , '-'},{'?' , 0 , '=' , '+'}}
#define KPD_ARR_VAL				{{'7' , '8', '9' , '/'},{'4' , '5' , '6' , '*'},{'1' , '2' , '3' , '-'},{'?' , '0' , '=' , '+'}}

#define KPD_COL_1		DIO_u8PIN0
#define KPD_COL_2		DIO_u8PIN1
#define KPD_COL_3		DIO_u8PIN2
#define KPD_COL_4		DIO_u8PIN3

#define KPD_ROW_1		DIO_u8PIN4
#define KPD_ROW_2		DIO_u8PIN5
#define KPD_ROW_3		DIO_u8PIN6
#define KPD_ROW_4		DIO_u8PIN7

#endif /* KBD_CONF_H_ */
