// 삽입 정렬(Insertion Sort) 구현 -- 정렬 안 된 부분의 데이터를 정렬된 부분의 특정 위치에 삽입하면서 정렬
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	int arr[5] = { 3,2,4,1,0 };	// 정렬 대상
	int temp;	// 정렬 안 된 부분의 데이터

	// 원본 배열 출력
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;


	int j;	// 정렬 안 된 부분의 데이터가 들어갈 인덱스
	// 오름차순 정렬 -- 배열의 총 길이가 n이면, 정렬 단계는 (n-1)
	for (int i = 1; i < 5; i++) {
		// arr[i] = 정렬 안 된 부분의 데이터
		temp = arr[i];

		// 한바퀴 정렬을 완료하면 우선 순위가 가장 높은 원소는 앞자리에 정렬된다
		// -- 내부 반복문은 정렬된 부분과의 비교하여 삽입 위치 찾기
		for (j = i - 1; j >= 0; j--) {
			if (temp < arr[j])
				arr[j + 1] = arr[j];
			// 삽입 위치 찾음
			else
				break;
		}
		arr[++j] = temp;
	}

	// 정렬된 배열 출력
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}