// 병합 정렬(Merge Sort) 구현 -- 분할 정복을 이용하여 재귀적 함수로 구현
#include <iostream>

void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int middle, int right);

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 3,2,4,1,0 };	// 정렬 대상
	int i;	// 반복문용 변수

	// 원본 배열 출력
	for (i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	// 오름차순 정렬 -- 우선순위는 값이 작을수록 높다
	MergeSort(arr, 0, 4);

	// 정렬된 배열 출력
	for (i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

// 병합 정렬 함수 겸 분할 함수 -- arr: 정렬 대상, left-right: 범위
void MergeSort(int arr[], int left, int right) {
	// 1. 데이터가 하나씩 될 때까지 분할 -- 분할 함수
	// 2. 나뉘었던 둘을 정렬순서를 고려하여 계속 묶는다 -- 병합 함수

	// 재귀 탈출 조건 -- 더 나눌 수 없는 범위
	if (left >= right)
		return;

	int middle = (left + right) / 2;
	MergeSort(arr, left, middle);
	MergeSort(arr, middle + 1, right);
	Merge(arr, left, middle, right);
}

// 병합 함수 -- left-middle: 왼쪽 배열, (middle+1)-right: 오른쪽 배열
// 왼쪽, 오른쪽 배열은 이미 정렬되어 있다
void Merge(int arr[], int left, int middle, int right) {
	int* marr = new int[right + 1];	// 정렬 결과를 담을 배열
	int i = left;		// 왼쪽 배열 인덱스
	int j = middle + 1;	// 오른쪽 배열 인덱스
	int k;				// 결과 배열 인덱스

	for (k = left; k <= right; k++) {
		// 오른쪽 배열 인덱스가 범위내이면서, 
		// 왼쪽 배열 인덱스가 범위 밖이거나 오른쪽 배열값이 왼쪽 배열값보다 우선순위가 높을때
		if (j <= right && (i > middle || arr[j] < arr[i]))
			marr[k] = arr[j++];
		else
			marr[k] = arr[i++];
	}

	for (k = left; k <= right; k++)
		arr[k] = marr[k];
	delete[] marr;
}