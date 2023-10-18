// AVL 트리 구현 확인
#include "AVLTree.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	AVLTree avltree;	// AVLTree의 기능을 이용하기 위한 객체
	TreeNode* root;		// AVLTree의 루트 노드
	TreeNode* lnode;	// 왼쪽 노드
	TreeNode* rnode;	// 오른쪽 노드

	// AVLTree 초기화
	avltree.MakeBSTree(&root);

	// AVLTree 데이터 저장
	avltree.Insert(&root, 1);
	avltree.Insert(&root, 2);
	avltree.Insert(&root, 3);
	avltree.Insert(&root, 4);
	avltree.Insert(&root, 5);
	avltree.Insert(&root, 6);
	avltree.Insert(&root, 7);
	avltree.Insert(&root, 8);
	avltree.Insert(&root, 9);

	// 현재 AVLTree 정보 출력
	cout << "루트 노드: " << avltree.GetData(root) << endl;
	lnode = avltree.GetLeft(root);
	rnode = avltree.GetRight(root);
	cout << "왼쪽 노드: " << avltree.GetData(lnode)
		<< ", 오른쪽 노드: " << avltree.GetData(rnode) << endl;
	
	lnode = avltree.GetLeft(lnode);
	rnode = avltree.GetRight(rnode);
	cout << "왼쪽2 노드: " << avltree.GetData(lnode)
		<< ", 오른쪽2 노드: " << avltree.GetData(rnode) << endl;

	lnode = avltree.GetLeft(lnode);
	rnode = avltree.GetRight(rnode);
	cout << "왼쪽3 노드: " << avltree.GetData(lnode)
		<< ", 오른쪽3 노드: " << avltree.GetData(rnode) << endl;

	lnode = avltree.GetLeft(lnode);
	rnode = avltree.GetRight(rnode);
	cout << "왼쪽4 노드: " << avltree.GetData(lnode)
		<< ", 오른쪽4 노드: " << avltree.GetData(rnode) << endl;

	return 0;
}