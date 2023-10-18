// int�� ����� ���� ����Ʈ(DoublyLinkedList) Ȯ�� -- tail ������ �߰� ���
#include <iostream>
#include "DoublyLinkedList.h"

int main() {
	using std::cout;
	using std::endl;

	DoublyList list;
	int data;

	// ����Ʈ ����
	list.LInsert(15);
	list.LInsert(11);
	list.LInsert(22);
	list.LInsert(10);
	list.LInsert(22);
	list.LInsert(33);

	// ����Ʈ ���
	std::cout << "���� ����Ʈ�� ������ ��: " << list.LCount() << std::endl;
	if (list.LFirst(&data)) {
		std::cout << data << ' ';
		while (list.LNext(&data))
			std::cout << data << ' ';
	}
	std::cout << std::endl;

	// Ư�� ������ ����
	std::cout << "���� 22 ����\n";
	if (list.LFirst(&data)) {
		if (data == 22)
			list.LRemove();
		while (list.LNext(&data)) {
			if (data == 22)
				list.LRemove();
		}
	}

	// ����Ʈ ���
	std::cout << "���� ����Ʈ�� ������ ��: " << list.LCount() << std::endl;
	if (list.LFirst(&data)) {
		std::cout << data << ' ';
		while (list.LNext(&data))
			std::cout << data << ' ';
	}

	return 0;
}