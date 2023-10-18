// ���� ����(Bubble Sort) ���� -- ������ �� �����͸� ���ϸ鼭 ���� ����
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 3,2,4,1,0 };	// ���� ���
	int temp;	// swap�� ����

	// ���� �迭 ���
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;


	// �������� ���� -- �迭�� �� ���̰� n�̸�, ���� �ܰ�� (n-1)
	for (int i = 0; i < 4; i++) {
		// �ѹ��� ������ �Ϸ��ϸ� �켱 ������ ���� ���� ���Ҵ� ���ڸ��� ���ĵȴ�
		// ���� �ݺ���: �켱 ������ ���� ���� ���Ҹ� ���ڸ��� ������
		for (int j = 0; j < 4 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// ���ĵ� �迭 ���
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}