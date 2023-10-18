// int�� �ܼ� ���� ����Ʈ(Singly LinkedList) Ȯ��
// "LinkedList1.h, cpp" -- head ������ �߰� ���
// "LinkedList2.h, cpp" -- tail ������ �߰� ���
// �����Ϸ��� �� ��� �� �ϳ��� �ڵ带 �����Ͽ��� ���ܽ�Ű�� ����
#include <iostream>
//#include "LinkedList1.h"
#include "LinkedList2.h"

// ���� ���� �Լ�
int SortOrder(int d1, int d2) {
	if (d1 < d2)
		return 0;	// d1�� ���� ������ ���̴�
	else
		return 1;	// d2�� ���� ������ ���̴�
}

int main() {
	LinkedList list;
	int data;

	// ����Ʈ ���� ���� ���� -- ���� ���ϸ� NULL
	list.SetSortRule(SortOrder);

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