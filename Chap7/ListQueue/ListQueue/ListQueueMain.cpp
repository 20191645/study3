// ���� ����Ʈ(LinkedList) ����� ť Ȯ��
#include "ListQueue.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	ListQueue queue;
	int data;

	// ť ������ ����
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);

	// ť ������ ����
	while (!queue.isEmpty()) {
		data = queue.Dequeue();
	}
	cout << endl;

	// ���� ť Ȯ���� ���� enqueue, dequeue �ݺ�
	queue.Enqueue(4);
	queue.Enqueue(2);
	queue.Dequeue();
	queue.Enqueue(3);
	queue.Dequeue();
	queue.Enqueue(1);
	queue.Enqueue(5);
	queue.Enqueue(7);

	// ť ������ ���
	while (!queue.isEmpty()) {
		data = queue.Dequeue();
	}
	cout << endl;

	return 0;
}