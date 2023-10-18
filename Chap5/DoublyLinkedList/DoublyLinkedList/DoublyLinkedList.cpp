// ����� ���� ����Ʈ(DoublyLinkedList) ���� -- tail ������ �߰� ���
#include "DoublyLinkedList.h"
#include <iostream>

// ������ - ����Ʈ �ʱ�ȭ
DoublyList::DoublyList() {
	count = 0;
	cur = NULL;

	// head, tail: ���� ���(��ȭ X)
	head = new Node;
	tail = new Node;
	
	head->prev = NULL;
	head->next = tail;
	
	tail->prev = head;
	tail->next = NULL;
}

// �ı��� - ����Ʈ ����
DoublyList::~DoublyList() {
	if (count > 0) {
		Node* temp = head;
		while (temp != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
	}
}

// ����Ʈ�� ������ ����
void DoublyList::LInsert(LData data) {
	// temp: tail�� �߰��Ǵ� Node
	Node* temp = new Node;
	temp->data = data;
	temp->next = tail;
	temp->prev = tail->prev;

	(tail->prev)->next = temp;
	tail->prev = temp;

	count++;
}

// ù ��° �����͸� pdata�� ����
bool DoublyList::LFirst(LData* pdata) {
	// head, tail�� ���� ��尡 ���θ� ����Ű�� ���
	if (head->next == tail)
		return false;
	else {
		cur = head->next;
		*pdata = cur->data;
		return true;
	}
}

// ���� �������� ���� �����͸� pdata�� ����
bool DoublyList::LNext(LData* pdata) {
	// ���� ��尡 tail�� ����Ű�� ���
	if (cur->next == tail)
		return false;
	else {
		cur = cur->next;
		*pdata = cur->data;
		return true;
	}
}

// ���� ����Ű�� ������ ����
LData DoublyList::LRemove() {
	LData data = cur->data;

	// temp: �����Ϸ��� Node
	Node* temp = cur;
	cur = cur->prev;
	cur->next = temp->next;
	(temp->next)->prev = cur;
	delete temp;

	count--;
	return data;
}

// ����Ʈ�� ����� ������ �� ��ȯ
int DoublyList::LCount() const {
	return count;
}