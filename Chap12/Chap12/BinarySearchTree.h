// ���� Ʈ���� ����Ͽ� ���� Ž�� Ʈ��(Binary Search Tree/BST) ����
// ���� Ʈ���� ��ӹޱ� ���� "BinaryTree.h, cpp"�� �Բ� ������
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "BinaryTree.h"

typedef TData BTData;	// TData: BinaryTree�� ������ Ÿ��

// ���� Ž�� Ʈ���� ADT
class BSTree: public BinaryTree {
public:
	void MakeBSTree(TreeNode** root);
	void Insert(TreeNode** root, BTData data);
	TreeNode* Search(TreeNode* bst, BTData data);
	TreeNode* Remove(TreeNode** root, BTData data);
	void ShowAll(TreeNode* bst);
};


#endif