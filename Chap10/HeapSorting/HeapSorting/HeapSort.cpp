// 힙 정렬(Heap Sort) 구현 -- 힙을 이용한 정렬
// 힙을 이용하기 위해 "Heap.h, cpp"와 함께 컴파일
#include <iostream>
#include "Heap.h"

// 힙 우선순위 비교를 위한 함수 -- HData: int, 오름차순 정렬
int PriorityFunction(int d1, int d2) {
	// 첫 번째 매개변수의 우선순위가 높으면 0보다 큰 값
	// 두 번째 매개변수의 우선순위가 높으면 0보다 작은 값
	// 우선순위가 동일하면 0
	return d2 - d1;
}

int main() {
	using std::cout;
	using std::endl;

	Heap heap(PriorityFunction);

	int arr[5] = { 3,2,4,1,0 };	// 정렬 대상
	int i;	// 반복문용 변수

	// 원본 배열 출력
	for (i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;

	// 오름차순 정렬 -- Heap에 insert하면 알아서 정렬된 순서로 저장
	for (i = 0; i < 5; i++)
		heap.Insert(arr[i]);
	// 정렬된 순서대로 다시 배열에 대입
	for (i = 0; i < 5; i++)
		arr[i] = heap.Delete();

	// 정렬된 배열 출력
	for (i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << endl;
	
	return 0;
}