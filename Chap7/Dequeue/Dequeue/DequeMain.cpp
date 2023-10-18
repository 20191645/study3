// ����� ���� ����Ʈ�� ������� ��(Deque) Ȯ��
#include "Deque.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	Deque deque;
	int data;

	// �� ������ ����
	deque.AddFirst(3);
	deque.AddFirst(2);
	deque.AddFirst(1);

	deque.AddLast(4);
	deque.AddLast(5);
	deque.AddLast(6);

	// ������ ���� -- head
	while (!deque.isEmpty()) {
		data = deque.RemoveFirst();
		cout << data << ' ';
	}
	cout << endl;

	// �� ������ ����
	deque.AddFirst(3);
	deque.AddFirst(2);
	deque.AddFirst(1);

	deque.AddLast(4);
	deque.AddLast(5);
	deque.AddLast(6);

	// ������ ���� -- tail
	while (!deque.isEmpty()) {
		data = deque.RemoveLast();
		cout << data << ' ';
	}
	cout << endl;

	return 0;
}