// �� ����(Heap Sort) ���� -- ���� �̿��� ����
// ���� �̿��ϱ� ���� "Heap.h, cpp"�� �Բ� ������
#include <iostream>
#include "Heap.h"

// �� �켱���� �񱳸� ���� �Լ� -- HData: int, �������� ����
int PriorityFunction(int d1, int d2) {
	// ù ��° �Ű������� �켱������ ������ 0���� ū ��
	// �� ��° �Ű������� �켱������ ������ 0���� ���� ��
	// �켱������ �����ϸ� 0
	return d2 - d1;
}

int main() {
	using std::cout;
	using std::endl;

	Heap heap(PriorityFunction);

	int arr[5] = { 3,2,4,1,0 };	// ���� ���
	int i;	// �ݺ����� ����

	// ���� �迭 ���
	for (i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	// �������� ���� -- Heap�� insert�ϸ� �˾Ƽ� ���ĵ� ������ ����
	for (i = 0; i < 5; i++)
		heap.Insert(arr[i]);
	// ���ĵ� ������� �ٽ� �迭�� ����
	for (i = 0; i < 5; i++)
		arr[i] = heap.Delete();

	// ���ĵ� �迭 ���
	for (i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;
	
	return 0;
}