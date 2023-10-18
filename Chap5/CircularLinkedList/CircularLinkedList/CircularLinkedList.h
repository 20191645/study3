// 원형 연결 리스트(CircularLinkedList) 구현 -- head/tail 데이터 추가 선택 방식
#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_

typedef int LData;
class CircularList {
private:
	struct Node{
		LData data;
		Node* next;
	};
	int count;	// 리스트에 저장된 데이터 수
	Node* tail;	// 리스트의 꼬리
	Node* cur;	// 현재 리스트의 위치

public:
	CircularList();
	~CircularList();

	void LInsertTail(LData data);
	void LInsertHead(LData data);
	bool LFirst(LData* pdata);
	bool LNext(LData* pdata);
	LData LRemove();
	int LCount() const;
};

#endif