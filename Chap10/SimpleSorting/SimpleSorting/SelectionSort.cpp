// ���� ����(Selection Sort) ���� -- ���ļ����� �°� �ϳ��� �����ؼ� �ű�� ����
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 3,2,4,1,0 };	// ���� ���
	int temp;	// swap�� ����
	int min;	// �켱������ ���� ���� ������ �ε���

	// ���� �迭 ���
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;


	// �������� ���� -- �迭�� �� ���̰� n�̸�, ���� �ܰ�� (n-1)
	for (int i = 0; i < 4; i++) {
		// �ѹ��� ������ �Ϸ��ϸ� �켱 ������ ���� ���� ���Ҵ� ���ڸ��� ���ĵȴ�
		// ���� �ݺ���: ���� ���ҵ� �� �켱 ������ ���� ���� ���Ҹ� ã�Ƴ���
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}

	// ���ĵ� �迭 ���
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}