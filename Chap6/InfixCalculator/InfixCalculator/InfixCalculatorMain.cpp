// 중위 표기법을 후위 표기법으로 바꾸어 연산하는 프로그램
// "InfixToPostfix.h": 중위 표기법 -> 후위 표기법 변환 함수
// "PostCalculator.h": 후위 표기법을 계산 함수
#include "InfixToPostfix.h"
#include "PostCalculator.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	cout << "중위 표기법: " << exp1 << endl;
	InfixToPostfix(exp1);
	cout << "후위 표기법: " << exp1 << endl;
	cout << "계산 결과: " << PostCalculator(exp1) << endl;
	cout << endl;

	cout << "중위 표기법: " << exp2 << endl;
	InfixToPostfix(exp2);
	cout << "후위 표기법: " << exp2 << endl;
	cout << "계산 결과: " << PostCalculator(exp2) << endl;
	cout << endl;

	cout << "중위 표기법: " << exp3 << endl;
	InfixToPostfix(exp3);
	cout << "후위 표기법: " << exp3 << endl;
	cout << "계산 결과: " << PostCalculator(exp3) << endl;
	cout << endl;

	return 0;
}