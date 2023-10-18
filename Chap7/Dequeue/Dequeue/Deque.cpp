// 양방향 연결 리스트를 기반으로 덱(Deque) 구현
#include "Deque.h"
#include <iostream>
#include <cstdlib>

// 생성자 -- 덱 초기화
Deque::Deque() {
	head = tail = NULL;
}

// 파괴자 - 덱 삭제
Deque::~Deque() {
	Node* temp = head;
	while (temp != NULL) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// 덱이 비어있는지 확인
bool Deque::isEmpty() const {
	return (head == NULL);
}

// head에 데이터 삽입
void Deque::AddFirst(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->prev = NULL;
	temp->next = head;

	// 덱이 비어있는 경우
	if (isEmpty()) {
		head = tail = temp;
	}
	else {
		head->prev = temp;
		head = temp;
	}
}

// tail에 데이터 삽입
void Deque::AddLast(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	temp->prev = tail;

	// 덱이 비어있는 경우
	if (isEmpty()) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

// head 데이터 삭제 후 반환 -- 데이터 하나 이상이어야 함
Data Deque::RemoveFirst() {
	if (isEmpty()) {
		std::cout << "덱이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	Node* temp = head;
	Data data = temp->data;
	head = head->next;
	delete temp;

	// 덱 원소가 하나였던 경우
	if (head == NULL)
		tail = NULL;
	else {
		head->prev = NULL;
	}

	return data;
}

// tail 데이터 삭제 후 반환 -- 데이터 하나 이상이어야 함
Data Deque::RemoveLast() {
	if (isEmpty()) {
		std::cout << "덱이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	Node* temp = tail;
	Data data = temp->data;
	tail = tail->prev;
	delete temp;

	// 덱 원소가 하나였던 경우
	if (tail == NULL)
		head = NULL;
	else {
		tail->next = NULL;
	}

	return data;
}

// head 데이터 반환 -- 데이터 하나 이상이어야 함
Data Deque::GetFirst() const {
	if (isEmpty()) {
		std::cout << "덱이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	return head->data;
}

// tail 데이터 반환 -- 데이터 하나 이상이어야 함
Data Deque::GetLast() const {
	if (isEmpty()) {
		std::cout << "덱이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	return tail->data;
}