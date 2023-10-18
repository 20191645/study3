// Employee형 원형 연결 리스트(CircularLinkedList) 구현
#ifndef EMPLOYEECIRCULARLIST_H_
#define EMPLOYEECIRCULARLIST_H_

#include <iostream>

struct Employee {
	int id;
	char name[30];

	void ShowEmp() const {
		std::cout << "사번: " << id << ", 이름: " << name << std::endl;
	};
};

// LData: Employee 구조체 변수의 주소
typedef Employee* LData;

class CircularList {
private:
	struct Node {
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