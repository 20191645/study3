// �ܼ� ���� ����Ʈ(Singly LinkedList ����) - tail ������ �߰� ���
// LData => Point* ��
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

	int count;	// ����Ʈ�� ����� ������ ��
	Node* head;	// ����Ʈ �Ӹ�
	Node* cur;	// ���� ����Ʈ ��ġ
	Node* tail;	// ����Ʈ ����
	int(*order)(LData d1, LData d2);	// ���� ���� �Լ��� ������

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
