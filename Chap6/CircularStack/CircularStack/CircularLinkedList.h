// ���� ���� ����Ʈ(CircularLinkedList) ���� -- head/tail ������ �߰� ���� ���
#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_

typedef int LData;
class CircularList {
private:
	struct Node{
		LData data;
		Node* next;
	};
	int count;	// ����Ʈ�� ����� ������ ��
	Node* tail;	// ����Ʈ�� ����
	Node* cur;	// ���� ����Ʈ�� ��ġ

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