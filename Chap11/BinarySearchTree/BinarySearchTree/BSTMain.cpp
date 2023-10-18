// 이진 트리를 상속받은 이진 탐색 트리(Binary Search Tree/BST) 확인
#include "BinarySearchTree.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	BSTree bstree;	// BSTree의 기능을 이용하기 위한 객체
	TreeNode* root;	// BST의 루트 노드

	// BST 생성 및 초기화
	bstree.MakeBSTree(&root);

	// BST 데이터 저장
	bstree.Insert(&root, 5);
	bstree.Insert(&root, 8);
	bstree.Insert(&root, 1);
	bstree.Insert(&root, 6);
	bstree.Insert(&root, 4);
	bstree.Insert(&root, 9);
	bstree.Insert(&root, 3);
	bstree.Insert(&root, 2);
	bstree.Insert(&root, 7);

	// BST 데이터 출력
	bstree.ShowAll(root);

	// 노드를 찾아서 제거
	TreeNode* node = bstree.Remove(&root, 3);
	delete node;
	bstree.ShowAll(root);

	node = bstree.Remove(&root, 8);
	delete node;
	bstree.ShowAll(root);

	node = bstree.Remove(&root, 1);
	delete node;
	bstree.ShowAll(root);

	node = bstree.Remove(&root, 6);
	delete node;
	bstree.ShowAll(root);

	return 0;
}