// Chap5���� �̹� �����ߴ� ���� ���� ����Ʈ�� Ȱ���Ͽ� ���� ����
// "CircularLinkedList.h, cpp" ����
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