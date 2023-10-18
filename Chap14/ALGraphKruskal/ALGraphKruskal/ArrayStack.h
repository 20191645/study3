// �迭 ��� ���� ����
#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

const int ArrLen = 10;
typedef int Data;

class ArrayStack {
private:
	Data arr[ArrLen];
	int top;	// ���ÿ� ����� ������ ����

public:
	ArrayStack() :top(0) {}
	~ArrayStack() {}

	bool isEmpty() const;
	void Push(Data data);
	Data Pop();
	Data Peek() const;
};

#endif