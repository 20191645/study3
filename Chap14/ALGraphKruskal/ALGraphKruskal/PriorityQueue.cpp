// 힙(Heap) 기반 우선순위 큐(Priority Queue) 구현
#include "PriorityQueue.h"

// 생성자 - 우선순위 큐 초기화
PQueue::PQueue(PriorityComp pc)
	:heap(pc) {
	// Heap 초기화
}

// 우선순위 큐가 비어있는지 확인
bool PQueue::isEmpty() const {
	return heap.isEmpty();
}

// 우선순위 큐 데이터 저장
void PQueue::Enqueue(HData data) {
	heap.Insert(data);
}

// 우선순위 가장 높은 데이터 삭제 후 반환
HData PQueue::Dequeue() {
	return heap.Delete();
}