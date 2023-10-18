// int형 연결 리스트(LinkedList) 기반 스택 확인
#include "ListStack.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	ListStack stack;
	int data;

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);

	// 스택 데이터 추출
	while (!stack.isEmpty()) {
		data = stack.Pop();
		cout << data << ' ';
	}
	cout << endl;

	return 0;
}