// 이진 트리를 상속하여 이진 탐색 트리(Binary Search Tree/BST) 구현
// 이진 트리를 상속받기 위해 "BinaryTree.h, cpp"와 함께 컴파일
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "BinaryTree.h"

typedef TData BTData;	// TData: BinaryTree의 데이터 타입

// 이진 탐색 트리의 ADT
class BSTree: public BinaryTree {
public:
	void MakeBSTree(TreeNode** root);
	void Insert(TreeNode** root, BTData data);
	TreeNode* Search(TreeNode* bst, BTData data);
	TreeNode* Remove(TreeNode** root, BTData data);
	void ShowAll(TreeNode* bst);
};


#endif