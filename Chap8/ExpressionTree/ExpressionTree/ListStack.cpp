// 연결 리스트(LinkedList) 기반 스택 구현
#include "ListStack.h"
#include <iostream>
#include <cstdlib>


// 생성자 -- 스택 초기화
ListStack::ListStack() {
	head = NULL;
}

// 파괴자
ListStack::~ListStack() {
	Node* temp = head;
	while (temp != NULL) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// 스택이 비어있는지 확인
bool ListStack::isEmpty() const {
	return head == NULL;
}

// 스택에 데이터 저장 -- head 데이터 추가 방식
void ListStack::Push(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

// 마지막 요소(head) 삭제 후 반환 -- 데이터가 하나 이상일 때 호출
Data ListStack::Pop() {
	if (isEmpty()) {
		std::cout << "스택이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	// temp: 삭제할 Node
	Node* temp = head;
	Data data = temp->data;
	head = temp->next;
	delete temp;

	return data;
}

// 마지막 요소(head) 반환 -- 데이터가 하나 이상일 때 호출
Data ListStack::Peek() const {
	if (isEmpty()) {
		std::cout << "스택이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	return head->data;
}