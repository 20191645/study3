// 연결 리스트(LinkedList) 기반의 이진 트리(BinaryTree) 구현
// -- BST를 위해 수정한 버전
#include "BinaryTree.h"
#include <iostream>

// 노드 생성
TreeNode* BinaryTree::MakeNode() {
	TreeNode* bt = new TreeNode;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// 노드 데이터 반환
TData BinaryTree::GetData(TreeNode* bt) {
	return bt->data;
}

// 노드 데이터 저장
void BinaryTree::SetData(TreeNode* bt, TData data) {
	bt->data = data;
}

// 왼쪽 서브 트리 주소 반환
TreeNode* BinaryTree::GetLeft(TreeNode* bt) {
	return bt->left;
}

// 오른쪽 서브 트리 주소 반환
TreeNode* BinaryTree::GetRight(TreeNode* bt) {
	return bt->right;
}

// 메인 트리에 왼쪽 서브 트리 연결
void BinaryTree::MakeLeft(TreeNode* main, TreeNode* sub) {
	// 이미 왼쪽 노드가 있는 경우
	if (main->left != NULL)
		delete main->left;
	main->left = sub;
}

// 오른쪽 서브 트리 연결
void BinaryTree::MakeRight(TreeNode* main, TreeNode* sub) {
	// 이미 오른쪽 노드가 있는 경우
	if (main->right != NULL)
		delete main->right;
	main->right = sub;
}

// 이진 트리 전위 순회 [루트, 왼쪽, 오른쪽] -- 데이터에는 function 함수 처리
void BinaryTree::PreOrderTraverse(TreeNode* bt, Function func) {
	// 재귀 탈출 조건
	if (bt == NULL)
		return;

	func(bt->data);	// 루트
	PreOrderTraverse(bt->left, func);	// 왼쪽 노드
	PreOrderTraverse(bt->right, func);	// 오른쪽 노드
}

// 이진 트리 중위 순회 [왼쪽, 루트, 오른쪽] -- 데이터에는 function 함수 처리
void BinaryTree::InOrderTraverse(TreeNode* bt, Function func) {
	// 재귀 탈출 조건
	if (bt == NULL)
		return;

	InOrderTraverse(bt->left, func);	// 왼쪽 노드
	func(bt->data);	// 루트
	InOrderTraverse(bt->right, func);	// 오른쪽 노드
}

// 이진 트리 후위 순회 [왼쪽, 오른쪽, 루트] -- 데이터에는 function 함수 처리
void BinaryTree::PostOrderTraverse(TreeNode* bt, Function func) {
	// 재귀 탈출 조건
	if (bt == NULL)
		return;

	PostOrderTraverse(bt->left, func);	// 왼쪽 노드
	PostOrderTraverse(bt->right, func);	// 오른쪽 노드
	func(bt->data);	// 루트
}


// -- 노드 삭제를 위해 추가된 함수 4개 --
// 왼쪽 자식 노드를 제거하고 반환
TreeNode* BinaryTree::RemoveLeft(TreeNode* bt) {
	TreeNode* left = NULL;	// 왼쪽 자식 노드
	if (bt != NULL) {
		left = GetLeft(bt);
		ChangeLeft(bt, NULL);
	}
	return left;
}

// 오른쪽 자식 노드를 제거하고 반환
TreeNode* BinaryTree::RemoveRight(TreeNode* bt) {
	TreeNode* right = NULL;	// 오른쪽 자식 노드
	if (bt != NULL) {
		right = GetRight(bt);
		ChangeRight(bt, NULL);
	}
	return right;
}

// main의 왼쪽 자식 노드를 sub로 변경 -- 메모리 삭제X
void BinaryTree::ChangeLeft(TreeNode* main, TreeNode* sub) {
	main->left = sub;
}

// main의 오른쪽 자식 노드를 sub로 변경 -- 메모리 삭제X
void BinaryTree::ChangeRight(TreeNode* main, TreeNode* sub) {
	main->right = sub;
}
