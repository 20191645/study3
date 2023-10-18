// ���� ����Ʈ(LinkedList) ����� ť ����
#ifndef LISTQUEUE_H_
#define LISTQUEUE_H_

typedef int Data;
class ListQueue {
private:
	struct Node {
		Data data;
		Node* next;
	};

	Node* front;	// �Ӹ�
	Node* rear;		// ����

public:
	ListQueue();
	~ListQueue();

	bool isEmpty() const;
	void Enqueue(Data data);
	Data Dequeue();
	Data Peek() const;
};

#endif