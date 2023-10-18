// 양방향 연결 리스트(DoublyLinkedList) 구현 -- tail 데이터 추가 방식
#ifndef DOUBLYLINKEDLIST1_H_
#define DOUBLYLINKEDLIST1_H_

typedef int LData;
class DoublyList {
private:
	struct Node {
		LData data;
		Node* prev;	// 이전 노드
		Node* next;	// 다음 노드
	};

	int count;	// 리스트에 저장된 데이터 수
	Node* head;	// 머리 노드
	Node* tail;	// 꼬리 노드
	Node* cur;	// 현재 노드 위치

public:
	DoublyList();
	~DoublyList();

	void LInsert(LData data);
	bool LFirst(LData* pdata);
	bool LNext(LData* pdata);
	LData LRemove();
	int LCount() const;
};


#endif
