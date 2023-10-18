// 후위 표현식을 계산하는 함수의 정의
// "IntListStack.h, cpp" 포함 -- int형 연결 리스트 스택을 활용하여 구현
#ifndef POSTCALCULATOR_H_
#define POSTCALCULATOR_H_

#define _CRT_SECURE_NO_WARNINGS
#include "ListStack.h"
#include <cctype>

int PostCalculator(char exp[]) {
	// 연산 과정을 담당할 int형 스택
	ListStack stack;

	/*
		구현 과정:
		1. 피연산자는 무조건 스택으로
		2. 연산자를 만나면 스택에서 피연산자 2개를 꺼내어 계산
		3. 계산 결과를 다시 스택으로
	*/

	int i = 0;
	while (exp[i]) {
		// 피연산자
		if (isalnum(exp[i])) {
			// 바로 계산하기 위해서 char형 -> int형 변환
			stack.Push(exp[i++] - '0');
			continue;
		}

		// 연산자
		int num2 = stack.Pop();
		int num1 = stack.Pop();
		switch (exp[i]) {
		case '*':
			stack.Push(num1 * num2);
			break;

		case '/':
			stack.Push(num1 / num2);
			break;

		case '+':
			stack.Push(num1 + num2);
			break;

		case '-':
			stack.Push(num1 - num2);
			break;
		}
		i++;
	}

	i = stack.Pop();
	return i;
}

#endif