// 선택 정렬(Selection Sort) 구현 -- 정렬순서에 맞게 하나씩 선택해서 옮기는 정렬
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 3,2,4,1,0 };	// 정렬 대상
	int temp;	// swap용 변수
	int min;	// 우선순위가 가장 높은 원소의 인덱스

	// 원본 배열 출력
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;


	// 오름차순 정렬 -- 배열의 총 길이가 n이면, 정렬 단계는 (n-1)
	for (int i = 0; i < 4; i++) {
		// 한바퀴 정렬을 완료하면 우선 순위가 가장 높은 원소는 앞자리에 정렬된다
		// 내부 반복문: 남은 원소들 중 우선 순위가 가장 높은 원소를 찾아낸다
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}

	// 정렬된 배열 출력
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}