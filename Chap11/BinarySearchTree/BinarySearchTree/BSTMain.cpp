// ���� Ʈ���� ��ӹ��� ���� Ž�� Ʈ��(Binary Search Tree/BST) Ȯ��
#include "BinarySearchTree.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	BSTree bstree;	// BSTree�� ����� �̿��ϱ� ���� ��ü
	TreeNode* root;	// BST�� ��Ʈ ���

	// BST ���� �� �ʱ�ȭ
	bstree.MakeBSTree(&root);

	// BST ������ ����
	bstree.Insert(&root, 5);
	bstree.Insert(&root, 8);
	bstree.Insert(&root, 1);
	bstree.Insert(&root, 6);
	bstree.Insert(&root, 4);
	bstree.Insert(&root, 9);
	bstree.Insert(&root, 3);
	bstree.Insert(&root, 2);
	bstree.Insert(&root, 7);

	// BST ������ ���
	bstree.ShowAll(root);

	// ��带 ã�Ƽ� ����
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