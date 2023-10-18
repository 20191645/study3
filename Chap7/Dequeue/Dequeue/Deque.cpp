// ����� ���� ����Ʈ�� ������� ��(Deque) ����
#include "Deque.h"
#include <iostream>
#include <cstdlib>

// ������ -- �� �ʱ�ȭ
Deque::Deque() {
	head = tail = NULL;
}

// �ı��� - �� ����
Deque::~Deque() {
	Node* temp = head;
	while (temp != NULL) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// ���� ����ִ��� Ȯ��
bool Deque::isEmpty() const {
	return (head == NULL);
}

// head�� ������ ����
void Deque::AddFirst(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->prev = NULL;
	temp->next = head;

	// ���� ����ִ� ���
	if (isEmpty()) {
		head = tail = temp;
	}
	else {
		head->prev = temp;
		head = temp;
	}
}

// tail�� ������ ����
void Deque::AddLast(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	temp->prev = tail;

	// ���� ����ִ� ���
	if (isEmpty()) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

// head ������ ���� �� ��ȯ -- ������ �ϳ� �̻��̾�� ��
Data Deque::RemoveFirst() {
	if (isEmpty()) {
		std::cout << "���� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	Node* temp = head;
	Data data = temp->data;
	head = head->next;
	delete temp;

	// �� ���Ұ� �ϳ����� ���
	if (head == NULL)
		tail = NULL;
	else {
		head->prev = NULL;
	}

	return data;
}

// tail ������ ���� �� ��ȯ -- ������ �ϳ� �̻��̾�� ��
Data Deque::RemoveLast() {
	if (isEmpty()) {
		std::cout << "���� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	Node* temp = tail;
	Data data = temp->data;
	tail = tail->prev;
	delete temp;

	// �� ���Ұ� �ϳ����� ���
	if (tail == NULL)
		head = NULL;
	else {
		tail->next = NULL;
	}

	return data;
}

// head ������ ��ȯ -- ������ �ϳ� �̻��̾�� ��
Data Deque::GetFirst() const {
	if (isEmpty()) {
		std::cout << "���� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	return head->data;
}

// tail ������ ��ȯ -- ������ �ϳ� �̻��̾�� ��
Data Deque::GetLast() const {
	if (isEmpty()) {
		std::cout << "���� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	return tail->data;
}