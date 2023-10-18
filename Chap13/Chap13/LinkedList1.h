// 단순 연결 리스트(Singly LinkedList 구현) - head 데이터 추가 방식
// 해쉬 테이블 구현을 위해 LData를 Slot으로 수정
#ifndef LINKEDLIST1_H_
#define LINKEDLIST1_H_

#include "Slot.h"

typedef Slot LData;
class LinkedList {
private:
	struct Node {
		LData data;
		Node* next;
	};

	int count;	// 리스트에 저장된 데이터 수
	Node* head;	// 리스트 머리
	Node* cur;	// 현재 리스트 위치
	int(*order)(LData d1, LData d2);	// 정렬 기준 함수의 포인터

public:
	LinkedList();
	~LinkedList();

	void LInsert(LData data);
	bool LFirst(LData* pdata);
	bool LNext(LData* pdata);
	LData LRemove();
	int LCount() const;
	void SetSortRule(int(*func)(LData d1, LData d2));
};


#endif
