// 이진 트리와 연결 리스트 기반 스택을 기반으로 수식 트리 구현
// 이진 트리 활용을 위해 "BinaryTree.h, cpp"와 함께 컴파일
#include "BinaryTree.h"

// 수식 트리 표현을 위한 함수 클래스
class ExpTree {
public:
	TreeNode* MakeExpTree(char exp[]);
	int ExpTreeCalculator(TreeNode* bt);

	void ShowPrefixTypeExp(TreeNode* bt);
	void ShowInfixTypeExp(TreeNode* bt);
	void ShowPostfixTypeExp(TreeNode* bt);
};