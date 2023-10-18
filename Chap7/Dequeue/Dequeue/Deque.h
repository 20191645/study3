// 양방향 연결 리스트를 기반으로 덱(Deque) 구현
#ifndef DEQUE_H_
#define DEQUE_H_

typedef int Data;

class Deque {
private:
	struct Node {
		Data data;
		Node* prev;	// 이전 노드
		Node* next;	// 다음 노드
	};
	Node* head;	// 머리
	Node* tail;	// 꼬리

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