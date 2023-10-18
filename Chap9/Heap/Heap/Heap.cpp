// �迭 ��� ��(Heap) ���� -- �켱������ �������� �� �κп� ��ġ
// ��: ���� ���� Ʈ��
#include "Heap.h"
#include <iostream>
#include <cstdlib>

// �� ���� ����
void Heap::Insert(HData data) {
	// ���� ���� ���
	if (num >= arrLen - 1) {
		std::cout << "���� �� á���ϴ�!\n";
		exit(EXIT_FAILURE);
	}
	
	int index = ++num;	// ���ο� ���Ұ� �̵��� �ε���

	// �θ� ���� ��� �ٲٸ鼭 �ڸ� ã�� -- �θ� ��尡 ������ ������
	while (index > 1) {
		// �����Ϸ��� ������ �켱������ �θ��� �켱�������� ���� ���
		if (comp(data, arr[index / 2]) >= 0) {
			arr[index] = arr[index / 2];
			index /= 2;
		}
		else
			break;
	}

	arr[index] = data;
}


// Delete ���� �� Child �ε��� ��� �Լ�
int Heap::GetChildIndex(int index) const {
	// ���ϰ� 0: child ����X -- �ܸ� ���
	if (index * 2 > num)
		return 0;
	// child�� ���� ��� �ϳ� ����
	else if (index * 2 == num)
		return index * 2;
	else {
		// ���� ����� �켱 ������ ���� ���
		if (comp(arr[index * 2], arr[index * 2 + 1]) >= 0)
			return index * 2;
		else
			return index * 2 + 1;
	}
}

// ������ ���� �켱������ ���� ���� ����
HData Heap::Delete() {
	// ���� ����ִ� ���
	if (num < 1) {
		std::cout << "���� ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	HData data = arr[1];	// �����Ϸ��� ���� -- ��Ʈ ���
	int index = 1;	// ������ ���Ұ� �̵��� �ε���
	int child;	// �ڽ� ��� �ε���

	// �ڽ� ���� ��� �ٲٸ鼭 �ڸ� ã�� -- �ڽ� ��尡 ������ ������
	while (child = GetChildIndex(index)) {
		// ������ ������ �켱������ �ڽ��� �켱�������� ���� ���
		if (comp(arr[num], arr[child]) < 0) {
			arr[index] = arr[child];
			index = child;
		}
		else
			break;
	}

	arr[index] = arr[num--];
	return data;
}