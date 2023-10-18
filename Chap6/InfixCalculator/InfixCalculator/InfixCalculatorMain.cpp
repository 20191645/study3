// ���� ǥ����� ���� ǥ������� �ٲپ� �����ϴ� ���α׷�
// "InfixToPostfix.h": ���� ǥ��� -> ���� ǥ��� ��ȯ �Լ�
// "PostCalculator.h": ���� ǥ����� ��� �Լ�
#include "InfixToPostfix.h"
#include "PostCalculator.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	cout << "���� ǥ���: " << exp1 << endl;
	InfixToPostfix(exp1);
	cout << "���� ǥ���: " << exp1 << endl;
	cout << "��� ���: " << PostCalculator(exp1) << endl;
	cout << endl;

	cout << "���� ǥ���: " << exp2 << endl;
	InfixToPostfix(exp2);
	cout << "���� ǥ���: " << exp2 << endl;
	cout << "��� ���: " << PostCalculator(exp2) << endl;
	cout << endl;

	cout << "���� ǥ���: " << exp3 << endl;
	InfixToPostfix(exp3);
	cout << "���� ǥ���: " << exp3 << endl;
	cout << "��� ���: " << PostCalculator(exp3) << endl;
	cout << endl;

	return 0;
}