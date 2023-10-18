// 보간 탐색(Interpol Search) -- 이진 탐색의 비효율성을 개선
#include <iostream>

int InterpolSearch(int arr[], int first, int last, int target);

int main() {
	using std::cout;
	using std::endl;

	int arr[] = { 1,3,5,7,9 };
	int index;	// 탐색하려는 키의 인덱스

	index = InterpolSearch(arr, 0, 4, 7);
	if (index < 0)
		cout << "찾으려는 데이터가 없습니다\n";
	else
		cout << "찾으시는 데이터의 인덱스는 " << index << "입니다\n";

	index = InterpolSearch(arr, 0, 4, 10);
	if (index < 0)
		cout << "찾으려는 데이터가 없습니다\n";
	else
		cout << "찾으시는 데이터의 인덱스는 " << index << "입니다\n";

	index = InterpolSearch(arr, 0, 4, 2);
	if (index < 0)
		cout << "찾으려는 데이터가 없습니다\n";
	else
		cout << "찾으시는 데이터의 인덱스는 " << index << "입니다\n";

	return 0;
}


int InterpolSearch(int arr[], int first, int last, int target) {
	// target이 배열 범위 밖에 있는 값
	if (arr[first] > target || arr[last] < target)
		return -1;
	
	// 탐색 위치 인덱스를 결정하는 식
	int search =
		((double)(target - arr[first]) / (arr[last] - arr[first]) *
			(last - first)) + first;

	if (arr[search] == target)
		return search;
	else if (arr[search] > target)
		return InterpolSearch(arr, first, search - 1, target);
	else
		return InterpolSearch(arr, search + 1, last, target);
}