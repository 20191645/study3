// 힙(Heap) 기반 우선순위 큐(Priority Queue) 확인
#include "PriorityQueue.h"
#include <iostream>
#include <string>
using std::string;

// 우선순위 비교용 함수
int PriorityFunction(string c1, string c2) {
	// 첫 번째 매개변수의 우선순위가 높으면 0보다 큰 값
	// 두 번째 매개변수의 우선순위가 높으면 0보다 작은 값
	// 우선순위가 동일하면 0
	return c2.size() - c1.size();
}

int main() {
	using std::cout;
	using std::endl;
	
	PQueue pqueue(PriorityFunction);

	pqueue.Enqueue("abcd");
	pqueue.Enqueue("ba");
	pqueue.Enqueue("aca");
	pqueue.Enqueue("b");
	pqueue.Enqueue("ab");

	while (!pqueue.isEmpty())
		cout << pqueue.Dequeue() << endl;

	return 0;
}