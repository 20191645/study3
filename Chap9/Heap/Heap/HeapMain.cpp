// 배열 기반 힙(Heap) 확인
#include "Heap.h"
#include <iostream>

// 우선순위 비교용 함수
int PriorityFunction(char c1, char c2) {
	// 첫 번째 매개변수의 우선순위가 높으면 0보다 큰 값
	// 두 번째 매개변수의 우선순위가 높으면 0보다 작은 값
	// 우선순위가 동일하면 0
	return c2 - c1;
}

int main() {
	using std::cout;
	using std::endl;

	Heap heap(PriorityFunction);

	heap.Insert('A');
	heap.Insert('B');
	heap.Insert('C');
	cout << heap.Delete() << endl;
	
	heap.Insert('A');
	heap.Insert('B');
	heap.Insert('C');
	cout << heap.Delete() << endl;

	while (!heap.isEmpty())
		cout << heap.Delete() << endl;

	return 0;
}