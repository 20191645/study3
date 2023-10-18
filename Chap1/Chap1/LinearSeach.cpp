// 순차 탐색 알고리즘
#include <iostream>

int linear_search(int arr[], int len, int target) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == target)
			return i;
	}
	return -1;
}

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 4,2,1,7,5 };
	int result = linear_search(arr, 5, 1);
	if (result == -1)
		cout << "탐색 실패!" << endl;
	else
		cout << result << "번째 인덱스에 있습니다!" << endl;

	result = linear_search(arr, 5, 0);
	if (result == -1)
		cout << "탐색 실패!" << endl;
	else
		cout << result << "번째 인덱스에 있습니다!" << endl;

	return 0;
}