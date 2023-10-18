// 연결 리스트(LinkedList) 기반의 큐 구현
#include "ListQueue.h"
#include <iostream>
#include <cstdlib>

// 생성자 - 큐 초기화
ListQueue::ListQueue() {
	front = rear = NULL;
}

// 파괴자 - 큐 삭제
ListQueue::~ListQueue() {
	Node* temp = front;
	while (temp != NULL) {
		front = front->next;
		delete temp;
		temp = front;
	}
}

// 큐가 비어있는지 확인
bool ListQueue::isEmpty() const {
	return front == NULL;
}

// rear에 데이터 저장
void ListQueue::Enqueue(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;

	// 큐의 첫 원소일 경우
	if (isEmpty())
		front = rear = temp;
	else {
		rear->next = temp;
		rear = temp;
	}
}

// front에 해당하는 데이터 삭제 후 반환 -- 데이터가 하나 이상이어야 한다
Data ListQueue::Dequeue() {
	if (isEmpty()) {
		std::cout << "큐가 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	Node* temp = front;
	Data data = temp->data;

	// 큐의 원소가 하나인 경우
	if (front == rear)
		rear = NULL;
	front = front->next;

	delete temp;
	return data;
}

// front에 해당하는 데이터 반환 -- 데이터가 하나 이상이어야 한다
Data ListQueue::Peek() const {
	if (isEmpty()) {
		std::cout << "큐가 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	return front->data;
}