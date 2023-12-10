/*
 * KBD_prog.c
 *
 *  Created on: Dec 9, 2023
 *      Author: khaled
 */
#include "errorState.h"
#include "STD_TYPES.h"

#include "DIO_int.h"

#include "KBD_conf.h"
#include "KBD_priv.h"

void KPD_Init(void) {

	DIO_enuSetPinDirection(KPD_PORT, KPD_ROW_1, DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_PORT, KPD_ROW_2, DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_PORT, KPD_ROW_3, DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_PORT, KPD_ROW_4, DIO_u8INPUT);

	DIO_enuSetPintValue(KPD_PORT, KPD_ROW_1, DIO_u8PULL_UP);
	DIO_enuSetPintValue(KPD_PORT, KPD_ROW_2, DIO_u8PULL_UP);
	DIO_enuSetPintValue(KPD_PORT, KPD_ROW_3, DIO_u8PULL_UP);
	DIO_enuSetPintValue(KPD_PORT, KPD_ROW_4, DIO_u8PULL_UP);

	DIO_enuSetPinDirection(KPD_PORT, KPD_COL_1, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_PORT, KPD_COL_2, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_PORT, KPD_COL_3, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_PORT, KPD_COL_4, DIO_u8OUTPUT);

	DIO_enuSetPintValue(KPD_PORT, KPD_COL_1, DIO_u8HIGH);
	DIO_enuSetPintValue(KPD_PORT, KPD_COL_2, DIO_u8HIGH);
	DIO_enuSetPintValue(KPD_PORT, KPD_COL_3, DIO_u8HIGH);
	DIO_enuSetPintValue(KPD_PORT, KPD_COL_4, DIO_u8HIGH);
}

u8 KBD_u8_grtPressedkey(void) {
	 u8 Local_u8Pressedkey = KBD_NO_PRESSED_KEY, Local_u8ColumnIndex,
			Local_u8RowIndex,Local_u8PinState;
	static u8 Local_Au8KPDArr[ROW_NUM][COLUMN_NUM] = KPD_ARR_VAL;
	static u8 Local_u8KBDColunmArr[COLUMN_NUM] = { KPD_COL_1, KPD_COL_2,
			KPD_COL_3, KPD_COL_4 };
	u8 Local_u8KBDRowArr[ROW_NUM] = { KPD_ROW_1, KPD_ROW_2,
	KPD_ROW_3, KPD_ROW_4 };
	for (Local_u8ColumnIndex = 0; Local_u8ColumnIndex < COLUMN_NUM;
			++Local_u8ColumnIndex) {
		DIO_enuSetPintValue(KPD_PORT, Local_u8KBDColunmArr[Local_u8ColumnIndex],
				DIO_u8LOW);
		for (Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUM; ++Local_u8RowIndex) {
			DIO_enuGetPinValue(KPD_PORT,Local_u8KBDRowArr[Local_u8RowIndex],&Local_u8PinState);
			if(Local_u8PinState==DIO_u8LOW)
			{
				Local_u8Pressedkey=Local_Au8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				while(Local_u8PinState==DIO_u8LOW)
				{
					DIO_enuGetPinValue(KPD_PORT,Local_u8KBDRowArr[Local_u8RowIndex],&Local_u8PinState);
				}
				return Local_u8Pressedkey;
			}
		}
		DIO_enuSetPintValue(KPD_PORT, Local_u8KBDColunmArr[Local_u8ColumnIndex],
				DIO_u8HIGH);
	}
	return Local_u8Pressedkey;
}
