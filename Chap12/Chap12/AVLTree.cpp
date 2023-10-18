// AVL Ʈ�� -- BST�� ����Ͽ� ���뷱�� ����� �߰��� AVL Tree ����
#include "AVLTree.h"
#include <iostream>

// BSTree�� Insert �Լ� �������̵�
void AVLTree::Insert(TreeNode** root, BTData data) {
	// BST�� insert ��� �״��
	BSTree::Insert(root, data);
	
	// ���뷱�� ��� �߰�
	Rebalance(root);
}

// BSTree�� Remove �Լ� �������̵�
TreeNode* AVLTree::Remove(TreeNode** root, BTData data) {
	// BST�� remove ��� �״��
	TreeNode* temp = BSTree::Remove(root, data);

	// ���뷱�� ��� �߰� -- ��Ʈ ��� ����
	*root = Rebalance(root);

	return temp;
}

// ���뷱�� �Լ� -- ���� �μ��� ���밪�� 2 �̻��̸� Ʈ�� ������
TreeNode* AVLTree::Rebalance(TreeNode** root) {
	int balance = GetHeightDiff(*root);	// ���� �μ�: ���� ���� - ������ ����

	// LL, LR ����: balance >= +2
	// RR, RL ����: balance <= -2

	if (balance >= 2) {
		// LL ����: �ڽ� ��� 2���� ���̾� �������� ����
		if (GetHeightDiff(GetLeft(*root)) >= 1)
			*root = RotateLL(*root);
		// LR ����: �ڽ� ��尡 ���� �ϳ�, �̾ ������ �ϳ� ����
		else if (GetHeightDiff(GetLeft(*root)) <= -1)
			*root = RotateLR(*root);
	}
	else if (balance <= -2) {
		// RR ����: �ڽ� ��� 2���� ���̾� ���������� ����
		if (GetHeightDiff(GetRight(*root)) <= -1)
			*root = RotateRR(*root);
		// RL ����: �ڽ� ��尡 ������ �ϳ�, �̾ ���� �ϳ� ����
		else if (GetHeightDiff(GetRight(*root)) >= 1)
			*root = RotateRL(*root);
	}

	// �������� Ʈ���� ��Ʈ ��� ��ȯ
	return *root;
}

// Ʈ���� ���̸� ����Ͽ� ��ȯ
int AVLTree::GetHeight(TreeNode* bst) {
	int lheight = 1;	// ���� ��� ����
	int rheight = 1;	// ������ ��� ����
	
	if (bst == NULL)
		return 0;

	if (GetLeft(bst) != NULL) {
		lheight += GetHeight(GetLeft(bst));
	}
	if (GetRight(bst) != NULL) {
		rheight += GetHeight(GetRight(bst));
	}

	return (lheight > rheight) ? lheight : rheight;
}

// ���� Ʈ���� ���� ���� ��ȯ
int AVLTree::GetHeightDiff(TreeNode* bst){
	if (bst == NULL)
		return 0;

	return GetHeight(GetLeft(bst)) - GetHeight(GetRight(bst));
}

// LL ȸ�� �Լ�
TreeNode* AVLTree::RotateLL(TreeNode* bst) {
	TreeNode* parent = bst;	// ��Ʈ ���
	TreeNode* child = GetLeft(bst);
	
	// LL ȸ��
	ChangeLeft(parent, GetRight(child));
	ChangeRight(child, parent);

	// LL ȸ������ parent���� child�� ��Ʈ ��� ����
	return child;
}

// RR ȸ�� �Լ�
TreeNode* AVLTree::RotateRR(TreeNode* bst) {
	TreeNode* parent = bst;	// ��Ʈ ���
	TreeNode* child = GetRight(bst);

	// RR ȸ��
	ChangeRight(parent, GetLeft(child));
	ChangeLeft(child, parent);

	// RR ȸ������ parent���� child�� ��Ʈ ��� ����
	return child;
}

// LR ȸ�� �Լ�
TreeNode* AVLTree::RotateLR(TreeNode* bst) {
	TreeNode* parent = bst;	// ��Ʈ ���
	TreeNode* child = GetLeft(bst);

	// �κ��� RR ȸ��
	child = RotateRR(child);
	ChangeLeft(parent, child);

	// LL ȸ��
	parent = RotateLL(parent);
	return parent;
}

// RL ȸ�� �Լ�
TreeNode* AVLTree::RotateRL(TreeNode* bst) {
	TreeNode* parent = bst;	// ��Ʈ ���
	TreeNode* child = GetRight(bst);

	// �κ��� LL ȸ��
	child = RotateLL(child);
	ChangeRight(parent, child);

	// RR ȸ��
	parent = RotateRR(parent);
	return parent;
}