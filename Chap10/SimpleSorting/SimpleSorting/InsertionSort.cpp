// ���� ����(Insertion Sort) ���� -- ���� �� �� �κ��� �����͸� ���ĵ� �κ��� Ư�� ��ġ�� �����ϸ鼭 ����
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 3,2,4,1,0 };	// ���� ���
	int temp;	// ���� �� �� �κ��� ������

	// ���� �迭 ���
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;


	int j;	// ���� �� �� �κ��� �����Ͱ� �� �ε���
	// �������� ���� -- �迭�� �� ���̰� n�̸�, ���� �ܰ�� (n-1)
	for (int i = 1; i < 5; i++) {
		// arr[i] = ���� �� �� �κ��� ������
		temp = arr[i];

		// �ѹ��� ������ �Ϸ��ϸ� �켱 ������ ���� ���� ���Ҵ� ���ڸ��� ���ĵȴ�
		// -- ���� �ݺ����� ���ĵ� �κа��� ���Ͽ� ���� ��ġ ã��
		for (j = i - 1; j >= 0; j--) {
			if (temp < arr[j])
				arr[j + 1] = arr[j];
			// ���� ��ġ ã��
			else
				break;
		}
		arr[++j] = temp;
	}

	// ���ĵ� �迭 ���
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}