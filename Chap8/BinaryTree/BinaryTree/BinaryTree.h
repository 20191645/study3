// ���� ����Ʈ(LinkedList) ����� ���� Ʈ��(BinaryTree) ����
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

typedef int TData;
// Traverse �Լ����� ���� �Լ� ������
typedef void (*Function)(TData data);

// ���� Ʈ�� ���� ����ü
struct TreeNode {
	TData data;
	TreeNode* left;		// ���� �ڽ�
	TreeNode* right;	// ������ �ڽ�
};

// ���� Ʈ�� ADT
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