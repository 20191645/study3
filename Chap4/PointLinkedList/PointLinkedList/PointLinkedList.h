// 단순 연결 리스트(Singly LinkedList 구현) - tail 데이터 추가 방식
// LData => Point* 형
#ifndef POINTLINKEDLIST_H_
#define POINTLINKEDLIST_H_

#include "Point.h"

typedef Point* LData;
class LinkedList {
private:
	struct Node {
		LData data;
		Node* next;
	};

	int count;	// 리스트에 저장된 데이터 수
	Node* head;	// 리스트 머리
	Node* cur;	// 현재 리스트 위치
	Node* tail;	// 리스트 꼬리
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
