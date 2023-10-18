// int�� ���� ����Ʈ(ArrayList) �˻�
// "ArrayList.h, cpp"�� �Բ� ������
#include <iostream>
#include "ArrayList.h"

int main() {
	// 1. ����Ʈ ���� �� �ʱ�ȭ
	ArrayList list;
	int data;

	// 2. ����Ʈ ������ ����
	for (int i = 1; i < 10; i++)
		list.insert(i);

	// 3. ����Ʈ �������� �� ���
	int sum = 0;
	if (list.first(&data)) {
		sum += data;
		while (list.next(&data))
			sum += data;
	}
	std::cout << "List�� ��� �������� ��: " << sum << std::endl << std::endl;

	// 4. ����Ʈ ������ ������� ���
	std::cout << "List�� ��� �������� ��: " << list.count() << std::endl;
	std::cout << "List�� ��� ������: ";
	if (list.first(&data)) {
		std::cout << data << ' ';
		while (list.next(&data))
			std::cout << data << ' ';
	}
	std::cout << std::endl << std::endl;

	// +. ����Ʈ Ư�� ������ ���� �� �ٽ� ���
	std::cout << "---List�� �ִ� 3�� ����---\n";
	if (list.first(&data)) {
		if (data == 3)
			list.remove();

		while (list.next(&data)) {
			if (data == 3)
				list.remove();
		}
	}
	std::cout << "List�� ��� �������� ��: " << list.count() << std::endl;
	std::cout << "List�� ��� ������: ";
	if (list.first(&data)) {
		std::cout << data << ' ';
		while (list.next(&data))
			std::cout << data << ' ';
	}

	return 0;
}