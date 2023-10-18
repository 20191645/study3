// 원형 연결 리스트(CircularLinkedList) 구현 -- head/tail 데이터 추가 선택 방식
#include "CircularLinkedList.h"
#include <iostream>

// 생성자 - 리스트 초기화
CircularList::CircularList() {
	count = 0;
	// 개념적 head = tail->next
	cur = tail = NULL;
}

// 파괴자 - 리스트 삭제
CircularList::~CircularList() {
	if (count > 0) {
		Node* temp = tail->next;
		while (temp != tail) {
			tail->next = temp->next;
			delete temp;
			temp = tail->next;
		}
		delete tail;
	}
}

// head쪽에 데이터 삽입 -- head가 새로운 Node로 변경
void CircularList::LInsertHead(LData data) {
	Node* temp = new Node;
	temp->data = data;
	
	// 리스트 첫 원소
	if (tail == NULL) {
		temp->next = temp;
		tail = temp;
	}
	else {
		temp->next = tail->next;
		tail->next = temp;
	}

	count++;
}

// tail쪽에 데이터 삽입 -- tail이 새로운 Node로 변경
void CircularList::LInsertTail(LData data) {
	Node* temp = new Node;
	temp->data = data;

	// 리스트 첫 원소
	if (tail == NULL) {
		temp->next = temp;
		tail = temp;
	}
	else {
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}

	count++;
}

// 첫 번째 데이터를 pdata에 저장
bool CircularList::LFirst(LData* pdata) {
	if (tail == NULL)
		return false;
	else {
		cur = tail->next;
		*pdata = cur->data;
		return true;
	}
}

// 현재 데이터의 다음 데이터를 pdata에 저장 -- 원형이기 때문에 무한 반복 가능
bool CircularList::LNext(LData* pdata) {
	if (tail == NULL)
		return false;
	else {
		cur = cur->next;
		*pdata = cur->data;
		return true;
	}
}

// 현재 가리키는 데이터 삭제
LData CircularList::LRemove() {
	LData data = cur->data;
	// temp: 삭제하려는 Node 바로 앞의 Node
	Node* temp = tail;

	// 리스트에 Node가 1개인 경우
	if (tail == tail->next) {
		tail = NULL;
	}

	while (temp->next != cur)
		temp = temp->next;
	
	// 삭제하려는 Node가 tail인 경우
	if (cur == tail)
		tail = temp;

	cur = temp;
	temp = temp->next;
	cur->next = temp->next;

	delete temp;
	count--;
	return data;
}

// 리스트에 저장된 데이터 수 반환
int CircularList::LCount() const {
	return count;
}