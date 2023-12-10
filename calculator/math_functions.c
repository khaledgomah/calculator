/*
 * math_functions.c
 *
 *  Created on: Dec 10, 2023
 *      Author: khaled
 */
#include "STD_TYPES.h"

u8 calcAnswer(u8 firstNum, u8 secondNum, u8 operation) {
	switch (operation) {
	case '+':
		return firstNum + secondNum;
		break;
	case '-':
		return firstNum - secondNum;
		break;
	case '*':
		return firstNum * secondNum;
		break;
	case '/':
		return firstNum / secondNum;
		break;

	}
	return 0;
}


u8 calculatePower(u8 base, u8 exponent) {
	u8 result = 1;

	for (u8 i = 0; i < exponent; ++i) {
		result *= base;
	}

	return result;
}

u8 calcNum(u8 * num) {
	u8 j = 1, answer = 0;

	for (u8 i = 0; i <= 1; i++) {
		answer += (num[i]-'0') * calculatePower(10, j);
		j--;
	}

	return answer;
}


