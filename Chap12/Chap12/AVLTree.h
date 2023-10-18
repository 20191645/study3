// AVL Ʈ�� -- BST�� ����Ͽ� ���뷱�� ����� �߰��� AVL Tree ����
// ���� Ž�� Ʈ���� ����ϱ� ���� "BinarySearchTree.h, cpp", "BinaryTree.h, cpp"�� �Բ� ������
#include "BinarySearchTree.h"

// AVL Ʈ���� �����ϱ� 
class AVLTree: public BSTree{
public:
	// �Լ� �������̵� -- BSTree�� �Լ�
	void Insert(TreeNode** root, BTData data);
	TreeNode* Remove(TreeNode** root, BTData data);

	// ���뷱�̿� �ʿ��� ��� �Լ�
	TreeNode* Rebalance(TreeNode** root);
	int GetHeight(TreeNode* bst);
	int GetHeightDiff(TreeNode* bst);
	TreeNode* RotateLL(TreeNode* bst);
	TreeNode* RotateRR(TreeNode* bst);
	TreeNode* RotateLR(TreeNode* bst);
	TreeNode* RotateRL(TreeNode* bst);
};