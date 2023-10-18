// �ܼ� ���� ����Ʈ(Singly LinkedList ����) - head ������ �߰� ���
#include "LinkedList1.h"
#include <iostream>

// ������ - ����Ʈ �ʱ�ȭ
LinkedList::LinkedList() {
	count = 0;
	order = NULL;

	// head: ���� ���(��ȭ X)
	head = new Node;
	head->next = NULL;
}

// �ı��� - ����Ʈ ����
LinkedList::~LinkedList() {
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
void LinkedList::LInsert(LData data) {
	// ����Ʈ ���� ���� ������ = head�ʿ� ������ ����
	if (order == NULL) {
		Node* temp = new Node;
		temp->data = data;
		temp->next = head->next;
		head->next = temp;
	}

	// ����Ʈ ���� ���� ������ = ���� ���ؿ� ���� ����
	else {
		// temp: �߰��� Node, loc: ������ ��ġ Node
		Node* temp = new Node;
		temp->data = data;
		Node* loc = head;

		// ���� Node�� �����ϰ�, �� Node�� �����Ͱ����� ���� ���� ���϶� �ݺ�
		while (loc->next != NULL && order(temp->data, loc->next->data)) {
			loc = loc->next;
		}
		temp->next = loc->next;
		loc->next = temp;
	}

	count++;
}

// ù ��° �����͸� pdata�� ����
bool LinkedList::LFirst(LData* pdata) {
	if (head->next == NULL)
		return false;
	else {
		cur = head->next;
		*pdata = cur->data;
		return true;
	}
}

// ���� �������� ���� �����͸� pdata�� ����
bool LinkedList::LNext(LData* pdata) {
	if (cur->next == NULL)
		return false;
	else {
		cur = cur->next;
		*pdata = cur->data;
		return true;
	}
}

// ���� ����Ű�� ������ ����
LData LinkedList::LRemove() {	
	LData data = cur->data;

	// temp: �����Ϸ��� Node �ٷ� ���� Node
	Node* temp = head;
	while (temp->next != cur)
		temp = temp->next;

	cur = temp;
	temp = temp->next;
	cur->next = temp->next;
	
	delete temp;
	count--;
	return data;
}

// ����Ʈ�� ����� ������ �� ��ȯ
int LinkedList::LCount() const {
	return count;
}

// ����Ʈ�� ���� ������ �Ǵ� �Լ� ���
void LinkedList::SetSortRule(int(*func)(LData d1, LData d2)) {
	order = func;
}