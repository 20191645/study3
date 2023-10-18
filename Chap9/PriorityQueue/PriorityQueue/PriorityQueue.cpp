// ��(Heap) ��� �켱���� ť(Priority Queue) ����
#include "PriorityQueue.h"

// ������ - �켱���� ť �ʱ�ȭ
PQueue::PQueue(PriorityComp pc)
	:heap(pc) {
	// Heap �ʱ�ȭ
}

// �켱���� ť�� ����ִ��� Ȯ��
bool PQueue::isEmpty() const {
	return heap.isEmpty();
}

// �켱���� ť ������ ����
void PQueue::Enqueue(HData data) {
	heap.Insert(data);
}

// �켱���� ���� ���� ������ ���� �� ��ȯ
HData PQueue::Dequeue() {
	return heap.Delete();
}