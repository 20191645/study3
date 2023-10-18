// �� ����(Quick Sort) ���� -- ���� ������ �̿��Ͽ� pivot�� �������� �ϴ� ����� �Լ��� ����
#include <iostream>

void QuickSort(int arr[], int left, int right);
int Partition(int arr[], int left, int right);
int MidIndex(int arr[], int left, int right);

int main() {
	using std::cout;
	using std::endl;

	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };	// ���� ���
	int i;						// �ݺ����� ����

	// ���� �迭 ���
	for (i = 0; i < 15; i++)
		cout << arr[i] << ' ';
	cout << endl;

	// �������� ���� -- �켱������ ���� �������� ����
	QuickSort(arr, 0, 14);

	// ���ĵ� �迭 ���
	for (i = 0; i < 15; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

// �� ���� �Լ� -- left, right: ����
void QuickSort(int arr[], int left, int right) {
	// ��� Ż�� ���� -- �� ���� �� ���� ����
	if (left >= right)
		return;

	// pivot�� ���� ���� �ε����� ����
	int pivot = Partition(arr, left, right);
	QuickSort(arr, left, pivot - 1);
	QuickSort(arr, pivot + 1, right);
}

// pivot�� �� �ڸ��� ã�� �Լ� -- pivot�� �ε����� ��ȯ
// ���� ��� -- pivot ����: pivot���� ���� ��, ������: pivot���� ū ��
int Partition(int arr[], int left, int right) {
	int temp;			// swap�� ����
	
	// mid: ���� ����, ���� ������, �߰� �ε��� �߿��� �߰� ���� ���� �ε���
	// pivot: ���� ���� �ε����� ������ ������
	// low: pivot�� �����ϰ� ���� ���� �ε���
	// high: pivot�� �����ϰ� ���� ������ �ε���
	int mid = MidIndex(arr, left, right);
	temp = arr[mid];
	arr[mid] = arr[left];
	arr[left] = temp;
	int pivot = left;
	int low = left + 1;
	int high = right;

	// �ǹ� Ȯ���� ���� �޽���
	std::cout << "�ǹ�: " << arr[pivot] << std::endl;

	// low�� high�� ���� �����Ҷ�����
	while (low <= high) {
		// low, high�� �迭 ������ �Ѿ�� ������ ���� ���� �񱳿���
		// -- (low <= right), (high > left)
		
		// low ������ �̵� -- pivot���� �켱���� ���� ������ ����������
		while (arr[pivot] >= arr[low] && low <= right)
			low++;
		// high ���� �̵� -- pivot���� �켱���� ���� ������ ����������
		while (arr[pivot] <= arr[high] && high > left)
			high--;

		// low�� high �� ��ȯ -- ���� �������� �ʾ��� ��쿡��
		if (low <= high) {
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
		// pivot�� high �� ��ȯ -- ������ ���
		else {
			temp = arr[pivot];
			arr[pivot] = arr[high];
			arr[high] = temp;
		}
	}

	return high;
}

// ���� ����, ���� ������, �߰� �ε��� �߿��� �߰� ���� �ش��ϴ� �ε��� ��ȯ
int MidIndex(int arr[], int left, int right) {
	int middle = (left + right) / 2;
	
	if (arr[left] >= arr[right])
		if (arr[right] >= arr[middle])
			return right;
		else if (arr[left] <= arr[middle])
			return left;
		else
			return middle;
	else if (arr[middle] < arr[left])
		return left;
	else if (arr[right] > arr[middle])
		return middle;
	else
		return right;
}