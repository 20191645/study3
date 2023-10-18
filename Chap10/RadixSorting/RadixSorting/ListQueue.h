// 연결 리스트(LinkedList) 기반의 큐 구현
#ifndef LISTQUEUE_H_
#define LISTQUEUE_H_

typedef int Data;
class ListQueue {
private:
	struct Node {
		Data data;
		Node* next;
	};

	Node* front;	// 머리
	Node* rear;		// 꼬리

public:
	ListQueue();
	~ListQueue();

	bool isEmpty() const;
	void Enqueue(Data data);
	Data Dequeue();
	Data Peek() const;
};

#endif