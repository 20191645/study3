// ��(Heap) ��� �켱���� ť(Priority Queue) ����
// "Heap.h, cpp" �����Ͽ� ������ -- Heap Ȱ���ϱ� ���Ͽ�
#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Heap.h"

// HData: �� ���� ������ �� �켱���� ť ������ -- string Ŭ����
// PriorityComp: �켱���� �񱳿� �Լ� ������ -- ���ڿ� ���̰� ª������ �켱���� ���ٰ� ����

class PQueue {
private:
	Heap heap;

public:
	PQueue(PriorityComp pc);
	~PQueue() {}

	bool isEmpty() const;
	void Enqueue(HData data);
	HData Dequeue();
};

#endif