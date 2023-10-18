// 이진 트리와 연결 리스트 기반 스택을 기반으로 수식 트리 확인
#include "ExpressionTree.h"
#include <iostream>

int main() {
	using std::endl;
	using std::cout;
	
	char exp[] = "12+7*";
	ExpTree etree;		// 수식 트리 활용 함수
	TreeNode* bt = etree.MakeExpTree(exp);

	cout << "전위 표기법 수식: ";
	etree.ShowPrefixTypeExp(bt);
	cout << endl;

	cout << "중위 표기법 수식: ";
	etree.ShowInfixTypeExp(bt);
	cout << endl;

	cout << "후위 표기법 수식: ";
	etree.ShowPostfixTypeExp(bt);
	cout << endl;

	cout << "연산 결과: " << etree.ExpTreeCalculator(bt) << endl;

	return 0;
}