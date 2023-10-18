// ��(Heap) ��� �켱���� ť(Priority Queue) ����
// "Heap.h, cpp" �����Ͽ� ������ -- Heap Ȱ���ϱ� ���Ͽ�
#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Heap.h"

// HData: �� ���� ������ �� �켱���� ť ������
// PriorityComp: �켱���� �񱳿� �Լ� ������

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