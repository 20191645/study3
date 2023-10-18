// ���� ����Ʈ(LinkedList) ��� ���� ����
#ifndef LISTSTACK_H_
#define LISTSTACK_H_

// TreeNode ������ ���� �������
#include "BinaryTree.h"	

const int ArrLen = 10;

// Data: TreeNode*
typedef TreeNode* Data;

class ListStack {
private:
	struct Node {
		Data data;
		Node* next;
	};
	Node* head;	// �Ӹ� ���

public:
	ListStack();
	~ListStack();

	bool isEmpty() const;
	void Push(Data data);
	Data Pop();
	Data Peek() const;
};

#endif