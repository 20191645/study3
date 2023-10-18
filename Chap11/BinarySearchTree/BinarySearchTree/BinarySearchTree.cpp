// ���� Ʈ���� ����Ͽ� ���� Ž�� Ʈ��(Binary Search Tree/BST) ����
#include "BinarySearchTree.h"
#include <iostream>

// BST ���� �� �ʱ�ȭ
void BSTree::MakeBSTree(TreeNode** root) {
	*root = NULL;
}

// BST�� ������� ������ ����
void BSTree::Insert(TreeNode** root, BTData data) {
	TreeNode* temp = *root;		// Ž���� ���
	TreeNode* parent = NULL;	// �θ� ���
	TreeNode* child = NULL;		// �ڽ� ��� -- �����

	// ������ ������ ����� ��ġ ã�� -- �θ� ��嵵 �Բ� ����
	while (temp != NULL) {
		// ������ �ߺ� �� ���� ����
		if (BinaryTree::GetData(temp) == data)
			return;

		// temp�� �ڽ� ���� �̵��ϱ� ���� parent�� �θ� ��� �ּ� ����
		parent = temp;

		if (BinaryTree::GetData(temp) > data)
			temp = BinaryTree::GetLeft(temp);
		else
			temp = BinaryTree::GetRight(temp);
	}

	child = BinaryTree::MakeNode();
	BinaryTree::SetData(child, data);

	// ��Ʈ ��尡 ����ִ� ���
	if (*root == NULL) {
		*root = child;
	}
	else {
		// �θ� ����� �����͸� �������� child ��ġ ���ϱ�
		if (data > BinaryTree::GetData(parent))
			BinaryTree::MakeRight(parent, child);
		else
			BinaryTree::MakeLeft(parent, child);
	}
}

// BST�� ������� ������ Ž��
TreeNode* BSTree::Search(TreeNode* bst, BTData data) {
	TreeNode* temp = bst;

	while (temp != NULL) {
		if (data == BinaryTree::GetData(temp))
			break;
		else if (data < BinaryTree::GetData(temp))
			temp = BinaryTree::GetLeft(temp);
		else
			temp = BinaryTree::GetRight(temp);
	}

	// temp == NULL: Ž�� ����� Ʈ���� ����
	return temp;
}

// BST���� data ��带 �����ϰ� ��ȯ
TreeNode* BSTree::Remove(TreeNode** root, BTData data) {
	// ��Ʈ ��� ������ ����Ͽ� ���� ��Ʈ �غ�
	TreeNode* proot = BinaryTree::MakeNode();
	BinaryTree::ChangeRight(proot, *root);

	TreeNode* temp = *root;		// Ž���� ���
	TreeNode* parent = proot;	// �θ� ���

	
	// data ��� ã�� -- �θ� ��嵵 �Բ� ����
	while (temp != NULL) {
		if (data == BinaryTree::GetData(temp))
			break;

		// temp�� �ڽ� ���� �̵��ϱ� ���� parent�� �θ� ��� �ּ� ����
		parent = temp;

		if (data < BinaryTree::GetData(temp))
			temp = BinaryTree::GetLeft(temp);
		else
			temp = BinaryTree::GetRight(temp);
	}
	
	// data ��尡 Ʈ���� ���� ���
	if (temp == NULL)
		return temp;

	// data ��尡 �ܸ� ����� ���
	if (BinaryTree::GetLeft(temp) == NULL && 
		BinaryTree::GetRight(temp) == NULL) {
		if (BinaryTree::GetLeft(parent) == temp)	// ���� �ڽ�
			BinaryTree::RemoveLeft(parent);
		else								// ������ �ڽ�
			BinaryTree::RemoveRight(parent);
	}
	// data ��尡 �ϳ��� �ڽ� ��带 ���� ���
	else if (BinaryTree::GetLeft(temp) == NULL || BinaryTree::GetRight(temp) == NULL) {
		TreeNode* child;	// temp�� �ڽ� ���
		if (BinaryTree::GetLeft(temp) == NULL)	// ������ ���
			child = BinaryTree::GetRight(temp);
		else							// ���� ���
			child = BinaryTree::GetLeft(temp);

		// parent�� child ����
		if (BinaryTree::GetLeft(parent) == temp)	// ���� �ڽ�
			BinaryTree::ChangeLeft(parent, child);
		else								// ������ �ڽ�
			BinaryTree::ChangeRight(parent, child);
	}
	// data ��尡 �� �ڽ� ��带 ���� ���
	else {
		TreeNode* mparent = temp;	// min ����� �θ� ���
		TreeNode* min = BinaryTree::GetRight(temp);		// ���� ���ʿ� �ִ� ���
		TreeNode* mchild = NULL;					// min ����� �ڽ� ���

		// 1. data ����� �����ʿ��� ���� ���� ������ ��� ã�� -- temp ��ü
		while (BinaryTree::GetLeft(min) != NULL) {
			mparent = min;
			min = BinaryTree::GetLeft(min);
		}

		// min�� �ڽ��� ������ ����̴�
		// -- min�� ���� ���ʿ� �ִ� ����̱� ������
		mchild = BinaryTree::GetRight(min);
		
		// 2. min�� �����͸� temp�� �����Ϳ� ����
		int mdata = BinaryTree::GetData(min);
		BinaryTree::SetData(temp, mdata);
		
		// 3. min�� �θ� ���� �ڽ� ��� ����
		// min�� �θ��� ���� ����̴�
		// -- min�� ���� ���ʿ� �ִ� ����̱� ������
		if (mparent != temp) {
			BinaryTree::ChangeLeft(mparent, mchild);
		}
		// ����: min�� data ����� ������ ����� ���
		else {
			BinaryTree::ChangeRight(mparent, mchild);
		}

		// ��ü�� temp�� ������ ����� min�� ����Ű�⵵�� ����
		temp = min;
		BinaryTree::SetData(temp, mdata);
	}

	// data ��尡 ��Ʈ ��忴�� ��� -- root ��� ���� �� �����
	if (*root != BinaryTree::GetRight(proot)) {
		*root = BinaryTree::GetRight(proot);
	}
	delete proot;

	return temp;
}

// ���� ��ȸ�� �̿�Ǵ� �Լ�
void ShowData(int data) {
	std::cout << data << ' ';
}

// BST�� ����� ��� ����� ������ ��� -- ���� ��ȸ �̿�
void BSTree::ShowAll(TreeNode* bst) {
	BinaryTree::InOrderTraverse(bst, ShowData);
	std::cout << std::endl;
}