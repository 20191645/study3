// 배열 기반의 원형 큐(CircularQueue) 구현
#include "ArrayQueue.h"
#include <iostream>
#include <cstdlib>

// 큐가 비어있는지 확인
bool ArrayQueue::isEmpty() const {
	return front == rear;
}

// 큐가 꽉찼는지 확인
bool ArrayQueue::isFull() const {
	return (front - rear == 1 || rear - front == arrLen - 1);
}

// rear에 데이터 저장
void ArrayQueue::Enqueue(Data data) {
	// 큐가 꽉차있는 경우
	if (isFull()) {
		std::cout << "큐가 꽉차있습니다!\n";
		exit(EXIT_FAILURE);
	}

	arr[rear] = data;
	// rear가 배열의 마지막 인덱스인 경우
	if (rear == arrLen - 1) {
		rear = 0;
	}
	else {
		rear++;
	}
}

// front에 해당하는 데이터 삭제 후 반환 -- 데이터가 하나 이상이어야 한다
Data ArrayQueue::Dequeue() {
	if (isEmpty()) {
		std::cout << "큐가 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	Data data = arr[front];
	// front가 배열의 마지막 인덱스인 경우
	if (front == arrLen - 1) {
		front = 0;
	}
	else {
		front++;
	}
}

// front에 해당하는 데이터 반환 -- 데이터가 하나 이상이어야 한다
Data ArrayQueue::Peek() const {
	if (isEmpty()) {
		std::cout << "큐가 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	// front가 배열의 마지막 인덱스인 경우
	if (front == arrLen - 1) {
		return arr[0];
	}
	else {
		return arr[front + 1];
	}
}