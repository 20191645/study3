// 연결 리스트(LinkedList) 기반의 이진 트리(BinaryTree) 구현
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

typedef int TData;
// Traverse 함수들을 위한 함수 포인터
typedef void (*Function)(TData data);

// 이진 트리 정의 구조체
struct TreeNode {
	TData data;
	TreeNode* left;		// 왼쪽 자식
	TreeNode* right;	// 오른쪽 자식
};

// 이진 트리 ADT
class BinaryTree {
public:
	BinaryTree() {}
	~BinaryTree() {}

	TreeNode* MakeNode();
	TData GetData(TreeNode* bt);
	void SetData(TreeNode* bt, TData data);
	TreeNode* GetLeft(TreeNode* bt);
	TreeNode* GetRight(TreeNode* bt);
	void MakeLeft(TreeNode* main, TreeNode* sub);
	void MakeRight(TreeNode* main, TreeNode* sub);

	void DeleteTree(TreeNode* bt);

	void PreOrderTraverse(TreeNode* bt, Function func);
	void InOrderTraverse(TreeNode* bt, Function func);
	void PostOrderTraverse(TreeNode* bt, Function func);
};

#endif