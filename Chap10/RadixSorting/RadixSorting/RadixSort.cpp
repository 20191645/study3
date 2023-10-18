// ��� ����(Radix Sort) ���� -- ���� ����Ʈ ����� ť�� ��Ŷ�� �����, ����� �������� ����
#include <iostream>
#include "ListQueue.h"
#include <cmath>

void RadixSort(int arr[], int num, int maxLen);

int main() {
	using std::cout;
	using std::endl;

	int arr[7] = { 13,212,14,7141,10987,6,15 };
	int i;

	// ���� �迭 ���
	for (i = 0; i < 7; i++)
		cout << arr[i] << ' ';
	cout << endl;

	// �������� ���� -- �켱������ ���� �������� ����
	RadixSort(arr, 7, 5);

	// ���ĵ� �迭 ���
	for (i = 0; i < 7; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

// LSD ������� ��� ���� ���� -- num: �迭 ���� ����, maxLen: ���� �� ���� �� ����
void RadixSort(int arr[], int num, int maxLen) {
	// 10������ ǥ���ϱ� ���� 10���� ��Ŷ�� ������
	ListQueue bucket[10];

	int j;		// arr �迭 �ε���
	int temp;	// (i+1)��° �ڸ� ����
	int i = 0;	// �� ��° �ڸ�����(10�� i��: (i+1)��° �ڸ�)
	while (i < maxLen) {
		// bucket�� arr �迭�� ����
		for (j = 0; j < num; j++) {
			temp = arr[j] / pow(10, i);
			bucket[temp % 10].Enqueue(arr[j]);
		}

		// bucket���� arr �迭�� ����
		j = 0;
		for (int k = 0; k < 10; k++) {
			while (!bucket[k].isEmpty())
				arr[j++] = bucket[k].Dequeue();
		}

		// �ڸ��� �ø���
		i++;
	}


}