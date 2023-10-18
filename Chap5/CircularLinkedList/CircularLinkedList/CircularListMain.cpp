// int형 원형 연결 리스트(Singly LinkedList) 확인
#include <iostream>
#include "CircularLinkedList.h"

int main() {
	CircularList list;
	int data;

	// 리스트 삽입
	list.LInsertTail(3);
	list.LInsertTail(4);
	list.LInsertTail(5);
	list.LInsertHead(2);
	list.LInsertHead(1);

	// 리스트 연속 3회 출력
	std::cout << "현재 리스트의 데이터 수: " << list.LCount() << std::endl;
	if (list.LFirst(&data)) {
		std::cout << data << ' ';
		for (int i = 1; i < list.LCount() * 3; i++) {
			if (list.LNext(&data))
				std::cout << data << ' ';
		}
	}
	std::cout << std::endl;

	// 2의 배수 데이터 삭제
	std::cout << "2의 배수 삭제\n";
	if (list.LFirst(&data)) {
		if (data % 2 == 0)
			list.LRemove();
		for (int i = 1; i < list.LCount(); i++) {
			list.LNext(&data);
			if (data % 2 == 0)
				list.LRemove();
		}
	}

	// 리스트 1회 출력
	std::cout << "현재 리스트의 데이터 수: " << list.LCount() << std::endl;
	if (list.LFirst(&data)) {
		std::cout << data << ' ';
		for (int i = 1; i < list.LCount(); i++) {
			if (list.LNext(&data))
				std::cout << data << ' ';
		}
	}
	std::cout << std::endl;

	return 0;
}