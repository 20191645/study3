// 버블 정렬(Bubble Sort) 구현 -- 인접한 두 데이터를 비교하면서 정렬 진행
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 3,2,4,1,0 };	// 정렬 대상
	int temp;	// swap용 변수

	// 원본 배열 출력
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;


	// 오름차순 정렬 -- 배열의 총 길이가 n이면, 정렬 단계는 (n-1)
	for (int i = 0; i < 4; i++) {
		// 한바퀴 정렬을 완료하면 우선 순위가 가장 낮은 원소는 끝자리에 정렬된다
		// 내부 반복문: 우선 순위가 가장 낮은 원소를 끝자리로 보낸다
		for (int j = 0; j < 4 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// 정렬된 배열 출력
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}