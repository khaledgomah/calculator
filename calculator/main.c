#include "errorState.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KBD_int.h"
#include "math_function_int.h"


int main(void) {
	u8 firstNumArr[2] = { 0 }, secondNumArr[2] = { 0 }, operation;
	u32 firstNum, secondNum,ans;
	DIO_enuInit();
	LCD_enuInit();
	KPD_Init();

	while (1) {

		u8 digit = KBD_u8_grtPressedkey();
		while (digit == KBD_NO_PRESSED_KEY) {
			digit = KBD_u8_grtPressedkey();
		}
		u8 i = 0;
		while (digit != '*' && digit != '/' && digit != '+' && digit != '-'
				&& digit != '=') {
			firstNumArr[i] = digit;
			LCD_enuDisplayChar(digit);
			i++;
			digit = KBD_u8_grtPressedkey();
			while (digit == KBD_NO_PRESSED_KEY) {
				digit = KBD_u8_grtPressedkey();
			}

		}

		operation = digit;
		LCD_enuDisplayChar(digit);
		digit = KBD_u8_grtPressedkey();
		while (digit == KBD_NO_PRESSED_KEY) {
			digit = KBD_u8_grtPressedkey();
		}
		i = 0;

		while (digit != '*' && digit != '/' && digit != '+' && digit != '-'
				&& digit != '=') {
			secondNumArr[i] = digit;
			LCD_enuDisplayChar(digit);
			i++;
			digit = KBD_u8_grtPressedkey();
			while (digit == KBD_NO_PRESSED_KEY) {
				digit = KBD_u8_grtPressedkey();
			}

		}
		firstNum = calcNum(firstNumArr);
		secondNum = calcNum(secondNumArr);
LCD_vidClearScreen();
LCD_enuWriteNumber(firstNum);
LCD_enuDisplayChar(operation);

LCD_enuWriteNumber(secondNum);
		LCD_enuDisplayChar('=');

		ans = calcAnswer(firstNum,secondNum,operation);
		LCD_enuWriteNumber(ans);

	}

}
