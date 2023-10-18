// Chap5에서 이미 구현했던 원형 연결 리스트를 활용하여 스택 구현
// "CircularLinkedList.h, cpp" 포함
#ifndef CIRCULARSTACK_H_
#define CIRCULARSTACK_H_

#include "CircularLinkedList.h"

typedef int Data;
class CircularStack {
private:
	CircularList list;

public:
	CircularStack():list() {}
	~CircularStack() {}

	bool isEmpty();
	void Push(Data data);
	Data Pop();
	Data Peek();
};

#endif