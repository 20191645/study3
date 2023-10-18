// 중위 표기법을 후위 표기법으로 바꾸는 함수의 정의
// "IntListStack.h, cpp" 포함 -- int형 연결 리스트 스택을 활용하여 구현
#ifndef INFIXTOPOSTFIX_H_
#define INFIXTOPOSTFIX_H_

#define _CRT_SECURE_NO_WARNINGS
#include "ListStack.h"
#include <cctype>
#include <cstring>

// 표현식에는 한 자리의 정수나 연산자만 있다고 가정한다
void InfixToPostfix(char exp[]) {
	// 후위 표현식의 결과가 될 char형 배열[ 피연산자는 바로 push ]
	char* result = new char[std::strlen(exp) + 1];
	
	// 연산자가 담길 int형 Stack [ 우선순위: '*, /' > '+, -' > '(, )' ] 가정
	ListStack op;

	int i = 0;	// exp 인덱스
	int j = 0;	// result 인덱스

	// result에 후위 표현식 결과 담기
	while (exp[i]) {
		// 피연산자인 경우
		if (isalnum(exp[i])) {
			result[j++] = exp[i++];
			continue;
		}

		// 연산자 스택 비어있는 경우
		if (op.isEmpty()) {
			op.Push(exp[i++]);
			continue;
		}

		// 연산자 스택 안 비어있는 경우
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
			// 우선순위는 같으나 먼저 등장한 연산자
			if (ch == '/' || ch == '*') {
				ch = op.Pop();
				result[j++] = ch;
			}
			op.Push(exp[i]);
			break;

		case '+':
		case '-':
			// 우선순위가 같거나 높은 연산자들
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

	// result 값을 exp로 옮기기
	while (!op.isEmpty()) {
		result[j++] = op.Pop();
	}
	result[j] = '\0';
	std::strcpy(exp, result);
	delete[] result;
}

#endif