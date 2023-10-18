// ���� ����(Merge Sort) ���� -- ���� ������ �̿��Ͽ� ����� �Լ��� ����
#include <iostream>

void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int middle, int right);

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 3,2,4,1,0 };	// ���� ���
	int i;	// �ݺ����� ����

	// ���� �迭 ���
	for (i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	// �������� ���� -- �켱������ ���� �������� ����
	MergeSort(arr, 0, 4);

	// ���ĵ� �迭 ���
	for (i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

// ���� ���� �Լ� �� ���� �Լ� -- arr: ���� ���, left-right: ����
void MergeSort(int arr[], int left, int right) {
	// 1. �����Ͱ� �ϳ��� �� ������ ���� -- ���� �Լ�
	// 2. �������� ���� ���ļ����� ����Ͽ� ��� ���´� -- ���� �Լ�

	// ��� Ż�� ���� -- �� ���� �� ���� ����
	if (left >= right)
		return;

	int middle = (left + right) / 2;
	MergeSort(arr, left, middle);
	MergeSort(arr, middle + 1, right);
	Merge(arr, left, middle, right);
}

// ���� �Լ� -- left-middle: ���� �迭, (middle+1)-right: ������ �迭
// ����, ������ �迭�� �̹� ���ĵǾ� �ִ�
void Merge(int arr[], int left, int middle, int right) {
	int* marr = new int[right + 1];	// ���� ����� ���� �迭
	int i = left;		// ���� �迭 �ε���
	int j = middle + 1;	// ������ �迭 �ε���
	int k;				// ��� �迭 �ε���

	for (k = left; k <= right; k++) {
		// ������ �迭 �ε����� �������̸鼭, 
		// ���� �迭 �ε����� ���� ���̰ų� ������ �迭���� ���� �迭������ �켱������ ������
		if (j <= right && (i > middle || arr[j] < arr[i]))
			marr[k] = arr[j++];
		else
			marr[k] = arr[i++];
	}

	for (k = left; k <= right; k++)
		arr[k] = marr[k];
	delete[] marr;
}