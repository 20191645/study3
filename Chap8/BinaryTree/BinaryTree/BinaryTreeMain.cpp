// ���� ����Ʈ(LinkedList) ����� ���� Ʈ��(BinaryTree) Ȯ��
#include "BinaryTree.h"
#include <iostream>

// Traverse �Լ����� �Ű������� �Լ�
void ShowData(int data) {
	std::cout << data << ' ';
}

int main() {
	using std::cout;
	using std::endl;

	// ���� Ʈ�� ������ ���� �Լ� Ŭ����
	BinaryTree tree;

	// Ʈ�� ��� ����
	TreeNode* bt1 = tree.MakeNode();
	TreeNode* bt2 = tree.MakeNode();
	TreeNode* bt3 = tree.MakeNode();
	TreeNode* bt4 = tree.MakeNode();
	TreeNode* bt5 = tree.MakeNode();
	TreeNode* bt6 = tree.MakeNode();
	
	// Ʈ�� ��� ������ ����
	tree.SetData(bt1, 1);
	tree.SetData(bt2, 2);
	tree.SetData(bt3, 3);
	tree.SetData(bt4, 4);
	tree.SetData(bt5, 5);
	tree.SetData(bt6, 6);

	// ���� Ʈ�� ����
	tree.MakeLeft(bt1, bt2);
	tree.MakeRight(bt1, bt3);
	tree.MakeLeft(bt2, bt4);
	tree.MakeRight(bt2, bt5);
	tree.MakeRight(bt3, bt6);

	// bt1�� ���� �ڽ� ����� ���� �ڽ� ��� ������ ���
	cout << tree.GetLeft(tree.GetLeft(bt1))->data << endl;

	// bt1 ����, ����, ���� ��ȸ Ž��
	cout << "���� Ž��: ";
	tree.PreOrderTraverse(bt1, ShowData);
	cout << endl;

	cout << "���� Ž��: ";
	tree.InOrderTraverse(bt1, ShowData);
	cout << endl;

	cout << "���� Ž��: ";
	tree.PostOrderTraverse(bt1, ShowData);
	cout << endl;

	// bt1�� ��Ʈ ���� �ϴ� ��� ��� ����
	tree.DeleteTree(bt1);
	return 0;
}