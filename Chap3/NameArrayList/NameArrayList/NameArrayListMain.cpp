// NameCard�� ���� ����Ʈ(ArrayList) Ȯ��
// "NameArrayList.h, cpp"�� �Բ� ������
#include <iostream>
#include "NameArrayList.h"
#include "NameCard.h"

int main() {
	ArrayList list;
	NameCard p1;
	NameCard p2("������", "010-1555-3222");
	NameCard p3("������");
	NameCard p4("�迵ö");
	NameCard p5("������", "010-5555-3333");

	// 1. �� 5���� ������ ����Ʈ�� ����
	list.insert(p1);
	list.insert(p2);
	list.insert(p3);
	list.insert(p4);
	list.insert(p5);

	// 2. Ư�� �̸��� Ž���Ͽ� ���� ���
	NameCard temp;
	if (list.first(&temp)) {
		if (!temp.NameCompare("������"))
			temp.ShowNameCardInfo();

		while (list.next(&temp)) {
			if (!temp.NameCompare("������"))
				temp.ShowNameCardInfo();
		}
	}
	std::cout << std::endl;

	// 3. Ư�� �̸��� Ž���Ͽ� ��ȭ��ȣ ����
	if (list.first(&temp)) {
		if (!temp.NameCompare("������"))
			temp.ChangePhoneNum("010-3333-4444");

		while (list.next(&temp)) {
			if (!temp.NameCompare("������"))
				temp.ChangePhoneNum("010-3333-4444");
		}
	}

	// 4. Ư�� �̸��� Ž���Ͽ� ���� ����
	if (list.first(&temp)) {
		if (!temp.NameCompare("������"))
			list.remove();

		while (list.next(&temp)) {
			if (!temp.NameCompare("������"))
				list.remove();
		}
	}

	// 5. �����ִ� ��� ����� ��ȭ��ȣ ���
	if (list.first(&temp)) {
		temp.ShowPhone();

		while (list.next(&temp))
			temp.ShowPhone();
	}

	return 0;
}