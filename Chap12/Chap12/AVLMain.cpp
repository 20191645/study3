// AVL Ʈ�� ���� Ȯ��
#include "AVLTree.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	AVLTree avltree;	// AVLTree�� ����� �̿��ϱ� ���� ��ü
	TreeNode* root;		// AVLTree�� ��Ʈ ���
	TreeNode* lnode;	// ���� ���
	TreeNode* rnode;	// ������ ���

	// AVLTree �ʱ�ȭ
	avltree.MakeBSTree(&root);

	// AVLTree ������ ����
	avltree.Insert(&root, 1);
	avltree.Insert(&root, 2);
	avltree.Insert(&root, 3);
	avltree.Insert(&root, 4);
	avltree.Insert(&root, 5);
	avltree.Insert(&root, 6);
	avltree.Insert(&root, 7);
	avltree.Insert(&root, 8);
	avltree.Insert(&root, 9);

	// ���� AVLTree ���� ���
	cout << "��Ʈ ���: " << avltree.GetData(root) << endl;
	lnode = avltree.GetLeft(root);
	rnode = avltree.GetRight(root);
	cout << "���� ���: " << avltree.GetData(lnode)
		<< ", ������ ���: " << avltree.GetData(rnode) << endl;
	
	lnode = avltree.GetLeft(lnode);
	rnode = avltree.GetRight(rnode);
	cout << "����2 ���: " << avltree.GetData(lnode)
		<< ", ������2 ���: " << avltree.GetData(rnode) << endl;

	lnode = avltree.GetLeft(lnode);
	rnode = avltree.GetRight(rnode);
	cout << "����3 ���: " << avltree.GetData(lnode)
		<< ", ������3 ���: " << avltree.GetData(rnode) << endl;

	lnode = avltree.GetLeft(lnode);
	rnode = avltree.GetRight(rnode);
	cout << "����4 ���: " << avltree.GetData(lnode)
		<< ", ������4 ���: " << avltree.GetData(rnode) << endl;

	return 0;
}