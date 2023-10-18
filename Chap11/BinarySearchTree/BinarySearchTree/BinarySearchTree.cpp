// 이진 트리를 상속하여 이진 탐색 트리(Binary Search Tree/BST) 구현
#include "BinarySearchTree.h"
#include <iostream>

// BST 생성 및 초기화
void BSTree::MakeBSTree(TreeNode** root) {
	*root = NULL;
}

// BST를 대상으로 데이터 저장
void BSTree::Insert(TreeNode** root, BTData data) {
	TreeNode* temp = *root;		// 탐색용 노드
	TreeNode* parent = NULL;	// 부모 노드
	TreeNode* child = NULL;		// 자식 노드 -- 저장용

	// 데이터 저장할 노드의 위치 찾기 -- 부모 노드도 함께 지정
	while (temp != NULL) {
		// 데이터 중복 시 저장 실패
		if (BinaryTree::GetData(temp) == data)
			return;

		// temp가 자식 노드로 이동하기 전에 parent에 부모 노드 주소 저장
		parent = temp;

		if (BinaryTree::GetData(temp) > data)
			temp = BinaryTree::GetLeft(temp);
		else
			temp = BinaryTree::GetRight(temp);
	}

	child = BinaryTree::MakeNode();
	BinaryTree::SetData(child, data);

	// 루트 노드가 비어있는 경우
	if (*root == NULL) {
		*root = child;
	}
	else {
		// 부모 노드의 데이터를 기준으로 child 위치 정하기
		if (data > BinaryTree::GetData(parent))
			BinaryTree::MakeRight(parent, child);
		else
			BinaryTree::MakeLeft(parent, child);
	}
}

// BST를 대상으로 데이터 탐색
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

	// temp == NULL: 탐색 대상이 트리에 없음
	return temp;
}

// BST에서 data 노드를 제거하고 반환
TreeNode* BSTree::Remove(TreeNode** root, BTData data) {
	// 루트 노드 삭제를 대비하여 가상 루트 준비
	TreeNode* proot = BinaryTree::MakeNode();
	BinaryTree::ChangeRight(proot, *root);

	TreeNode* temp = *root;		// 탐색용 노드
	TreeNode* parent = proot;	// 부모 노드

	
	// data 노드 찾기 -- 부모 노드도 함께 지정
	while (temp != NULL) {
		if (data == BinaryTree::GetData(temp))
			break;

		// temp가 자식 노드로 이동하기 전에 parent에 부모 노드 주소 저장
		parent = temp;

		if (data < BinaryTree::GetData(temp))
			temp = BinaryTree::GetLeft(temp);
		else
			temp = BinaryTree::GetRight(temp);
	}
	
	// data 노드가 트리에 없는 경우
	if (temp == NULL)
		return temp;

	// data 노드가 단말 노드인 경우
	if (BinaryTree::GetLeft(temp) == NULL && 
		BinaryTree::GetRight(temp) == NULL) {
		if (BinaryTree::GetLeft(parent) == temp)	// 왼쪽 자식
			BinaryTree::RemoveLeft(parent);
		else								// 오른쪽 자식
			BinaryTree::RemoveRight(parent);
	}
	// data 노드가 하나의 자식 노드를 갖는 경우
	else if (BinaryTree::GetLeft(temp) == NULL || BinaryTree::GetRight(temp) == NULL) {
		TreeNode* child;	// temp의 자식 노드
		if (BinaryTree::GetLeft(temp) == NULL)	// 오른쪽 노드
			child = BinaryTree::GetRight(temp);
		else							// 왼쪽 노드
			child = BinaryTree::GetLeft(temp);

		// parent에 child 연결
		if (BinaryTree::GetLeft(parent) == temp)	// 왼쪽 자식
			BinaryTree::ChangeLeft(parent, child);
		else								// 오른쪽 자식
			BinaryTree::ChangeRight(parent, child);
	}
	// data 노드가 두 자식 노드를 갖는 경우
	else {
		TreeNode* mparent = temp;	// min 노드의 부모 노드
		TreeNode* min = BinaryTree::GetRight(temp);		// 가장 왼쪽에 있는 노드
		TreeNode* mchild = NULL;					// min 노드의 자식 노드

		// 1. data 노드의 오른쪽에서 가장 작은 데이터 노드 찾기 -- temp 대체
		while (BinaryTree::GetLeft(min) != NULL) {
			mparent = min;
			min = BinaryTree::GetLeft(min);
		}

		// min의 자식은 오른쪽 노드이다
		// -- min은 가장 왼쪽에 있는 노드이기 때문에
		mchild = BinaryTree::GetRight(min);
		
		// 2. min의 데이터를 temp의 데이터에 대입
		int mdata = BinaryTree::GetData(min);
		BinaryTree::SetData(temp, mdata);
		
		// 3. min의 부모 노드와 자식 노드 연결
		// min은 부모의 왼쪽 노드이다
		// -- min은 가장 왼쪽에 있는 노드이기 때문에
		if (mparent != temp) {
			BinaryTree::ChangeLeft(mparent, mchild);
		}
		// 예외: min이 data 노드의 오른쪽 노드인 경우
		else {
			BinaryTree::ChangeRight(mparent, mchild);
		}

		// 대체된 temp가 삭제된 노드인 min을 가리키기도록 수정
		temp = min;
		BinaryTree::SetData(temp, mdata);
	}

	// data 노드가 루트 노드였던 경우 -- root 노드 삭제 후 변경됨
	if (*root != BinaryTree::GetRight(proot)) {
		*root = BinaryTree::GetRight(proot);
	}
	delete proot;

	return temp;
}

// 중위 순회에 이용되는 함수
void ShowData(int data) {
	std::cout << data << ' ';
}

// BST에 저장된 모든 노드의 데이터 출력 -- 중위 순회 이용
void BSTree::ShowAll(TreeNode* bst) {
	BinaryTree::InOrderTraverse(bst, ShowData);
	std::cout << std::endl;
}