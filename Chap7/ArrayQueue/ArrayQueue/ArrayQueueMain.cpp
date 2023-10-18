/*
	�迭 ����� ���� ť(CircularQueue) ���� Ȯ��
	- �迭�� ���̰� n�̸� �����Ͱ� n-1�� ä������ �� ���� ������ ����
	- (��, front�� rear�� �ε��� ���̰� ��ĭ�� ��)
	- front�� rear�� ���� ���̸� �� ������ ����
	- �̸� ���� front�� ����Ű�� �迭�� �׻� ����д�
	- ���԰� ������ Ȯ���ϱ� ���� Enqueue(), Dequeue()�� �޽��� �߰�
*/
#include "ArrayQueue.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	ArrayQueue queue;
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