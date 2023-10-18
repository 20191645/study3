// ���� ����Ʈ(LinkedList) ��� ���� ����
#include "ListStack.h"
#include <iostream>
#include <cstdlib>


// ������ -- ���� �ʱ�ȭ
ListStack::ListStack() {
	head = NULL;
}

// �ı���
ListStack::~ListStack() {
	Node* temp = head;
	while (temp != NULL) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// ������ ����ִ��� Ȯ��
bool ListStack::isEmpty() const {
	return head == NULL;
}

// ���ÿ� ������ ���� -- head ������ �߰� ���
void ListStack::Push(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

// ������ ���(head) ���� �� ��ȯ -- �����Ͱ� �ϳ� �̻��� �� ȣ��
Data ListStack::Pop() {
	if (isEmpty()) {
		std::cout << "������ ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	// temp: ������ Node
	Node* temp = head;
	Data data = temp->data;
	head = temp->next;
	delete temp;

	return data;
}

// ������ ���(head) ��ȯ -- �����Ͱ� �ϳ� �̻��� �� ȣ��
Data ListStack::Peek() const {
	if (isEmpty()) {
		std::cout << "������ ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	return head->data;
}