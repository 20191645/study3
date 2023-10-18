// ���� ǥ����� ���� ǥ������� �ٲٴ� �Լ��� ����
// "IntListStack.h, cpp" ���� -- int�� ���� ����Ʈ ������ Ȱ���Ͽ� ����
#ifndef INFIXTOPOSTFIX_H_
#define INFIXTOPOSTFIX_H_

#define _CRT_SECURE_NO_WARNINGS
#include "ListStack.h"
#include <cctype>
#include <cstring>

// ǥ���Ŀ��� �� �ڸ��� ������ �����ڸ� �ִٰ� �����Ѵ�
void InfixToPostfix(char exp[]) {
	// ���� ǥ������ ����� �� char�� �迭[ �ǿ����ڴ� �ٷ� push ]
	char* result = new char[std::strlen(exp) + 1];
	
	// �����ڰ� ��� int�� Stack [ �켱����: '*, /' > '+, -' > '(, )' ] ����
	ListStack op;

	int i = 0;	// exp �ε���
	int j = 0;	// result �ε���

	// result�� ���� ǥ���� ��� ���
	while (exp[i]) {
		// �ǿ������� ���
		if (isalnum(exp[i])) {
			result[j++] = exp[i++];
			continue;
		}

		// ������ ���� ����ִ� ���
		if (op.isEmpty()) {
			op.Push(exp[i++]);
			continue;
		}

		// ������ ���� �� ����ִ� ���
		char ch = op.Peek();
		switch (exp[i]) {
		case '(':
			// 
			op.Push(exp[i]);
			break;

		case ')':
			while (!op.isEmpty()) {
				ch = op.Pop();
				if (ch != '(')
					result[j++] = ch;
			}
			break;
			
		case '*':
		case '/':
			// �켱������ ������ ���� ������ ������
			if (ch == '/' || ch == '*') {
				ch = op.Pop();
				result[j++] = ch;
			}
			op.Push(exp[i]);
			break;

		case '+':
		case '-':
			// �켱������ ���ų� ���� �����ڵ�
			while (ch != '(') {
				ch = op.Pop();
				result[j++] = ch;
				if (op.isEmpty())
					break;
				ch = op.Peek();
			}
			op.Push(exp[i]);
			break;
		}

		i++;
	}

	// result ���� exp�� �ű��
	while (!op.isEmpty()) {
		result[j++] = op.Pop();
	}
	result[j] = '\0';
	std::strcpy(exp, result);
	delete[] result;
}

#endif