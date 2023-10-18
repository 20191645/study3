// 이진 탐색 알고리즘
#include <iostream>

int binary_search(int arr[], int len, int target);

int main() {
	using std::cout;
	using std::endl;

	int arr[6] = { 1,2,4,5,7,9 };
	int result = binary_search(arr, 6, 2);
	if (result == -1)
		cout << "탐색 실패!" << endl;
	else
		cout << result << "번째 인덱스 있습니다!" << endl;

	result = binary_search(arr, 6, 5);
	if (result == -1)
		cout << "탐색 실패!" << endl;
	else
		cout << result << "번째 인덱스 있습니다!" << endl;

	result = binary_search(arr, 6, -1);
	if (result == -1)
		cout << "탐색 실패!" << endl;
	else
		cout << result << "번째 인덱스 있습니다!" << endl;

	return 0;
}

int binary_search(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int middle = (first + last) / 2;

	while (first <= last) {
		if (arr[middle] == target)
			return middle;
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
	}

	return -1;
}