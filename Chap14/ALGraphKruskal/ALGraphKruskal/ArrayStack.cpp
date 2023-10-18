// 배열 기반 스택 구현
#include "ArrayStack.h"
#include <iostream>
#include <cstdlib>

// 스택이 비어있는지 확인
bool ArrayStack::isEmpty() const {
	return top == 0;
}

// 스택에 데이터 저장
void ArrayStack::Push(Data data) {
	if (top < ArrLen)
		arr[top++] = data;
}

// 마지막 요소 삭제 후 반환 -- 데이터가 하나 이상일 때 호출
Data ArrayStack::Pop() {
	if (isEmpty()) {
		std::cout << "스택이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	Data data;
	data = arr[--top];
	
	return data;
}

// 마지막 요소 반환 -- 데이터가 하나 이상일 때 호출
Data ArrayStack::Peek() const {
	if (isEmpty()) {
		std::cout << "스택이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	return arr[top - 1];
}