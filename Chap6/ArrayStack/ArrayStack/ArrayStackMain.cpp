// int형 배열 기반 스택 확인
#include "ArrayStack.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	ArrayStack stack;
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