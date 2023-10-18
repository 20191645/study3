// int�� ���� ����Ʈ(LinkedList) ��� ���� ����
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