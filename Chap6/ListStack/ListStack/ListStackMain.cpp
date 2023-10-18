// int�� ���� ����Ʈ(LinkedList) ��� ���� Ȯ��
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

	// ���� ������ ����
	while (!stack.isEmpty()) {
		data = stack.Pop();
		cout << data << ' ';
	}
	cout << endl;

	return 0;
}