// ���� Ž��(Interpol Search) -- ���� Ž���� ��ȿ������ ����
#include <iostream>

int InterpolSearch(int arr[], int first, int last, int target);

int main() {
	using std::cout;
	using std::endl;

	int arr[] = { 1,3,5,7,9 };
	int index;	// Ž���Ϸ��� Ű�� �ε���

	index = InterpolSearch(arr, 0, 4, 7);
	if (index < 0)
		cout << "ã������ �����Ͱ� �����ϴ�\n";
	else
		cout << "ã���ô� �������� �ε����� " << index << "�Դϴ�\n";

	index = InterpolSearch(arr, 0, 4, 10);
	if (index < 0)
		cout << "ã������ �����Ͱ� �����ϴ�\n";
	else
		cout << "ã���ô� �������� �ε����� " << index << "�Դϴ�\n";

	index = InterpolSearch(arr, 0, 4, 2);
	if (index < 0)
		cout << "ã������ �����Ͱ� �����ϴ�\n";
	else
		cout << "ã���ô� �������� �ε����� " << index << "�Դϴ�\n";

	return 0;
}


int InterpolSearch(int arr[], int first, int last, int target) {
	// target�� �迭 ���� �ۿ� �ִ� ��
	if (arr[first] > target || arr[last] < target)
		return -1;
	
	// Ž�� ��ġ �ε����� �����ϴ� ��
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