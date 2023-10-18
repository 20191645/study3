// Chap5에서 이미 구현했던 원형 연결 리스트를 활용하여 스택 구현
#include "CircularLinkedList.h"
#include "CircularStack.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	CircularStack stack;
	int data;

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);

	while (!stack.isEmpty()) {
		data = stack.Pop();
		cout << data << ' ';
	}
	cout << endl;

	return 0;
}