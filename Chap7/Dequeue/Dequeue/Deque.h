// ����� ���� ����Ʈ�� ������� ��(Deque) ����
#ifndef DEQUE_H_
#define DEQUE_H_

typedef int Data;

class Deque {
private:
	struct Node {
		Data data;
		Node* prev;	// ���� ���
		Node* next;	// ���� ���
	};
	Node* head;	// �Ӹ�
	Node* tail;	// ����

public:
	Deque();
	~Deque();

	bool isEmpty() const;
	void AddFirst(Data data);
	void AddLast(Data data);
	Data RemoveFirst();
	Data RemoveLast();
	Data GetFirst() const;
	Data GetLast() const;
};

#endif