// AVL 트리 -- BST를 상속하여 리밸런싱 기능을 추가한 AVL Tree 구현
#include "AVLTree.h"
#include <iostream>

// BSTree의 Insert 함수 오버라이딩
void AVLTree::Insert(TreeNode** root, BTData data) {
	// BST의 insert 기능 그대로
	BSTree::Insert(root, data);
	
	// 리밸런싱 기능 추가
	Rebalance(root);
}

// BSTree의 Remove 함수 오버라이딩
TreeNode* AVLTree::Remove(TreeNode** root, BTData data) {
	// BST의 remove 기능 그대로
	TreeNode* temp = BSTree::Remove(root, data);

	// 리밸런싱 기능 추가 -- 루트 노드 수정
	*root = Rebalance(root);

	return temp;
}

// 리밸런싱 함수 -- 균형 인수의 절대값이 2 이상이면 트리 재조정
TreeNode* AVLTree::Rebalance(TreeNode** root) {
	int balance = GetHeightDiff(*root);	// 균형 인수: 왼쪽 높이 - 오른쪽 높이

	// LL, LR 상태: balance >= +2
	// RR, RL 상태: balance <= -2

	if (balance >= 2) {
		// LL 상태: 자식 노드 2개가 연이어 왼쪽으로 연결
		if (GetHeightDiff(GetLeft(*root)) >= 1)
			*root = RotateLL(*root);
		// LR 상태: 자식 노드가 왼쪽 하나, 이어서 오른쪽 하나 연결
		else if (GetHeightDiff(GetLeft(*root)) <= -1)
			*root = RotateLR(*root);
	}
	else if (balance <= -2) {
		// RR 상태: 자식 노드 2개가 연이어 오른쪽으로 연결
		if (GetHeightDiff(GetRight(*root)) <= -1)
			*root = RotateRR(*root);
		// RL 상태: 자식 노드가 오른쪽 하나, 이어서 왼쪽 하나 연결
		else if (GetHeightDiff(GetRight(*root)) >= 1)
			*root = RotateRL(*root);
	}

	// 재조정된 트리의 루트 노드 반환
	return *root;
}

// 트리의 높이를 계산하여 반환
int AVLTree::GetHeight(TreeNode* bst) {
	int lheight = 1;	// 왼쪽 노드 높이
	int rheight = 1;	// 오른쪽 노드 높이
	
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

// 서브 트리의 높이 차를 반환
int AVLTree::GetHeightDiff(TreeNode* bst){
	if (bst == NULL)
		return 0;

	return GetHeight(GetLeft(bst)) - GetHeight(GetRight(bst));
}

// LL 회전 함수
TreeNode* AVLTree::RotateLL(TreeNode* bst) {
	TreeNode* parent = bst;	// 루트 노드
	TreeNode* child = GetLeft(bst);
	
	// LL 회전
	ChangeLeft(parent, GetRight(child));
	ChangeRight(child, parent);

	// LL 회전으로 parent에서 child로 루트 노드 변경
	return child;
}

// RR 회전 함수
TreeNode* AVLTree::RotateRR(TreeNode* bst) {
	TreeNode* parent = bst;	// 루트 노드
	TreeNode* child = GetRight(bst);

	// RR 회전
	ChangeRight(parent, GetLeft(child));
	ChangeLeft(child, parent);

	// RR 회전으로 parent에서 child로 루트 노드 변경
	return child;
}

// LR 회전 함수
TreeNode* AVLTree::RotateLR(TreeNode* bst) {
	TreeNode* parent = bst;	// 루트 노드
	TreeNode* child = GetLeft(bst);

	// 부분적 RR 회전
	child = RotateRR(child);
	ChangeLeft(parent, child);

	// LL 회전
	parent = RotateLL(parent);
	return parent;
}

// RL 회전 함수
TreeNode* AVLTree::RotateRL(TreeNode* bst) {
	TreeNode* parent = bst;	// 루트 노드
	TreeNode* child = GetRight(bst);

	// 부분적 LL 회전
	child = RotateLL(child);
	ChangeRight(parent, child);

	// RR 회전
	parent = RotateRR(parent);
	return parent;
}