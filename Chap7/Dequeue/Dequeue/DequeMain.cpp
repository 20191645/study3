// 양방향 연결 리스트를 기반으로 덱(Deque) 확인
#include "Deque.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	Deque deque;
	int data;

	// 덱 데이터 삽입
	deque.AddFirst(3);
	deque.AddFirst(2);
	deque.AddFirst(1);

	deque.AddLast(4);
	deque.AddLast(5);
	deque.AddLast(6);

	// 데이터 추출 -- head
	while (!deque.isEmpty()) {
		data = deque.RemoveFirst();
		cout << data << ' ';
	}
	cout << endl;

	// 덱 데이터 삽입
	deque.AddFirst(3);
	deque.AddFirst(2);
	deque.AddFirst(1);

	deque.AddLast(4);
	deque.AddLast(5);
	deque.AddLast(6);

	// 데이터 추출 -- tail
	while (!deque.isEmpty()) {
		data = deque.RemoveLast();
		cout << data << ' ';
	}
	cout << endl;

	return 0;
}