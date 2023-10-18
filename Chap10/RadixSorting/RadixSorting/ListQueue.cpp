// ���� ����Ʈ(LinkedList) ����� ť ����
#include "ListQueue.h"
#include <iostream>
#include <cstdlib>

// ������ - ť �ʱ�ȭ
ListQueue::ListQueue() {
	front = rear = NULL;
}

// �ı��� - ť ����
ListQueue::~ListQueue() {
	Node* temp = front;
	while (temp != NULL) {
		front = front->next;
		delete temp;
		temp = front;
	}
}

// ť�� ����ִ��� Ȯ��
bool ListQueue::isEmpty() const {
	return front == NULL;
}

// rear�� ������ ����
void ListQueue::Enqueue(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;

	// ť�� ù ������ ���
	if (isEmpty())
		front = rear = temp;
	else {
		rear->next = temp;
		rear = temp;
	}
}

// front�� �ش��ϴ� ������ ���� �� ��ȯ -- �����Ͱ� �ϳ� �̻��̾�� �Ѵ�
Data ListQueue::Dequeue() {
	if (isEmpty()) {
		std::cout << "ť�� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	Node* temp = front;
	Data data = temp->data;

	// ť�� ���Ұ� �ϳ��� ���
	if (front == rear)
		rear = NULL;
	front = front->next;

	delete temp;
	return data;
}

// front�� �ش��ϴ� ������ ��ȯ -- �����Ͱ� �ϳ� �̻��̾�� �Ѵ�
Data ListQueue::Peek() const {
	if (isEmpty()) {
		std::cout << "ť�� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	return front->data;
}