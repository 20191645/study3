// int형 순차 리스트(ArrayList) 검사
// "ArrayList.h, cpp"와 함께 컴파일
#include <iostream>
#include "ArrayList.h"

int main() {
	// 1. 리스트 생성 및 초기화
	ArrayList list;
	int data;

	// 2. 리스트 데이터 삽입
	for (int i = 1; i < 10; i++)
		list.insert(i);

	// 3. 리스트 데이터의 합 계산
	int sum = 0;
	if (list.first(&data)) {
		sum += data;
		while (list.next(&data))
			sum += data;
	}
	std::cout << "List에 담긴 데이터의 합: " << sum << std::endl << std::endl;

	// 4. 리스트 데이터 순서대로 출력
	std::cout << "List에 담긴 데이터의 수: " << list.count() << std::endl;
	std::cout << "List에 담긴 데이터: ";
	if (list.first(&data)) {
		std::cout << data << ' ';
		while (list.next(&data))
			std::cout << data << ' ';
	}
	std::cout << std::endl << std::endl;

	// +. 리스트 특정 데이터 삭제 후 다시 출력
	std::cout << "---List에 있는 3을 삭제---\n";
	if (list.first(&data)) {
		if (data == 3)
			list.remove();

		while (list.next(&data)) {
			if (data == 3)
				list.remove();
		}
	}
	std::cout << "List에 담긴 데이터의 수: " << list.count() << std::endl;
	std::cout << "List에 담긴 데이터: ";
	if (list.first(&data)) {
		std::cout << data << ' ';
		while (list.next(&data))
			std::cout << data << ' ';
	}

	return 0;
}