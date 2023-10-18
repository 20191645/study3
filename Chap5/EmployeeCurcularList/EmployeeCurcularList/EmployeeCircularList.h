// Employee�� ���� ���� ����Ʈ(CircularLinkedList) ����
#ifndef EMPLOYEECIRCULARLIST_H_
#define EMPLOYEECIRCULARLIST_H_

#include <iostream>

struct Employee {
	int id;
	char name[30];

	void ShowEmp() const {
		std::cout << "���: " << id << ", �̸�: " << name << std::endl;
	};
};

// LData: Employee ����ü ������ �ּ�
typedef Employee* LData;

class CircularList {
private:
	struct Node {
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