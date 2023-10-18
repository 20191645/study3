// 연결 리스트(LinkedList) 기반의 큐 확인
#include "ListQueue.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	ListQueue queue;
	int data;

	// 큐 데이터 삽입
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);

	// 큐 데이터 삭제
	while (!queue.isEmpty()) {
		data = queue.Dequeue();
	}
	cout << endl;

	// 원형 큐 확인을 위해 enqueue, dequeue 반복
	queue.Enqueue(4);
	queue.Enqueue(2);
	queue.Dequeue();
	queue.Enqueue(3);
	queue.Dequeue();
	queue.Enqueue(1);
	queue.Enqueue(5);
	queue.Enqueue(7);

	// 큐 데이터 출력
	while (!queue.isEmpty()) {
		data = queue.Dequeue();
	}
	cout << endl;

	return 0;
}