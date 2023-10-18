// ���� Ʈ���� ���� ����Ʈ ��� ������ ������� ���� Ʈ�� ����
// ���� Ʈ�� Ȱ���� ���� "BinaryTree.h, cpp"�� �Բ� ������
#include "BinaryTree.h"

// ���� Ʈ�� ǥ���� ���� �Լ� Ŭ����
class ExpTree {
public:
	TreeNode* MakeExpTree(char exp[]);
	int ExpTreeCalculator(TreeNode* bt);

	void ShowPrefixTypeExp(TreeNode* bt);
	void ShowInfixTypeExp(TreeNode* bt);
	void ShowPostfixTypeExp(TreeNode* bt);
};