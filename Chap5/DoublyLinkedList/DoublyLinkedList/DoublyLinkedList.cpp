// 양방향 연결 리스트(DoublyLinkedList) 구현 -- tail 데이터 추가 방식
#include "DoublyLinkedList.h"
#include <iostream>

// 생성자 - 리스트 초기화
DoublyList::DoublyList() {
	count = 0;
	cur = NULL;

	// head, tail: 더미 노드(변화 X)
	head = new Node;
	tail = new Node;
	
	head->prev = NULL;
	head->next = tail;
	
	tail->prev = head;
	tail->next = NULL;
}

// 파괴자 - 리스트 삭제
DoublyList::~DoublyList() {
	if (count > 0) {
		Node* temp = head;
		while (temp != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
	}
}

// 리스트에 데이터 삽입
void DoublyList::LInsert(LData data) {
	// temp: tail에 추가되는 Node
	Node* temp = new Node;
	temp->data = data;
	temp->next = tail;
	temp->prev = tail->prev;

	(tail->prev)->next = temp;
	tail->prev = temp;

	count++;
}

// 첫 번째 데이터를 pdata에 저장
bool DoublyList::LFirst(LData* pdata) {
	// head, tail의 더미 노드가 서로를 가리키는 경우
	if (head->next == tail)
		return false;
	else {
		cur = head->next;
		*pdata = cur->data;
		return true;
	}
}

// 현재 데이터의 다음 데이터를 pdata에 저장
bool DoublyList::LNext(LData* pdata) {
	// 다음 노드가 tail을 가리키는 경우
	if (cur->next == tail)
		return false;
	else {
		cur = cur->next;
		*pdata = cur->data;
		return true;
	}
}

// 현재 가리키는 데이터 삭제
LData DoublyList::LRemove() {
	LData data = cur->data;

	// temp: 삭제하려는 Node
	Node* temp = cur;
	cur = cur->prev;
	cur->next = temp->next;
	(temp->next)->prev = cur;
	delete temp;

	count--;
	return data;
}

// 리스트에 저장된 데이터 수 반환
int DoublyList::LCount() const {
	return count;
}