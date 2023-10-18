// 단순 연결 리스트(Singly LinkedList 구현) - head 데이터 추가 방식
#include "LinkedList1.h"
#include <iostream>

// 생성자 - 리스트 초기화
LinkedList::LinkedList() {
	count = 0;
	order = NULL;

	// head: 더미 노드(변화 X)
	head = new Node;
	head->next = NULL;
}

// 파괴자 - 리스트 삭제
LinkedList::~LinkedList() {
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
void LinkedList::LInsert(LData data) {
	// 리스트 정렬 기준 없을때 = head쪽에 데이터 삽입
	if (order == NULL) {
		Node* temp = new Node;
		temp->data = data;
		temp->next = head->next;
		head->next = temp;
	}

	// 리스트 정렬 기준 있을때 = 정렬 기준에 맞춰 삽입
	else {
		// temp: 추가할 Node, loc: 삽입할 위치 Node
		Node* temp = new Node;
		temp->data = data;
		Node* loc = head;

		// 비교할 Node가 존재하고, 비교 Node의 데이터값보다 정렬 순서 뒤일때 반복
		while (loc->next != NULL && order(temp->data, loc->next->data)) {
			loc = loc->next;
		}
		temp->next = loc->next;
		loc->next = temp;
	}

	count++;
}

// 첫 번째 데이터를 pdata에 저장
bool LinkedList::LFirst(LData* pdata) {
	if (head->next == NULL)
		return false;
	else {
		cur = head->next;
		*pdata = cur->data;
		return true;
	}
}

// 현재 데이터의 다음 데이터를 pdata에 저장
bool LinkedList::LNext(LData* pdata) {
	if (cur->next == NULL)
		return false;
	else {
		cur = cur->next;
		*pdata = cur->data;
		return true;
	}
}

// 현재 가리키는 데이터 삭제
LData LinkedList::LRemove() {	
	LData data = cur->data;

	// temp: 삭제하려는 Node 바로 앞의 Node
	Node* temp = head;
	while (temp->next != cur)
		temp = temp->next;

	cur = temp;
	temp = temp->next;
	cur->next = temp->next;
	
	delete temp;
	count--;
	return data;
}

// 리스트에 저장된 데이터 수 반환
int LinkedList::LCount() const {
	return count;
}

// 리스트의 정렬 기준이 되는 함수 등록
void LinkedList::SetSortRule(int(*func)(LData d1, LData d2)) {
	order = func;
}