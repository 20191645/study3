// ���� Ʈ���� ���� ����Ʈ ��� ������ ������� ���� Ʈ�� Ȯ��
#include "ExpressionTree.h"
#include <iostream>

int main() {
	using std::endl;
	using std::cout;
	
	char exp[] = "12+7*";
	ExpTree etree;		// ���� Ʈ�� Ȱ�� �Լ�
	TreeNode* bt = etree.MakeExpTree(exp);

	cout << "���� ǥ��� ����: ";
	etree.ShowPrefixTypeExp(bt);
	cout << endl;

	cout << "���� ǥ��� ����: ";
	etree.ShowInfixTypeExp(bt);
	cout << endl;

	cout << "���� ǥ��� ����: ";
	etree.ShowPostfixTypeExp(bt);
	cout << endl;

	cout << "���� ���: " << etree.ExpTreeCalculator(bt) << endl;

	return 0;
}