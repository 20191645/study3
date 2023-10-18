// ���� ���� ����Ʈ(CircularLinkedList) ���� -- head/tail ������ �߰� ���� ���
#include "CircularLinkedList.h"
#include <iostream>

// ������ - ����Ʈ �ʱ�ȭ
CircularList::CircularList() {
	count = 0;
	// ������ head = tail->next
	cur = tail = NULL;
}

// �ı��� - ����Ʈ ����
CircularList::~CircularList() {
	if (count > 0) {
		Node* temp = tail->next;
		while (temp != tail) {
			tail->next = temp->next;
			delete temp;
			temp = tail->next;
		}
		delete tail;
	}
}

// head�ʿ� ������ ���� -- head�� ���ο� Node�� ����
void CircularList::LInsertHead(LData data) {
	Node* temp = new Node;
	temp->data = data;
	
	// ����Ʈ ù ����
	if (tail == NULL) {
		temp->next = temp;
		tail = temp;
	}
	else {
		temp->next = tail->next;
		tail->next = temp;
	}

	count++;
}

// tail�ʿ� ������ ���� -- tail�� ���ο� Node�� ����
void CircularList::LInsertTail(LData data) {
	Node* temp = new Node;
	temp->data = data;

	// ����Ʈ ù ����
	if (tail == NULL) {
		temp->next = temp;
		tail = temp;
	}
	else {
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}

	count++;
}

// ù ��° �����͸� pdata�� ����
bool CircularList::LFirst(LData* pdata) {
	if (tail == NULL)
		return false;
	else {
		cur = tail->next;
		*pdata = cur->data;
		return true;
	}
}

// ���� �������� ���� �����͸� pdata�� ���� -- �����̱� ������ ���� �ݺ� ����
bool CircularList::LNext(LData* pdata) {
	if (tail == NULL)
		return false;
	else {
		cur = cur->next;
		*pdata = cur->data;
		return true;
	}
}

// ���� ����Ű�� ������ ����
LData CircularList::LRemove() {
	LData data = cur->data;
	// temp: �����Ϸ��� Node �ٷ� ���� Node
	Node* temp = tail;

	// ����Ʈ�� Node�� 1���� ���
	if (tail == tail->next) {
		tail = NULL;
	}

	while (temp->next != cur)
		temp = temp->next;
	
	// �����Ϸ��� Node�� tail�� ���
	if (cur == tail)
		tail = temp;

	cur = temp;
	temp = temp->next;
	cur->next = temp->next;

	delete temp;
	count--;
	return data;
}

// ����Ʈ�� ����� ������ �� ��ȯ
int CircularList::LCount() const {
	return count;
}