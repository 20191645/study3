// ���� ǥ������ ����ϴ� �Լ��� ����
// "IntListStack.h, cpp" ���� -- int�� ���� ����Ʈ ������ Ȱ���Ͽ� ����
#ifndef POSTCALCULATOR_H_
#define POSTCALCULATOR_H_

#define _CRT_SECURE_NO_WARNINGS
#include "ListStack.h"
#include <cctype>

int PostCalculator(char exp[]) {
	// ���� ������ ����� int�� ����
	ListStack stack;

	/*
		���� ����:
		1. �ǿ����ڴ� ������ ��������
		2. �����ڸ� ������ ���ÿ��� �ǿ����� 2���� ������ ���
		3. ��� ����� �ٽ� ��������
	*/

	int i = 0;
	while (exp[i]) {
		// �ǿ�����
		if (isalnum(exp[i])) {
			// �ٷ� ����ϱ� ���ؼ� char�� -> int�� ��ȯ
			stack.Push(exp[i++] - '0');
			continue;
		}

		// ������
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