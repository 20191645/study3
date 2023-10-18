/*
	Employee�� ���� ���� ����Ʈ(CircularLinkedList) Ȯ�� -- tail ������ �߰� ���
	- ����Ʈ�� ������: ���� ������ ���� �� �ִ� Employee ����ü�� �ּ� ��
	- ������ ������� ���ư��鼭 ������ ����(���� ���� = ����Ʈ ��� ����)
	- Emp(list, name, days): �Ű������� ���޵� �̸��� ������ ������ �� ��, 
			�Ű������� ���޵� ���ڸ�ŭ ���� ������ ������ ���� �Ǵ� ������ ���� ��ȯ
*/
#include "EmployeeCircularList.h"
#include <iostream>

Employee* Emp(CircularList& list, const char* name, int days) {
	Employee* temp;
	int i;

	// name�� �ش��ϴ� Employee ã��
	if (list.LFirst(&temp)) {
		if (strcmp(name, temp->name)) {
			for (i = 1; i < list.LCount(); i++) {
				list.LNext(&temp);
				if (!strcmp(name, temp->name))
					break;
			}
		}
	}

	// days �帥 �� Employee ã��
	for (i = 0; i < days; i++) {
		list.LNext(&temp);
	}

	return temp;
}

int main() {
	using std::cout;
	using std::endl;

	CircularList list;
	Employee* data;

	Employee emp1 = { 123, "ȫ�浿" };
	Employee emp2 = { 456, "��ö��" };
	Employee emp3 = { 789, "��¯��" };
	Employee emp4 = { 210, "�ڸͱ�" };

	// ����Ʈ ������ ���� -- ����Ʈ ����: ��� ����
	list.LInsertTail(&emp1);
	list.LInsertTail(&emp2);
	list.LInsertTail(&emp3);
	list.LInsertTail(&emp4);

	// ����Ʈ ���� ���
	cout << "���� ����Ʈ�� ������ ��: " << list.LCount() << endl;
	if (list.LFirst(&data)) {
		data->ShowEmp();
		for (int i = 1; i < list.LCount(); i++) {
			if (list.LNext(&data))
				data->ShowEmp();
		}
	}
	std::cout << std::endl;

	// ������ Ȯ��
	cout << "ó�� ������:\n";
	emp2.ShowEmp();
	data = Emp(list, "��ö��", 7);
	cout << "7�� �� ������:\n";
	data->ShowEmp();
	cout << endl;

	// ����Ʈ ���� ����
	cout << "��¯�� ����!\n";
	if (list.LFirst(&data)) {
		if (!strcmp(data->name, "��¯��"))
			list.LRemove();
		for (int i = 1; i < list.LCount(); i++) {
			if (list.LNext(&data))
				if (!strcmp(data->name, "��¯��"))
					list.LRemove();
		}
	}

	// ����Ʈ ���� ���
	cout << "���� ����Ʈ�� ������ ��: " << list.LCount() << endl;
	if (list.LFirst(&data)) {
		data->ShowEmp();
		for (int i = 1; i < list.LCount(); i++) {
			if (list.LNext(&data))
				data->ShowEmp();
		}
	}
	std::cout << std::endl;

	return 0;
}