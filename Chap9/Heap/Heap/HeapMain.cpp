// �迭 ��� ��(Heap) Ȯ��
#include "Heap.h"
#include <iostream>

// �켱���� �񱳿� �Լ�
int PriorityFunction(char c1, char c2) {
	// ù ��° �Ű������� �켱������ ������ 0���� ū ��
	// �� ��° �Ű������� �켱������ ������ 0���� ���� ��
	// �켱������ �����ϸ� 0
	return c2 - c1;
}

int main() {
	using std::cout;
	using std::endl;

	Heap heap(PriorityFunction);

	heap.Insert('A');
	heap.Insert('B');
	heap.Insert('C');
	cout << heap.Delete() << endl;
	
	heap.Insert('A');
	heap.Insert('B');
	heap.Insert('C');
	cout << heap.Delete() << endl;

	while (!heap.isEmpty())
		cout << heap.Delete() << endl;

	return 0;
}