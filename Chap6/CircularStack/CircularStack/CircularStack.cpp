// Chap5���� �̹� �����ߴ� ���� ���� ����Ʈ�� Ȱ���Ͽ� ���� ����
#include "CircularStack.h"
#include "CircularLinkedList.h"

// ������ ����ִ��� Ȯ��
bool CircularStack::isEmpty() {
	return list.LCount() == 0;
}

// ���ÿ� ������ ���� -- head ������ �߰� ���
void CircularStack::Push(Data data) {
	list.LInsertHead(data);
}

// ������ ���(head) ���� �� ��ȯ -- �����Ͱ� �ϳ� �̻��� �� ȣ��
Data CircularStack::Pop() {
	// CircularLinkedList�� cur�� tail->next[��, head]�� ����Ű���� ����
	Data data;
	list.LFirst(&data);

	return list.LRemove();
}

// ������ ���(head) ��ȯ -- �����Ͱ� �ϳ� �̻��� �� ȣ��
Data CircularStack::Peek() {
	Data data = list.LFirst(&data);
	return data;
}