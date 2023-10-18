// 배열 기반의 원형 큐(CircularQueue) 구현
#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

const int arrLen = 100;
typedef int Data;

class ArrayQueue {
private:
	Data arr[arrLen];
	int front;	// 머리
	int rear;	// 꼬리

public:
	ArrayQueue() :front(0), rear(0) {}
	~ArrayQueue() {}

	bool isEmpty() const;
	bool isFull() const;
	void Enqueue(Data data);
	Data Dequeue();
	Data Peek() const;
};

#endif