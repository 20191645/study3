// �迭 ����� ���� ť(CircularQueue) ����
#include "ArrayQueue.h"
#include <iostream>
#include <cstdlib>

// ť�� ����ִ��� Ȯ��
bool ArrayQueue::isEmpty() const {
	return front == rear;
}

// rear�� ������ ����
void ArrayQueue::Enqueue(Data data) {
	// ť�� �����ִ� ���
	if (front - rear == 1 || rear - front == arrLen - 1) {
		std::cout << "ť�� �����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}
	
	arr[rear] = data;
	// rear�� �迭�� ������ �ε����� ���
	if (rear == arrLen - 1) {
		rear = 0;
	}
	else {
		rear++;
	}

	// ������ Ȯ���ϱ� ���� �޽���
	std::cout << "arr[" << rear << "]�� "
		<< data << " ����!\n";
}

// front�� �ش��ϴ� ������ ���� �� ��ȯ -- �����Ͱ� �ϳ� �̻��̾�� �Ѵ�
Data ArrayQueue::Dequeue() {
	if (isEmpty()) {
		std::cout << "ť�� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	Data data = arr[front];
	// front�� �迭�� ������ �ε����� ���
	if (front == arrLen - 1) {
		front = 0;
	}
	else {
		front++;
	}

	// ������ Ȯ���ϱ� ���� �޽���
	std::cout << "arr[" << front << "]���� "
		<< data << " ����!\n";
	return data;
}

// front�� �ش��ϴ� ������ ��ȯ -- �����Ͱ� �ϳ� �̻��̾�� �Ѵ�
Data ArrayQueue::Peek() const {
	if (isEmpty()) {
		std::cout << "ť�� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	// front�� �迭�� ������ �ε����� ���
	if (front == arrLen - 1) {
		return arr[0];
	}
	else {
		return arr[front + 1];
	}
}