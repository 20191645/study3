// int형 양방향 연결 리스트(DoublyLinkedList) 확인 -- tail 데이터 추가 방식
#include <iostream>
#include "DoublyLinkedList.h"

int main() {
	using std::cout;
	using std::endl;

	DoublyList list;
	int data;

	// 리스트 삽입
	list.LInsert(15);
	list.LInsert(11);
	list.LInsert(22);
	list.LInsert(10);
	list.LInsert(22);
	list.LInsert(33);

	// 리스트 출력
	std::cout << "현재 리스트의 데이터 수: " << list.LCount() << std::endl;
	if (list.LFirst(&data)) {
		std::cout << data << ' ';
		while (list.LNext(&data))
			std::cout << data << ' ';
	}
	std::cout << std::endl;

	// 특정 데이터 삭제
	std::cout << "숫자 22 삭제\n";
	if (list.LFirst(&data)) {
		if (data == 22)
			list.LRemove();
		while (list.LNext(&data)) {
			if (data == 22)
				list.LRemove();
		}
	}

	// 리스트 출력
	std::cout << "현재 리스트의 데이터 수: " << list.LCount() << std::endl;
	if (list.LFirst(&data)) {
		std::cout << data << ' ';
		while (list.LNext(&data))
			std::cout << data << ' ';
	}

	return 0;
}