// int형 연결 리스트(LinkedList) 기반 스택 구현
#ifndef LISTSTACK_H_
#define LISTSTACK_H_

const int ArrLen = 10;
typedef int Data;

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