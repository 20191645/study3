// ���� ����Ʈ(LinkedList) ����� ���� Ʈ��(BinaryTree) ����
// -- BST�� ���� ������ ����
#include "BinaryTree.h"
#include <iostream>

// ��� ����
TreeNode* BinaryTree::MakeNode() {
	TreeNode* bt = new TreeNode;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// ��� ������ ��ȯ
TData BinaryTree::GetData(TreeNode* bt) {
	return bt->data;
}

// ��� ������ ����
void BinaryTree::SetData(TreeNode* bt, TData data) {
	bt->data = data;
}

// ���� ���� Ʈ�� �ּ� ��ȯ
TreeNode* BinaryTree::GetLeft(TreeNode* bt) {
	return bt->left;
}

// ������ ���� Ʈ�� �ּ� ��ȯ
TreeNode* BinaryTree::GetRight(TreeNode* bt) {
	return bt->right;
}

// ���� Ʈ���� ���� ���� Ʈ�� ����
void BinaryTree::MakeLeft(TreeNode* main, TreeNode* sub) {
	// �̹� ���� ��尡 �ִ� ���
	if (main->left != NULL)
		delete main->left;
	main->left = sub;
}

// ������ ���� Ʈ�� ����
void BinaryTree::MakeRight(TreeNode* main, TreeNode* sub) {
	// �̹� ������ ��尡 �ִ� ���
	if (main->right != NULL)
		delete main->right;
	main->right = sub;
}

// ���� Ʈ�� ���� ��ȸ [��Ʈ, ����, ������] -- �����Ϳ��� function �Լ� ó��
void BinaryTree::PreOrderTraverse(TreeNode* bt, Function func) {
	// ��� Ż�� ����
	if (bt == NULL)
		return;

	func(bt->data);	// ��Ʈ
	PreOrderTraverse(bt->left, func);	// ���� ���
	PreOrderTraverse(bt->right, func);	// ������ ���
}

// ���� Ʈ�� ���� ��ȸ [����, ��Ʈ, ������] -- �����Ϳ��� function �Լ� ó��
void BinaryTree::InOrderTraverse(TreeNode* bt, Function func) {
	// ��� Ż�� ����
	if (bt == NULL)
		return;

	InOrderTraverse(bt->left, func);	// ���� ���
	func(bt->data);	// ��Ʈ
	InOrderTraverse(bt->right, func);	// ������ ���
}

// ���� Ʈ�� ���� ��ȸ [����, ������, ��Ʈ] -- �����Ϳ��� function �Լ� ó��
void BinaryTree::PostOrderTraverse(TreeNode* bt, Function func) {
	// ��� Ż�� ����
	if (bt == NULL)
		return;

	PostOrderTraverse(bt->left, func);	// ���� ���
	PostOrderTraverse(bt->right, func);	// ������ ���
	func(bt->data);	// ��Ʈ
}


// -- ��� ������ ���� �߰��� �Լ� 4�� --
// ���� �ڽ� ��带 �����ϰ� ��ȯ
TreeNode* BinaryTree::RemoveLeft(TreeNode* bt) {
	TreeNode* left = NULL;	// ���� �ڽ� ���
	if (bt != NULL) {
		left = GetLeft(bt);
		ChangeLeft(bt, NULL);
	}
	return left;
}

// ������ �ڽ� ��带 �����ϰ� ��ȯ
TreeNode* BinaryTree::RemoveRight(TreeNode* bt) {
	TreeNode* right = NULL;	// ������ �ڽ� ���
	if (bt != NULL) {
		right = GetRight(bt);
		ChangeRight(bt, NULL);
	}
	return right;
}

// main�� ���� �ڽ� ��带 sub�� ���� -- �޸� ����X
void BinaryTree::ChangeLeft(TreeNode* main, TreeNode* sub) {
	main->left = sub;
}

// main�� ������ �ڽ� ��带 sub�� ���� -- �޸� ����X
void BinaryTree::ChangeRight(TreeNode* main, TreeNode* sub) {
	main->right = sub;
}
