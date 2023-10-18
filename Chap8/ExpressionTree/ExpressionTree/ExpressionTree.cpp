// ���� Ʈ���� ���� ����Ʈ ��� ������ ������� ���� Ʈ�� ����
// ListStack�� ��������: TreeNode*, TreeNode�� ��������: int
#include "ExpressionTree.h"
#include "ListStack.h"
#include <cctype>
#include <iostream>

// Traverse �Ű������� �Լ�
void ShowData(int data) {
	// ASCII �ڵ忡 ���� int���� char������ ��ȯ�Ͽ� ���
	std::cout << (char)data;
}

// ���� ǥ�������� ���� Ʈ�� ����
TreeNode* ExpTree::MakeExpTree(char exp[]) {
	// ���� ǥ���� ��ȯ ������ ����� TreeNode*�� ����
	ListStack stack;

	// ���� Ʈ�� �Լ��� Ȱ���ϱ� ���� Ŭ���� ��ü
	BinaryTree tree;

	/*
		���� ����:
		1. �ϴ� exp[]�� data�� ��� TreeNode* ������ �����
		2. �ǿ������̸� �������� �̵�, �������̸� ���ÿ��� 2�� ������
		3. root�� ������, ù��° pop() ����� right, �ι�° pop() ����� left�� �ϴ� Node ����
		4. �ش� TreeNode*�� �ٽ� ���ÿ� �ֱ�
		5. ���������� ���ÿ� ���� �ϳ��� TreeNode* ������ ���
	*/

	// ���ÿ� ��� ���� TreeNode* ����
	TreeNode* temp;
	int i = 0;
	while (exp[i]) {
		temp = tree.MakeNode();
		tree.SetData(temp, exp[i]);
		
		// �ǿ�����
		if (isalnum(exp[i])) {
			stack.Push(temp);
		}
		// ������
		else {
			tree.MakeRight(temp, stack.Pop());	// �ι�° �ǿ�����
			tree.MakeLeft(temp, stack.Pop());	// ù��° �ǿ�����
			stack.Push(temp);
		}

		i++;
	}

	temp = stack.Pop();
	return temp;
}

// ��͸� �̿��Ͽ� ���� Ʈ�� ���
int ExpTree::ExpTreeCalculator(TreeNode* bt) {
	int result = 0;	// ���� ���

	// ������
	if (!isalnum(bt->data)) {
		int op1 = ExpTreeCalculator(bt->left);	// ���� ���
		int op2 = ExpTreeCalculator(bt->right);	// ������ ���
		
		switch (bt->data) {
		case '*':
			result = op1 * op2;
			break;

		case '/':
			result = op1 / op2;
			break;

		case '+':
			result = op1 + op2;
			break;

		case '-':
			result = op1 - op2;
			break;
		}
	}
	// �ǿ����� -- �ܸ� ���
	else {
		return (bt->data) - '0';
	}

	return result;
}

// ���� ǥ��� ������� ���
void ExpTree::ShowPrefixTypeExp(TreeNode* bt) {
	BinaryTree tree;
	tree.PreOrderTraverse(bt, ShowData);
}

// ���� ǥ��� ������� ��� -- �Ұ�ȣ���� �����ؼ� ����ϵ��� ����
void ExpTree::ShowInfixTypeExp(TreeNode* bt) {
	// ��� Ż�� ����
	if (bt == NULL)
		return;

	// ���� �Ұ�ȣ ��� -- ���� ���X, �ϳ��� ������� �����Ҷ�
	if (bt->left != NULL || bt->right != NULL)
		std::cout << "(";

	ShowInfixTypeExp(bt->left);
	ShowData(bt->data);
	ShowInfixTypeExp(bt->right);

	// ������ �Ұ�ȣ ��� -- ���� ���X, �ϳ��� ������� ��������
	if (bt->left != NULL || bt->right != NULL)
		std::cout << ")";
}

// ���� ǥ��� ������� ���
void ExpTree::ShowPostfixTypeExp(TreeNode* bt) {
	BinaryTree tree;
	tree.PostOrderTraverse(bt, ShowData);
}