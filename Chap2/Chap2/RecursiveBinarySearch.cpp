// 재귀를 이용하여 이진 탐색 알고리즘 구현
#include <iostream>

int binary_search(int arr[], int first, int last, int target);

int main() {
	using std::cout;
	using std::endl;

	int arr[6] = { 2,6,10,15,40,41 };
	int result = binary_search(arr, 0, 5, 6);
	if (result == -1)
		cout << "탐색 실패!" << endl;
	else
		cout << result << "번째 인덱스에 위치!" << endl;

	result = binary_search(arr, 0, 5, 1);
	if (result == -1)
		cout << "탐색 실패!" << endl;
	else
		cout << result << "번째 인덱스에 위치!" << endl;

	result = binary_search(arr, 0, 5, 50);
	if (result == -1)
		cout << "탐색 실패!" << endl;
	else
		cout << result << "번째 인덱스에 위치!" << endl;

	return 0;
}

int binary_search(int arr[], int first, int last, int target) {
	int middle = (first + last) / 2;

	if (first > last)
		return -1;

	if (arr[middle] == target)
		return middle;
	else if (arr[middle] > target)
		binary_search(arr, first, middle - 1, target);
	else
		binary_search(arr, middle + 1, last, target);
}