// int�� ���� ���� ����Ʈ(Singly LinkedList) Ȯ��
#include <iostream>
#include "CircularLinkedList.h"

int main() {
	CircularList list;
	int data;

	// ����Ʈ ����
	list.LInsertTail(3);
	list.LInsertTail(4);
	list.LInsertTail(5);
	list.LInsertHead(2);
	list.LInsertHead(1);

	// ����Ʈ ���� 3ȸ ���
	std::cout << "���� ����Ʈ�� ������ ��: " << list.LCount() << std::endl;
	if (list.LFirst(&data)) {
		std::cout << data << ' ';
		for (int i = 1; i < list.LCount() * 3; i++) {
			if (list.LNext(&data))
				std::cout << data << ' ';
		}
	}
	std::cout << std::endl;

	// 2�� ��� ������ ����
	std::cout << "2�� ��� ����\n";
	if (list.LFirst(&data)) {
		if (data % 2 == 0)
			list.LRemove();
		for (int i = 1; i < list.LCount(); i++) {
			list.LNext(&data);
			if (data % 2 == 0)
				list.LRemove();
		}
	}

	// ����Ʈ 1ȸ ���
	std::cout << "���� ����Ʈ�� ������ ��: " << list.LCount() << std::endl;
	if (list.LFirst(&data)) {
		std::cout << data << ' ';
		for (int i = 1; i < list.LCount(); i++) {
			if (list.LNext(&data))
				std::cout << data << ' ';
		}
	}
	std::cout << std::endl;

	return 0;
}