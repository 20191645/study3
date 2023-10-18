// AVL 트리 -- BST를 상속하여 리밸런싱 기능을 추가한 AVL Tree 구현
// 이진 탐색 트리를 상속하기 위해 "BinarySearchTree.h, cpp", "BinaryTree.h, cpp"와 함께 컴파일
#include "BinarySearchTree.h"

// AVL 트리를 구현하기 
class AVLTree: public BSTree{
public:
	// 함수 오버라이딩 -- BSTree의 함수
	void Insert(TreeNode** root, BTData data);
	TreeNode* Remove(TreeNode** root, BTData data);

	// 리밸런싱에 필요한 기능 함수
	TreeNode* Rebalance(TreeNode** root);
	int GetHeight(TreeNode* bst);
	int GetHeightDiff(TreeNode* bst);
	TreeNode* RotateLL(TreeNode* bst);
	TreeNode* RotateRR(TreeNode* bst);
	TreeNode* RotateLR(TreeNode* bst);
	TreeNode* RotateRL(TreeNode* bst);
};