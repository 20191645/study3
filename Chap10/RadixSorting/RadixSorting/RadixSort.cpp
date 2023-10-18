// 기수 정렬(Radix Sort) 구현 -- 연결 리스트 기반의 큐로 버킷을 만들고, 기수를 기준으로 정렬
#include <iostream>
#include "ListQueue.h"
#include <cmath>

void RadixSort(int arr[], int num, int maxLen);

int main() {
	using std::cout;
	using std::endl;

	int arr[7] = { 13,212,14,7141,10987,6,15 };
	int i;

	// 원본 배열 출력
	for (i = 0; i < 7; i++)
		cout << arr[i] << ' ';
	cout << endl;

	// 오름차순 정렬 -- 우선순위는 값이 작을수록 높다
	RadixSort(arr, 7, 5);

	// 정렬된 배열 출력
	for (i = 0; i < 7; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

// LSD 방식으로 기수 정렬 구현 -- num: 배열 원소 개수, maxLen: 원소 중 제일 긴 길이
void RadixSort(int arr[], int num, int maxLen) {
	// 10진수를 표현하기 위해 10개의 버킷을 가진다
	ListQueue bucket[10];

	int j;		// arr 배열 인덱스
	int temp;	// (i+1)번째 자리 숫자
	int i = 0;	// 몇 번째 자리인지(10의 i승: (i+1)번째 자리)
	while (i < maxLen) {
		// bucket에 arr 배열을 대입
		for (j = 0; j < num; j++) {
			temp = arr[j] / pow(10, i);
			bucket[temp % 10].Enqueue(arr[j]);
		}

		// bucket에서 arr 배열에 대입
		j = 0;
		for (int k = 0; k < 10; k++) {
			while (!bucket[k].isEmpty())
				arr[j++] = bucket[k].Dequeue();
		}

		// 자리수 올리기
		i++;
	}


}