/*
	배열 기반의 원형 큐(CircularQueue) 구현 확인
	- 배열의 길이가 n이면 데이터가 n-1개 채워졌을 때 꽉찬 것으로 간주
	- (즉, front와 rear의 인덱스 차이가 한칸일 때)
	- front와 rear가 같은 값이면 빈 것으로 간주
	- 이를 위해 front가 가리키는 배열은 항상 비워둔다
	- 삽입과 삭제를 확인하기 위해 Enqueue(), Dequeue()에 메시지 추가
*/
#include "ArrayQueue.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	ArrayQueue queue;
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