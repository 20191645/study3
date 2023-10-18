// 힙(Heap) 기반 우선순위 큐(Priority Queue) 구현
// "Heap.h, cpp" 포함하여 컴파일 -- Heap 활용하기 위하여
#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Heap.h"

// HData: 힙 원소 데이터 겸 우선순위 큐 데이터
// PriorityComp: 우선순위 비교용 함수 포인터

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