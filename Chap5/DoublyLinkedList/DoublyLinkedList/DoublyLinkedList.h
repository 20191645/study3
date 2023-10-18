// ����� ���� ����Ʈ(DoublyLinkedList) ���� -- tail ������ �߰� ���
#ifndef DOUBLYLINKEDLIST1_H_
#define DOUBLYLINKEDLIST1_H_

typedef int LData;
class DoublyList {
private:
	struct Node {
		LData data;
		Node* prev;	// ���� ���
		Node* next;	// ���� ���
	};

	int count;	// ����Ʈ�� ����� ������ ��
	Node* head;	// �Ӹ� ���
	Node* tail;	// ���� ���
	Node* cur;	// ���� ��� ��ġ

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
