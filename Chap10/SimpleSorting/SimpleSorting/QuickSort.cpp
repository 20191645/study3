// 퀵 정렬(Quick Sort) 구현 -- 분할 정복을 이용하여 pivot을 기준으로 하는 재귀적 함수로 구현
#include <iostream>

void QuickSort(int arr[], int left, int right);
int Partition(int arr[], int left, int right);
int MidIndex(int arr[], int left, int right);

int main() {
	using std::cout;
	using std::endl;

	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };	// 정렬 대상
	int i;						// 반복문용 변수

	// 원본 배열 출력
	for (i = 0; i < 15; i++)
		cout << arr[i] << ' ';
	cout << endl;

	// 오름차순 정렬 -- 우선순위는 값이 작을수록 높다
	QuickSort(arr, 0, 14);

	// 정렬된 배열 출력
	for (i = 0; i < 15; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

// 퀵 정렬 함수 -- left, right: 범위
void QuickSort(int arr[], int left, int right) {
	// 재귀 탈출 조건 -- 더 나눌 수 없는 범위
	if (left >= right)
		return;

	// pivot은 가장 왼쪽 인덱스로 간주
	int pivot = Partition(arr, left, right);
	QuickSort(arr, left, pivot - 1);
	QuickSort(arr, pivot + 1, right);
}

// pivot이 제 자리를 찾는 함수 -- pivot의 인덱스값 반환
// 정렬 결과 -- pivot 왼쪽: pivot보다 작은 값, 오른쪽: pivot보다 큰 값
int Partition(int arr[], int left, int right) {
	int temp;			// swap용 변수
	
	// mid: 가장 왼쪽, 가장 오른쪽, 중간 인덱스 중에서 중간 값을 갖는 인덱스
	// pivot: 가장 왼쪽 인덱스를 가지는 기준점
	// low: pivot을 제외하고 가장 왼쪽 인덱스
	// high: pivot을 제외하고 가장 오른쪽 인덱스
	int mid = MidIndex(arr, left, right);
	temp = arr[mid];
	arr[mid] = arr[left];
	arr[left] = temp;
	int pivot = left;
	int low = left + 1;
	int high = right;

	// 피벗 확인을 위한 메시지
	std::cout << "피벗: " << arr[pivot] << std::endl;

	// low와 high이 서로 교차할때까지
	while (low <= high) {
		// low, high가 배열 범위를 넘어서는 문제를 막기 위한 비교연산
		// -- (low <= right), (high > left)
		
		// low 오른쪽 이동 -- pivot보다 우선순위 낮은 데이터 만날때까지
		while (arr[pivot] >= arr[low] && low <= right)
			low++;
		// high 왼쪽 이동 -- pivot보다 우선순위 높은 데이터 만날때까지
		while (arr[pivot] <= arr[high] && high > left)
			high--;

		// low와 high 값 교환 -- 아직 교차되지 않았을 경우에만
		if (low <= high) {
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
		// pivot과 high 값 교환 -- 교차된 경우
		else {
			temp = arr[pivot];
			arr[pivot] = arr[high];
			arr[high] = temp;
		}
	}

	return high;
}

// 가장 왼쪽, 가장 오른쪽, 중간 인덱스 중에서 중간 값에 해당하는 인덱스 반환
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