// int형 단순 연결 리스트(Singly LinkedList) 확인
// "LinkedList1.h, cpp" -- head 데이터 추가 방식
// "LinkedList2.h, cpp" -- tail 데이터 추가 방식
// 실행하려는 두 방식 중 하나의 코드를 컴파일에서 제외시키고 실행
#include <iostream>
//#include "LinkedList1.h"
#include "LinkedList2.h"

// 정렬 기준 함수
int SortOrder(int d1, int d2) {
	if (d1 < d2)
		return 0;	// d1이 정렬 순서가 앞이다
	else
		return 1;	// d2가 정렬 순서가 앞이다
}

int main() {
	LinkedList list;
	int data;

	// 리스트 정렬 기준 설정 -- 설정 안하면 NULL
	list.SetSortRule(SortOrder);

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