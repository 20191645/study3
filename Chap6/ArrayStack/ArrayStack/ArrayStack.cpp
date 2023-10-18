// �迭 ��� ���� ����
#include "ArrayStack.h"
#include <iostream>
#include <cstdlib>

// ������ ����ִ��� Ȯ��
bool ArrayStack::isEmpty() const {
	return top == 0;
}

// ���ÿ� ������ ����
void ArrayStack::Push(Data data) {
	if (top < ArrLen)
		arr[top++] = data;
}

// ������ ��� ���� �� ��ȯ -- �����Ͱ� �ϳ� �̻��� �� ȣ��
Data ArrayStack::Pop() {
	if (isEmpty()) {
		std::cout << "������ ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	Data data;
	data = arr[--top];
	
	return data;
}

// ������ ��� ��ȯ -- �����Ͱ� �ϳ� �̻��� �� ȣ��
Data ArrayStack::Peek() const {
	if (isEmpty()) {
		std::cout << "������ ����ֽ��ϴ�!\n";
		exit(EXIT_FAILURE);
	}

	return arr[top - 1];
}