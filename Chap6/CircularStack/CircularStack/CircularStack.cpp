// Chap5에서 이미 구현했던 원형 연결 리스트를 활용하여 스택 구현
#include "CircularStack.h"
#include "CircularLinkedList.h"

// 스택이 비어있는지 확인
bool CircularStack::isEmpty() {
	return list.LCount() == 0;
}

// 스택에 데이터 저장 -- head 데이터 추가 방식
void CircularStack::Push(Data data) {
	list.LInsertHead(data);
}

// 마지막 요소(head) 삭제 후 반환 -- 데이터가 하나 이상일 때 호출
Data CircularStack::Pop() {
	// CircularLinkedList의 cur이 tail->next[즉, head]를 가리키도록 설정
	Data data;
	list.LFirst(&data);

	return list.LRemove();
}

// 마지막 요소(head) 반환 -- 데이터가 하나 이상일 때 호출
Data CircularStack::Peek() {
	Data data = list.LFirst(&data);
	return data;
}