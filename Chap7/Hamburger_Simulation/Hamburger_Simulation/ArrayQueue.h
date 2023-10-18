// �迭 ����� ���� ť(CircularQueue) ����
#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

const int arrLen = 100;
typedef int Data;

class ArrayQueue {
private:
	Data arr[arrLen];
	int front;	// �Ӹ�
	int rear;	// ����

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