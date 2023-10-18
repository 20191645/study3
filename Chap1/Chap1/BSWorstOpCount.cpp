// ���� Ž���� ���� Ž�� �˰����� ���� ��
#include <iostream>

int binary_search(int arr[], int len, int target);
int linear_search(int arr[], int len, int target);

int main() {
	using std::cout;
	using std::endl;

	int arr1[1000] = { 0, };
	int arr2[100000] = { 0, };

	// count: == �� ���� ���� Ƚ��
	int count = linear_search(arr1, 1000, 1);
	cout << "���� Ž���� �� ���� ���� Ƚ��: " << count << endl;
	count = binary_search(arr1, 1000, 1);
	cout << "���� Ž���� �� ���� ���� Ƚ��: " << count << endl;

	cout << endl;

	count = linear_search(arr2, 100000, 1);
	cout << "���� Ž���� �� ���� ���� Ƚ��: " << count << endl;
	count = binary_search(arr2, 100000, 1);
	cout << "���� Ž���� �� ���� ���� Ƚ��: " << count << endl;

	return 0;
}

int binary_search(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int middle = (first + last) / 2;
	int count = 0;

	while (first <= last) {
		if (arr[middle] == target)
			break;
		else {
			if (arr[middle] > target) {
				last = middle - 1;
				middle = (first + last) / 2;
			}
			else {
				first = middle + 1;
				middle = (first + last) / 2;
			}
		}

		count++;
	}

	return count;
}

int linear_search(int arr[], int len, int target) {
	int count = 0;	// == �񱳿��� ����Ƚ��

	for (int i = 0; i < len; i++) {
		if (arr[i] == target)
			break;
		count++;
	}
	return count;
}