// 연결 리스트(LinkedList) 기반의 이진 트리(BinaryTree) 확인
#include "BinaryTree.h"
#include <iostream>

// Traverse 함수들의 매개변수용 함수
void ShowData(int data) {
	std::cout << data << ' ';
}

int main() {
	using std::cout;
	using std::endl;

	// 이진 트리 구현을 위한 함수 클래스
	BinaryTree tree;

	// 트리 노드 생성
	TreeNode* bt1 = tree.MakeNode();
	TreeNode* bt2 = tree.MakeNode();
	TreeNode* bt3 = tree.MakeNode();
	TreeNode* bt4 = tree.MakeNode();
	TreeNode* bt5 = tree.MakeNode();
	TreeNode* bt6 = tree.MakeNode();
	
	// 트리 노드 데이터 저장
	tree.SetData(bt1, 1);
	tree.SetData(bt2, 2);
	tree.SetData(bt3, 3);
	tree.SetData(bt4, 4);
	tree.SetData(bt5, 5);
	tree.SetData(bt6, 6);

	// 서브 트리 연결
	tree.MakeLeft(bt1, bt2);
	tree.MakeRight(bt1, bt3);
	tree.MakeLeft(bt2, bt4);
	tree.MakeRight(bt2, bt5);
	tree.MakeRight(bt3, bt6);

	// bt1의 왼쪽 자식 노드의 왼쪽 자식 노드 데이터 출력
	cout << tree.GetLeft(tree.GetLeft(bt1))->data << endl;

	// bt1 전위, 중위, 후위 순회 탐색
	cout << "전위 탐색: ";
	tree.PreOrderTraverse(bt1, ShowData);
	cout << endl;

	cout << "중위 탐색: ";
	tree.InOrderTraverse(bt1, ShowData);
	cout << endl;

	cout << "후위 탐색: ";
	tree.PostOrderTraverse(bt1, ShowData);
	cout << endl;

	// bt1을 루트 노드로 하는 모든 노드 삭제
	tree.DeleteTree(bt1);
	return 0;
}