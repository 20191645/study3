// NameCard형 순차 리스트(ArrayList) 확인
// "NameArrayList.h, cpp"와 함께 컴파일
#include <iostream>
#include "NameArrayList.h"
#include "NameCard.h"

int main() {
	ArrayList list;
	NameCard p1;
	NameCard p2("김지현", "010-1555-3222");
	NameCard p3("안유진");
	NameCard p4("김영철");
	NameCard p5("안유진", "010-5555-3333");

	// 1. 총 5명의 정보를 리스트에 저장
	list.insert(p1);
	list.insert(p2);
	list.insert(p3);
	list.insert(p4);
	list.insert(p5);

	// 2. 특정 이름을 탐색하여 정보 출력
	NameCard temp;
	if (list.first(&temp)) {
		if (!temp.NameCompare("안유진"))
			temp.ShowNameCardInfo();

		while (list.next(&temp)) {
			if (!temp.NameCompare("안유진"))
				temp.ShowNameCardInfo();
		}
	}
	std::cout << std::endl;

	// 3. 특정 이름을 탐색하여 전화번호 변경
	if (list.first(&temp)) {
		if (!temp.NameCompare("안유진"))
			temp.ChangePhoneNum("010-3333-4444");

		while (list.next(&temp)) {
			if (!temp.NameCompare("안유진"))
				temp.ChangePhoneNum("010-3333-4444");
		}
	}

	// 4. 특정 이름을 탐색하여 정보 삭제
	if (list.first(&temp)) {
		if (!temp.NameCompare("안유진"))
			list.remove();

		while (list.next(&temp)) {
			if (!temp.NameCompare("안유진"))
				list.remove();
		}
	}

	// 5. 남아있는 모든 사람의 전화번호 출력
	if (list.first(&temp)) {
		temp.ShowPhone();

		while (list.next(&temp))
			temp.ShowPhone();
	}

	return 0;
}