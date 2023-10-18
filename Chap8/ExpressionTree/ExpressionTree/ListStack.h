// 연결 리스트(LinkedList) 기반 스택 구현
#ifndef LISTSTACK_H_
#define LISTSTACK_H_

// TreeNode 선언을 위한 헤더파일
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
	Node* head;	// 머리 노드

public:
	ListStack();
	~ListStack();

	bool isEmpty() const;
	void Push(Data data);
	Data Pop();
	Data Peek() const;
};

#endif